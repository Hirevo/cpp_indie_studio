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
#include "SoundDevice.hpp"
#include "SceneHandler.hpp"
#include "menu/GameMenu.hpp"
#include "JsonRead.hpp"
#include <iostream>
#include <menu/SettingsMenu.hpp>
#include <cstring>

const float Eo::Game::_maxSpeed = 0.2f;
const float Eo::Game::_speedBonus = 0.02f;

Eo::Game::Game(Eo::Rc<Eo::Event> event, Eo::Rc<Eo::Device> device,
	const std::string &mapPath, Eo::Rc<Eo::Options> options,
	Eo::Rc<Eo::SceneHandler> sceneHandler, Eo::Rc<Eo::SoundDevice> sound)
	: AScene(event, device, sceneHandler, sound), _json(mapPath),
	  _map(Eo::initRc<Eo::Map>(_json)), _camera(_map->getWidth()),
	_options(options), _deathOrder()
{
	_sound->stopMusic();
	_sound->play(Eo::SoundDevice::GAMEBGM, true);
	_sound->play(Eo::SoundDevice::PLAY);
	Eo::vec2i v(_map->getWidth(), _map->getHeight());
	auto ref = Eo::Rc<Eo::IScene>(this, [](Eo::IScene *ptr) {});
	_playersPos = _json.readPlayersPos("player_pos");
	_sceneHandler = sceneHandler;
	_players.fill(Eo::Rc<Eo::Player>(nullptr));
	_computers.fill(Eo::Rc<Eo::Computer>(nullptr));
	for (Eo::u32 i = 0; i < _options->getNbPlayer(); i++)
		_players.at(i) = Eo::initRc<Eo::Player>(ref, _event, _options,
			_sound,
			vec3(getPlayerPos(i).X, -0.5f, getPlayerPos(i).Y), i,
			getPlayerPos(i).Z == 1);
	for (Eo::u32 i = 3; i >= _options->getNbPlayer(); i--)
		_computers.at(i - 1) = Eo::initRc<Eo::Computer>(_sound,
			ref, vec3(getPlayerPos(i).X, 0, getPlayerPos(i).Y), i,
			getPlayerPos(i).Z == 1);
	_floor = Eo::initRc<Eo::Floor>((v.X - 1), Eo::vec3(0.0f, -0.5f, 0.0f));
	Eo::Game::addEvents();
}

Eo::Game::~Game()
{
	auto p1 = _options->getPlayerKeys().at(0);
	auto p2 = _options->getPlayerKeys().at(1);

	_event->clearKeyHandlers(p1._up);
	_event->clearKeyHandlers(p2._up);
	_event->clearKeyHandlers(p1._down);
	_event->clearKeyHandlers(p2._down);
	_event->clearKeyHandlers(p1._left);
	_event->clearKeyHandlers(p2._left);
	_event->clearKeyHandlers(p1._right);
	_event->clearKeyHandlers(p2._right);
	_event->clearKeyHandlers(p1._bomb);
	_event->clearKeyHandlers(p2._bomb);
	_event->clearKeyHandlers(Eo::keyCode::KEY_ESCAPE);
	_event->clearKeyHandlers(_options->getKeyExit());
}

bool Eo::Game::clear()
{
	_sceneManager->clear();
	_device->getDevice()->getGUIEnvironment()->clear();
	std::for_each(_players.begin(), _players.end(),
		[](Eo::Rc<Eo::Player> &player) {
			if (player.get()) {
				player->setHasNode(false);
				player->setPlacedInScene(false);
				player->setHasMesh(false);
			}
		});
	std::for_each(_computers.begin(), _computers.end(),
		[](Eo::Rc<Eo::Computer> &player) {
			if (player.get()) {
				player->setHasNode(false);
				player->setPlacedInScene(false);
				player->setHasMesh(false);
			}
		});
	auto map = _map->getObjects();
	std::for_each(map.begin(), map.end(), [](Eo::Rc<Eo::IObject> obj) {
		if (obj.get()) {
			obj->setHasNode(false);
			obj->setPlacedInScene(false);
		}
	});
	return true;
}

