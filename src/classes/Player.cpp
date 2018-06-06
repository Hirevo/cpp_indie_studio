/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Player.hpp"

Eo::Player::Player(Eo::IScene &game, Eo::Event &event, const vec3 &pos) :
	AModel(Eo::IObject::Type::CHARACTER, pos),
	_event(event), _flags(0)
{
	this->loadModel(&game, "../assets/Bomberman/character.blend.x",
		"../assets/Bomberman/bomberboy_colors_white.png");
	this->animate(Eo::animType::EMAT_RUN);
	this->getAnimatedNode()->setScale(Eo::vec3(0.15));
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
