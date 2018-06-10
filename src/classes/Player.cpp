/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Player.hpp"
#include "Game.hpp"
#include <iostream>

const Eo::Player::Directions Eo::Player::_dirs = {{North,     180.0f},
						  {South,     0.0f},
						  {East,      270.0f},
						  {West,      90.0f},
						  {NorthWest, 135.0f},
						  {NorthEast, 225.0f},
						  {SouthWest, 45.0f},
						  {SouthEast, 315.0f}};

Eo::Player::Player(Eo::Rc<Eo::IScene> game, Eo::Rc<Eo::Event> event,
	Eo::Rc<Eo::Options> options, Eo::Rc<Eo::SoundDevice> sound,
	const vec3 &pos, Eo::u64 id, bool isDead)
	: AModel(Eo::IObject::Type::CHARACTER, pos), ACharacter(id),
	_event(event), _options(options), _sound(sound)
{
	this->_dead = isDead;
	std::stringstream path;
	path << (currPath + "assets/img/bomberboy_");
	path << id + 1;
	path << ".png";
	_path = path.str();
	this->addEvents(game);
}

Eo::Player::~Player() = default;

void Eo::Player::draw(Eo::Rc<Eo::IScene> game)
{
	if (isDead())
		return;
	this->loadModel(game, currPath + "assets/Bomberman/Character.x",
		_path.c_str());
	this->getAnimatedNode()->setScale(_scale);
}

void Eo::Player::addEvents(Eo::Rc<Eo::IScene> game)
{
}

void Eo::Player::move(Eo::Rc<Eo::Game> scene)
{
	auto flags = Eo::Player::getFlag();
	auto newDir = Eo::vec3(0);
	auto fwd = ((flags & Eo::Player::Motion::Forward) != 0);
	auto bwd = ((flags & Eo::Player::Motion::Backward) != 0);
	auto rgt = ((flags & Eo::Player::Motion::Right) != 0);
	auto lft = ((flags & Eo::Player::Motion::Left) != 0);
	newDir.Z += (fwd ? Eo::ACharacter::getSpeed() : 0);
	newDir.Z += (bwd ? -Eo::ACharacter::getSpeed() : 0);
	newDir.X += (rgt ? Eo::ACharacter::getSpeed() : 0);
	newDir.X += (lft ? -Eo::ACharacter::getSpeed() : 0);
	if (newDir.X || newDir.Y || newDir.Z)
		this->getAnimatedNode()->setAnimationSpeed(42.f);
	else {
		this->getAnimatedNode()->setAnimationSpeed(0.00001f);
		this->getAnimatedNode()->setCurrentFrame(16);
	}
	if (isValidMove(scene->getMap(), Eo::Player::getPosition(), newDir) &&
		isValidMove(scene->getMap(), Eo::Player::getPosition(),
			Eo::vec3(newDir.X, 0, 0)) &&
		isValidMove(scene->getMap(), Eo::Player::getPosition(),
			Eo::vec3(0, 0, newDir.Z))) {
		try {
			Eo::Player::setRotation(Eo::Player::_dirs.at(
				static_cast<Eo::Player::Facing>(flags)));
		}
		catch (std::exception &exception) {
			static_cast<void>(exception);
		}
		Eo::Player::translate(newDir);
		Eo::Player::updateInScene();
	}
}

void Eo::Player::die()
{
	if (!this->_dead) {
		this->_dead = true;
		this->removeFromScene();
		this->_sound->play(Eo::SoundDevice::SoundPath::DEATH);
	}
}

bool Eo::Player::isDead()
{
	return this->_dead;
}