irr::scene::ICameraSceneNode *Eo::Game::getCamera() const
{
	return _camera.getCameraHandle();
}

bool Eo::Game::draw()
{
	_device->getDevice()->getSceneManager()->addSkyDomeSceneNode(
		_device->getDriver()->getTexture((currPath + "../assets/img/background.jpg").c_str()), 16, 8, 2, 5, 800);
	Eo::vec2i v(_map->getWidth(), _map->getHeight());
	auto ref = Eo::Rc<Eo::IScene>(this, [](Eo::IScene *ptr) {});
	_camera.insertStaticInScene(ref);
	_floor->insertInScene(ref);
	Eo::Game::insertMap(v);
	std::for_each(_players.begin(), _players.end(),
		[&ref](Eo::Rc<Eo::Player> &player) {
			if (player.get())
				player->draw(ref);
		});
	std::for_each(_computers.begin(), _computers.end(),
		[&ref](Eo::Rc<Eo::Computer> &player) {
			if (player.get())
				player->draw(ref);
		});
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
	Eo::Rc<Eo::ICharacter> &player, Eo::Player::Motion flag)
{
	#pragma warning(disable : 4834)
	return [this, player, flag](bool &toRemove, const Eo::event &ev) {
		auto state = ev.KeyInput.PressedDown;
		auto func = (state ? &Eo::ICharacter::setFlag :
				     &Eo::ICharacter::unsetFlag);
		((player.get())->*func)(flag);
	};
}

void Eo::Game::addPlayerEvents(Eo::Rc<Eo::ICharacter> player)
{
	auto id = _options->getPlayerKeys().at(player->getPlayerID());

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
			if (player->isDead())
				return;
			auto bombs = player->getAvailableBombs();
			if (!ev.KeyInput.PressedDown || bombs == 0)
				return;
			auto pos = player->getPosition();
			auto posX = std::roundf(pos.X) + _map->getWidth() / 2;
			auto posY = std::roundf(pos.Z) + _map->getHeight() / 2;
			auto obj = _map->getObject(posX, posY);
			if (obj == nullptr)
				Eo::Game::placeBomb(player, bombs);
		});
}

void Eo::Game::placeBomb(Eo::Rc<Eo::ICharacter> player, Eo::u32 bombs)
{
	player->setAvailableBombs(bombs - 1);
	auto ref = Eo::Rc<Eo::Game>(this, [](Eo::Game *ptr) {});
	auto oPos = player->getPosition();
	Eo::vec3 nPos(std::roundf(oPos.X), std::roundf(oPos.Y) + 1,
		std::roundf(oPos.Z));
	Eo::vec2i size(_map->getWidth() / 2.0f, _map->getHeight() / 2.0f);
	Eo::vec2i inMap(nPos.X + size.X, nPos.Z + size.Y);
	this->getMap()->putObject(
		Eo::initRc<Eo::Bomb>(ref, player, inMap, nPos, _sound),
		inMap.X, inMap.Y);
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
				Eo::initRc<Eo::GameMenu>(_event, _device,
					_sceneHandler, _sound));
		});
}

bool Eo::Game::gameOver()
{
	std::for_each(_players.begin(), _players.end(),
		[this](Eo::Rc<Eo::Player> &player) {
			if (player) {
				if (player->isDead() &&
					std::find(this->_deathOrder.begin(),
					this->_deathOrder.end(),
						player->getPlayerID()) ==
					this->_deathOrder.end())
					this->_deathOrder.push_back(
						player->getPlayerID());
			}
	});
	std::for_each(_computers.begin(), _computers.end(),
		[this](Eo::Rc<Eo::Computer> &computer) {
			if (computer) {
				if (computer->isDead() &&
					std::find(this->_deathOrder.begin(),
						this->_deathOrder.end(),
						computer->getPlayerID()) ==
						this->_deathOrder.end())
					this->_deathOrder.push_back(
						computer->getPlayerID());
			}
		});
	return _deathOrder.size() >= 3;
}

