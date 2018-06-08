/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Game.hpp"
#include "Bomb.hpp"
#include "Floor.hpp"
#include "Player.hpp"
#include <iostream>

Eo::Game::Game(Eo::Rc<Eo::Event> event, Eo::Rc<Eo::Device> device,
	const std::string &mapPath, Eo::Rc<Eo::Options> options)
	: AScene(event, device), _json(mapPath),
	  _map(Eo::initRc<Eo::Map>(_json)), _camera(), _options(options)
{
}

Eo::Game::~Game()
{
}

irr::scene::ICameraSceneNode *Eo::Game::getCamera() const
{
	return _camera.getCameraHandle();
}

bool Eo::Game::draw()
{
	auto ref = Eo::Rc<Eo::IScene>(this, [](Eo::IScene *ptr) {});
	Eo::vec2i v(_map->getWidth(), _map->getHeight());
	Eo::i32 medX = (v.X % 2 == 0) ? (v.X / 2 - 2) : (v.X / 2 - 1);
	Eo::i32 medY = (v.Y % 2 == 0) ? (v.Y / 2 - 2) : (v.Y / 2 - 1);
	Eo::i32 playerX[] = {-medX, medX};
	Eo::i32 playerY[] = {-medY, medY};
	Eo::i32 computerX[] = {-medX, medX, medX};
	Eo::i32 computerY[] = {medY, -medY, medY};
	_players.fill(Eo::Rc<Eo::Player>(nullptr));
	_computers.fill(Eo::Rc<Eo::Computer>(nullptr));
	for (Eo::u32 i = 0; i < _options->getNbPlayer(); i++)
		_players.at(i) = Eo::initRc<Eo::Player>(ref, _event,
			_options, vec3(playerX[i], -0.5f, playerY[i]), i);
	for (Eo::u32 i = 0; i < (4 - _options->getNbPlayer()); i++)
		_computers.at(i) = Eo::initRc<Eo::Computer>(
			ref, vec3(computerX[i], 0, computerY[i]));
	_camera.insertStaticInScene(ref);
	_floor = Eo::initRc<Eo::Floor>((v.X - 1), Eo::vec3(0, -0.5f, 0));
	_floor->insertInScene(ref);
	Eo::Game::insertMap(v);
	Eo::Game::addEvents();
	return true;
}

void Eo::Game::insertMap(Eo::vec2i v)
{
	for (Eo::f32 i = 0; i < v.Y; i++)
		for (Eo::f32 j = 0; j < v.X; j++)
			Eo::Game::placeObject(v, Eo::vec2i(j, i));
}

void Eo::Game::placeObject(Eo::vec2i size, Eo::vec2i cur)
{
	auto obj = _map->getObject(cur.X, cur.Y);
	if (obj) {
		obj->setPosition(
			(cur.X - size.X / 2), 0, (cur.Y - size.Y / 2));
		obj->insertInScene(
			Eo::Rc<Eo::IScene>(this, [](Eo::IScene *ptr) {}));
		obj->getSceneNode()->setMaterialFlag(
			irr::video::EMF_LIGHTING, false);
	}
}

Eo::keyHandler Eo::Game::getPlayerEventFunc(
	Eo::Rc<Eo::Player> &player, Eo::Player::Motion flag)
{
	return [this, player, flag](bool &toRemove, const Eo::event &ev) {
		auto state = ev.KeyInput.PressedDown;
		auto func = (state ? &Eo::Player::setFlag :
				     &Eo::Player::unsetFlag);
		((player.get())->*func)(flag);
	};
}

void Eo::Game::addPlayerEvents(Eo::Rc<Eo::Player> &player)
{
	auto id = _options->getPlayerKeys().at(player->getPlayerId());
	auto ref = Eo::Rc<Eo::Game>(this, [](Eo::Game *ptr) {});

	_event->addKeyHandler(id._up,
		Eo::Game::getPlayerEventFunc(
			player, Eo::Player::Motion::Forward));
	_event->addKeyHandler(id._left,
		Eo::Game::getPlayerEventFunc(
			player, Eo::Player::Motion::Left));
	_event->addKeyHandler(id._down,
		Eo::Game::getPlayerEventFunc(
			player, Eo::Player::Motion::Backward));
	_event->addKeyHandler(id._right,
		Eo::Game::getPlayerEventFunc(
			player, Eo::Player::Motion::Right));
	_event->addKeyHandler(
		id._bomb, [this, ref, player](bool &toRemove, const Eo::event &ev) {
			if (ev.KeyInput.PressedDown) {
				// toRemove = true;
				auto oPos = player->getPosition();
				Eo::vec3 nPos(std::roundf(oPos.X),
					std::roundf(oPos.Y) + 0.1,
					std::roundf(oPos.Z));
				Eo::vec2i size(_map->getWidth() / 2.0f,
					_map->getHeight() / 2.0f);
				Eo::vec2i inMap(
					nPos.X + size.X, nPos.Z + size.Y);
				this->getMap()->putObject(Eo::initRc<Eo::Bomb>(
					ref, inMap, nPos), inMap.X, inMap.Y);
			}
		});
}

void Eo::Game::addEvents()
{
	std::for_each(_players.begin(), _players.end(),
		[this](Eo::Rc<Eo::Player> &player) {
			if (player.get() != nullptr)
				Eo::Game::addPlayerEvents(player);
		});
	_event->addKeyHandler(_options->getKeyExit(),
		[this](bool &toRemove, const Eo::event &ev) {
			if (!ev.KeyInput.PressedDown)
				return;
			_options->setExit(true);
		});
}

void Eo::Game::update()
{
	_map->update();
	std::for_each(_players.begin(), _players.end(),
		[this](Eo::Rc<Eo::Player> &player) {
			if (player.get() == nullptr)
				return;
			player->move(Eo::Rc<Eo::Game>(this, [](Eo::Game *_) {}));
			Eo::Booster::BoosterType type = CollectibleMove(
				player->getPosition(), player->getPlayerId());
			if (type != Booster::NONE) {
				if (type == Booster::SPEED)
					std::cout << "It's speed" << std::endl;
				if (type == Booster::SUPERBOMB)
					std::cout << "It's SuperBomb"
						  << std::endl;
				if (type == Booster::NBBOMB)
					std::cout << "It's NBBomb"
						  << std::endl;
			}
		});
}

Eo::Rc<Eo::Map> Eo::Game::getMap()
{
	return _map;
}

Eo::Booster::BoosterType Eo::Game::CollectibleMove(Eo::vec3 Pos, irr::u64 id)
{
	auto posX = roundf(Pos.X) + _map->getWidth() / 2;
	auto posY = roundf(Pos.Z) + _map->getHeight() / 2;
	Eo::vec2 pos(posX, posY);
	auto object = _map->getObject(pos.X, pos.Y);
	if (!object) {
		return Booster::NONE;
	}
	auto type = static_cast<Booster::BoosterType>(object->getType());
	if (type != Booster::SPEED && type != Booster::NBBOMB &&
		type != Booster::SUPERBOMB)
		return Booster::NONE;
	return type;
}
