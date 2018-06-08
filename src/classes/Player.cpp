/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Player.hpp"
#include <iostream>

const Eo::Player::Directions Eo::Player::_dirs = {{North, 180.0f},
	{South, 0.0f}, {East, 270.0f}, {West, 90.0f}, {NorthWest, 135.0f},
	{NorthEast, 225.0f}, {SouthWest, 45.0f}, {SouthEast, 315.0f}};

Eo::Player::Player(Eo::IScene &game, Eo::Event &event, Eo::Options &options,
	const vec3 &pos, Eo::u64 id
)
	: AModel(Eo::IObject::Type::CHARACTER, pos),
	  _flags(0),
	  _event(event),
	  _options(options),
	  _playerId(id)
{
	this->loadModel(&game, "../assets/Bomberman/Character.x",
		"../assets/Bomberman/bomberboy_colors_white.png") ;
	//todo Comment because EMAT_RUN doean't exist
	//this->animate(Eo::animType::EMAT_RUN);
	this->getAnimatedNode()->setScale(_scale);
	this->getAnimatedNode()->setAnimationSpeed(2000.f);
	this->addEvents(game);
}

Eo::Player::~Player() = default;

void Eo::Player::addEvents(Eo::IScene &game)
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
