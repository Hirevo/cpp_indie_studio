/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include <iostream>
#include "Player.hpp"

Eo::Player::Player(Eo::Game &game, Eo::Event &event, Eo::Options &options, const vec3 &pos, Eo::u64 id) :
	AModel(Eo::IObject::Type::CHARACTER, pos),
	_event(event),
	_options(options),
	_playerId(id)
{
	std::cout << "helo: " << _playerId << std::endl;
	this->loadModel(&game, "../assets/Bomberman/character.blend.x",
		"../assets/Bomberman/bomberboy_colors_white.png");
	this->animate(Eo::animType::EMAT_RUN);
	this->getAnimatedNode()->setScale(Eo::vec3(0.15));
	this->addEvents(game);
}

void Eo::Player::addEvents(Eo::Game &game)
{
	_event.addKeyHandler(_options.getPlayerKeys().at(_playerId)._up,
		[this, &game](bool &toRemove, const Eo::event &ev) {
			if (!ev.KeyInput.PressedDown)
				return;
			this->translateZ(0.2);
			this->updateInScene(&game);
		});
	_event.addKeyHandler(_options.getPlayerKeys().at(_playerId)._down,
		[this, &game](bool &toRemove, const Eo::event &ev) {
			if (!ev.KeyInput.PressedDown)
				return;
			this->translateZ(-0.2);
			this->updateInScene(&game);
		});
	_event.addKeyHandler(_options.getPlayerKeys().at(_playerId)._right,
		[this, &game](bool &toRemove, const Eo::event &ev) {
			if (!ev.KeyInput.PressedDown)
				return;
			this->translateX(0.2);
			this->updateInScene(&game);
		});
	_event.addKeyHandler(_options.getPlayerKeys().at(_playerId)._left,
		[this, &game](bool &toRemove, const Eo::event &ev) {
			if (!ev.KeyInput.PressedDown)
				return;
			this->translateX(-0.2);
			this->updateInScene(&game);
		});
}

Eo::Player::~Player() = default;
