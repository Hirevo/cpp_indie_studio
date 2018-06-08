/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Player.hpp"
#include "Game.hpp"
#include <iostream>

const Eo::Player::Directions Eo::Player::_dirs = {{North, 180.0f},
	{South, 0.0f}, {East, 270.0f}, {West, 90.0f}, {NorthWest, 135.0f},
	{NorthEast, 225.0f}, {SouthWest, 45.0f}, {SouthEast, 315.0f}};

Eo::Player::Player(Eo::Rc<Eo::IScene> game, Eo::Rc<Eo::Event> event,
	Eo::Rc<Eo::Options> options, const vec3 &pos, Eo::u64 id)
	: AModel(Eo::IObject::Type::CHARACTER, pos), _flags(0), _event(event),
	  _options(options), _playerId(id)
{
	this->loadModel(game, "../assets/Bomberman/Character.x",
		"../assets/Bomberman/bomberboy_colors_white.png");
	_scale = vec3(0.28f);
	this->getAnimatedNode()->setScale(_scale);
	this->getAnimatedNode()->setAnimationSpeed(2000.f);
	this->addEvents(game);
}

Eo::Player::~Player() = default;

void Eo::Player::addEvents(Eo::Rc<Eo::IScene> game)
{
	// _event.addKeyHandler(Eo::keyCode::KEY_KEY_Z,
	// 	[this, &game](bool &toRemove, const Eo::event &ev) {
	// 		if (!ev.KeyInput.PressedDown)
	// 			return;
	// 		this->translateZ(0.2);
	// 		this->updateInScene(&game);
	// 	});
	// _event.addKeyHandler(Eo::keyCode::KEY_KEY_S,
	// 	[this, &game](bool &toRemove, const Eo::event &ev) {
	// 		if (!ev.KeyInput.PressedDown)
	// 			return;
	// 		this->translateZ(-0.2);
	// 		this->updateInScene(&game);
	// 	});
	// _event.addKeyHandler(Eo::keyCode::KEY_KEY_D,
	// 	[this, &game](bool &toRemove, const Eo::event &ev) {
	// 		if (!ev.KeyInput.PressedDown)
	// 			return;
	// 		this->translateX(0.2);
	// 		this->updateInScene(&game);
	// 	});
	// _event.addKeyHandler(Eo::keyCode::KEY_KEY_Q,
	// 	[this, &game](bool &toRemove, const Eo::event &ev) {
	// 		if (!ev.KeyInput.PressedDown)
	// 			return;
	// 		this->translateX(-0.2);
	// 		this->updateInScene(&game);
	// 	});
}

void Eo::Player::setFlag(Eo::u8 flags)
{
	_flags |= flags;
}

void Eo::Player::unsetFlag(Eo::u8 flags)
{
	_flags &= ~flags;
}

Eo::u8 Eo::Player::getFlag() const
{
	return _flags;
}

irr::u64 Eo::Player::getPlayerId() const
{
	return _playerId;
}

irr::f32 Eo::Player::getSpeed() const
{
	return _speed;
}

void Eo::Player::setSpeed(irr::f32 _speed)
{
	Player::_speed = _speed;
}

void Eo::Player::move(Eo::Rc<Eo::Game> scene)
{
	auto flags = Eo::Player::getFlag();
	auto dir = Eo::vec3(0);
	auto fwd = ((flags & Eo::Player::Motion::Forward) != 0);
	auto bwd = ((flags & Eo::Player::Motion::Backward) != 0);
	auto rgt = ((flags & Eo::Player::Motion::Right) != 0);
	auto lft = ((flags & Eo::Player::Motion::Left) != 0);
	dir.Z += (fwd ? Eo::Player::getSpeed() : 0);
	dir.Z += (bwd ? -Eo::Player::getSpeed() : 0);
	dir.X += (rgt ? Eo::Player::getSpeed() : 0);
	dir.X += (lft ? -Eo::Player::getSpeed() : 0);
	if (isValidMove(scene->getMap(), Eo::Player::getPosition() + dir,
		    Eo::Player::getPlayerId())) {
		try {
			Eo::Player::setRotation(Eo::Player::_dirs.at(
				static_cast<Eo::Player::Facing>(flags)));
		}
		catch (std::exception &exception) {
			static_cast<void>(exception);
		}
		Eo::Player::translate(dir);
		Eo::Player::updateInScene();
	}
}

bool Eo::Player::isValidMove(Eo::Rc<Eo::Map> map, Eo::vec3 newPos, irr::u64 id)
{
	auto posX = roundf(newPos.X) + map->getWidth() / 2;
	auto posY = roundf(newPos.Z) + map->getHeight() / 2;
	Eo::vec2 pos(posX, posY);
	auto object = map->getObject(pos.X, pos.Y);
	if (!object)
		return true;
	auto type = object->getType();
	return !(type == IObject::WALL || type == IObject::DEST_WALL);
}

irr::u32 Eo::Player::getMaxBomb() const
{
	return _maxBomb;
}

void Eo::Player::setMaxBomb(irr::u32 _maxBomb)
{
	Player::_maxBomb = _maxBomb;
}

irr::u32 Eo::Player::getBombAvailable() const
{
	return _bombAvailable;
}

void Eo::Player::setBombAvailable(irr::u32 _bombAvailable)
{
	Player::_bombAvailable = _bombAvailable;
}

irr::u32 Eo::Player::getBombPower() const
{
	return _bombPower;
}

void Eo::Player::setBombPower(irr::u32 _bombPower)
{
	Player::_bombPower = _bombPower;
}
