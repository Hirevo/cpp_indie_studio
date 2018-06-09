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
#include "SceneHandler.hpp"
#include "menu/GameMenu.hpp"
#include "JsonRead.hpp"
#include <iostream>

Eo::Game::Game(Eo::Rc<Eo::Event> event, Eo::Rc<Eo::Device> device,
	const std::string &mapPath, Eo::Rc<Eo::Options> options,
	Eo::Rc<Eo::SceneHandler> sceneHandler)
	: AScene(event, device, sceneHandler), _json(mapPath),
	  _map(Eo::initRc<Eo::Map>(_json)), _camera(), _options(options)
{
	_playersPos = _json.readPlayersPos("player_pos");
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
	_device->getDevice()->getSceneManager()->addSkyDomeSceneNode(
		_device->getDriver()->getTexture(
			"../assets/img/background.jpg"), 16, 8, 2, 5, 800);
	auto ref = Eo::Rc<Eo::IScene>(this, [](Eo::IScene *ptr) {});
	Eo::vec2i v(_map->getWidth(), _map->getHeight());

	_players.fill(Eo::Rc<Eo::Player>(nullptr));
	_computers.fill(Eo::Rc<Eo::Computer>(nullptr));
	for (Eo::u32 i = 0; i < _options->getNbPlayer(); i++)
		_players.at(i) = Eo::initRc<Eo::Player>(ref, _event, _options,
			vec3(getPlayerPos(i).X, -0.5f, getPlayerPos(i).Y), i);
	for (Eo::u32 i = 3; i >= _options->getNbPlayer(); i--)
		_computers.at(i - 1) = Eo::initRc<Eo::Computer>(
			ref, vec3(getPlayerPos(i).X, 0, getPlayerPos(i).Y));
	_camera.insertStaticInScene(ref);
	_floor = Eo::initRc<Eo::Floor>((v.X - 1), Eo::vec3(0.0f, -0.5f, 0.0f));
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
	#pragma warning(disable : 4834)
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
	_event->addKeyHandler(id._bomb,
		[this, player](bool &toRemove, const Eo::event &ev) {
			if (ev.KeyInput.PressedDown)
				Eo::Game::placeBomb(player);
		});
}

void Eo::Game::placeBomb(Eo::Rc<Eo::Player> player)
{
	auto ref = Eo::Rc<Eo::Game>(this, [](Eo::Game *ptr) {});
	auto oPos = player->getPosition();
	Eo::vec3 nPos(std::roundf(oPos.X), std::roundf(oPos.Y) + 1,
		std::roundf(oPos.Z));
	Eo::vec2i size(_map->getWidth() / 2.0f, _map->getHeight() / 2.0f);
	Eo::vec2i inMap(nPos.X + size.X, nPos.Z + size.Y);
	this->getMap()->putObject(
		Eo::initRc<Eo::Bomb>(ref, inMap, nPos), inMap.X, inMap.Y);
}

void Eo::Game::placeBomb(Eo::Rc<Eo::Computer> computer)
{
	auto ref = Eo::Rc<Eo::Game>(this, [](Eo::Game *ptr) {});
	auto oPos = computer->getPosition();
	Eo::vec3 nPos(std::roundf(oPos.X), std::roundf(oPos.Y) + 1,
		std::roundf(oPos.Z));
	Eo::vec2i size(_map->getWidth() / 2.0f, _map->getHeight() / 2.0f);
	Eo::vec2i inMap(nPos.X + size.X, nPos.Z + size.Y);
	this->getMap()->putObject(
		Eo::initRc<Eo::Bomb>(ref, inMap, nPos), inMap.X, inMap.Y);
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
	_event->addKeyHandler(Eo::keyCode::KEY_ESCAPE,
		[this](bool &toRemove, const Eo::event &ev) {
			if (!ev.KeyInput.PressedDown)
				return;
			_sceneHandler->loadScene(
				Eo::initRc<Eo::GameMenu>(_event, _device, _sceneHandler));
		});
}

void Eo::Game::update()
{
	_map->update(Eo::Rc<Eo::IScene>(this, [](Eo::IScene *_) {}));
	std::for_each(_players.begin(), _players.end(),
		[this](Eo::Rc<Eo::Player> &player) {
			if (player.get() == nullptr)
				return;
			auto ref = Eo::Rc<Eo::Game>(this, [](Eo::Game *_) {});
			player->move(ref);
			Eo::Booster::BoosterType type = CollectibleMove(
				player->getPosition(), player->getPlayerId());
			if (type != Booster::NONE)
				useCollectible(type, player);
		});
}

Eo::Rc<Eo::Map> Eo::Game::getMap()
{
	return _map;
}

void Eo::Game::useCollectible(Booster::BoosterType type, Rc<Player> player)
{
	auto pos = player->getPosition();
	auto posX = std::roundf(pos.X) + _map->getWidth() / 2;
	auto posY = std::roundf(pos.Z) + _map->getHeight() / 2;
	Eo::vec2 posf(posX, posY);
	auto object = _map->getObject(posf.X, posf.Y);

	if (type == Booster::SPEED) {
		auto speed = player->getSpeed();
		player->setSpeed(speed < 0.1f ? speed + 0.01f : speed);
		_map->putObject(Eo::Rc<Eo::IObject>(nullptr), posf.X, posf.Y);
	}
	if (type == Booster::SUPERBOMB) {
		auto sbomb = player->getBombPower();
		player->setBombPower(sbomb < 100 ? sbomb + 1 : sbomb);
		_map->putObject(Eo::Rc<Eo::IObject>(nullptr), posf.X, posf.Y);
	}
	else if (type == Booster::NBBOMB) {
		auto nbomb = player->getBombPower();
		auto abomb = player->getBombAvailable();
		player->setBombPower(nbomb < 100 ? nbomb + 1 : nbomb);
		player->setBombAvailable(nbomb < 100 ? abomb + 1 : abomb);
		_map->putObject(Eo::Rc<Eo::IObject>(nullptr), posf.X, posf.Y);
	}
}

bool Eo::Game::isValidMove(Eo::vec3 pos)
{
	auto posX = roundf(pos.X) + _map->getWidth() / 2;
	auto posY = roundf(pos.Z) + _map->getHeight() / 2;
	Eo::vec2 posf(posX, posY);
	auto object = _map->getObject(posf.X, posf.Y);
	if (!object)
		return true;
	auto type = object->getType();
	return !(type == IObject::WALL || type == IObject::DEST_WALL);
}

Eo::Booster::BoosterType Eo::Game::CollectibleMove(Eo::vec3 Pos, irr::u64 id)
{
	Eo::u32 posX = roundf(Pos.X) + _map->getWidth() / 2;
	Eo::u32 posY = roundf(Pos.Z) + _map->getHeight() / 2;
	Eo::vec2i pos(posX, posY);
	auto object = _map->getObject(pos.X, pos.Y);
	if (!object)
		return Booster::NONE;
	auto type = static_cast<Booster::BoosterType>(object->getType());
	// if (type != Booster::SPEED && type != Booster::NBBOMB &&
	// 	type != Booster::SUPERBOMB)
	// 	return Booster::NONE;
	return type;
}

const std::string &Eo::Game::getMapName() const
{
	return _mapName;
}

Eo::vec2 Eo::Game::getPlayerPos(size_t playerId)
{
	Eo::vec2 player;

	player.X = _playersPos.at(playerId).at(0) - _map->getWidth() / 2;
	player.Y = _playersPos.at(playerId).at(1) - _map->getHeight() / 2;
	return player;
}