void Eo::Game::update()
{
	_map->update(Eo::Rc<Eo::IScene>(this, [](Eo::IScene *_) {}));
	std::for_each(_players.begin(), _players.end(),
		[this](Eo::Rc<Eo::Player> &player) {
			if (player.get() == nullptr || player->isDead())
				return;
			auto ref = Eo::Rc<Eo::Game>(this, [](Eo::Game *_) {});
			player->move(ref);
			Eo::IObject::Type type = CollectibleMove(
				player->getPosition(), player->getPlayerID());
			if (type != Eo::IObject::NONE)
				useCollectible(type, player);
		});
	std::for_each(_computers.begin(), _computers.end(), 
		[this](Eo::Rc<Eo::Computer> &computer) {
		if (computer.get() == nullptr || computer->isDead())
			return;
		computer->updatePosition(_map);
		if (computer->checkPoseBomb(_map)) {
			auto bombs = computer->getAvailableBombs();
			if (bombs > 0)
				placeBomb(computer, bombs);
		}
		computer->updateInScene();
	});
}

Eo::Rc<Eo::Map> Eo::Game::getMap()
{
	return _map;
}

void Eo::Game::useCollectible(Eo::IObject::Type type,
	Eo::Rc<Eo::ICharacter> player)
{
	auto pos = player->getPosition();
	auto posX = std::roundf(pos.X) + _map->getWidth() / 2;
	auto posY = std::roundf(pos.Z) + _map->getHeight() / 2;
	Eo::vec2 posf(posX, posY);
	auto object = _map->getObject(posf.X, posf.Y);
	auto boosterType = static_cast<Eo::Booster::BoosterType>(type);

	if (type == Booster::SPEED) {
		auto speed = player->getSpeed();
		player->setSpeed(speed < _maxSpeed ? speed + _speedBonus : speed);
		_sound->play(Eo::SoundDevice::GETITEM);
		_map->putObject(Eo::Rc<Eo::IObject>(nullptr), posf.X, posf.Y);
	}
	else if (type == Booster::SUPERBOMB) {
		auto sbomb = player->getBombRadius();
		player->setBombRadius(sbomb < 100 ? sbomb + 1 : sbomb);
		_sound->play(Eo::SoundDevice::GETITEM);
		_map->putObject(Eo::Rc<Eo::IObject>(nullptr), posf.X, posf.Y);
	}
	else if (type == Booster::NBBOMB) {
		auto nbomb = player->getBombRadius();
		auto abomb = player->getAvailableBombs();
		player->setBombRadius(nbomb < 100 ? nbomb + 1 : nbomb);
		player->setAvailableBombs(nbomb < 100 ? abomb + 1 : abomb);
		_sound->play(Eo::SoundDevice::GETITEM);
		_map->putObject(Eo::Rc<Eo::IObject>(nullptr), posf.X, posf.Y);
	}
	else if (type == Booster::WALLPASS) {
		player->setWallPass(true);
		_sound->play(Eo::SoundDevice::GETITEM);
		_map->putObject(Eo::Rc<Eo::IObject>(nullptr), posf.X, posf.Y);
	}
}

Eo::IObject::Type Eo::Game::CollectibleMove(Eo::vec3 Pos, irr::u64 id)
{
	Eo::u32 posX = roundf(Pos.X) + _map->getWidth() / 2;
	Eo::u32 posY = roundf(Pos.Z) + _map->getHeight() / 2;
	Eo::vec2i pos(posX, posY);
	auto object = _map->getObject(pos.X, pos.Y);
	if (!object)
		return Eo::IObject::Type::NONE;
	auto type = object->getType();
	return type;
}

const std::string &Eo::Game::getMapName() const
{
	return _mapName;
}

Eo::vec3 Eo::Game::getPlayerPos(size_t playerId)
{
	Eo::vec3 player;

	player.X = _playersPos.at(playerId).at(0) - _map->getWidth() / 2;
	player.Y = _playersPos.at(playerId).at(1) - _map->getHeight() / 2;
	player.Z = _playersPos.at(playerId).at(1);
	return player;
}
