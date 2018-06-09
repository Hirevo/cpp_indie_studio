/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** ACharacter
*/

#include "ACharacter.hpp"
#include <irrlicht.h>

Eo::ACharacter::ACharacter(Eo::u32 playerID)
	: _playerID(playerID)
{
}

Eo::ACharacter::~ACharacter() = default;


Eo::u32 Eo::ACharacter::getMaxBombs() const
{
	return _maxBombs;
}

void Eo::ACharacter::setMaxBombs(Eo::u32 bombs)
{
	_maxBombs = bombs;
}

Eo::u32 Eo::ACharacter::getAvailableBombs() const
{
	return _availableBombs;
}

void Eo::ACharacter::setAvailableBombs(Eo::u32 bombs)
{
	_availableBombs = bombs;
}

Eo::u32 Eo::ACharacter::getBombRadius() const
{
	return _bombRadius;
}

void Eo::ACharacter::setBombRadius(Eo::u32 radius)
{
	_bombRadius = radius;
}

Eo::f32 Eo::ACharacter::getSpeed() const
{
	return _speed;
}

void Eo::ACharacter::setSpeed(Eo::f32 speed)
{
	_speed = speed;
}


void Eo::ACharacter::setFlag(Eo::u8 flags)
{
	_flags |= flags;
}

void Eo::ACharacter::unsetFlag(Eo::u8 flags)
{
	_flags &= ~flags;
}

Eo::u8 Eo::ACharacter::getFlag() const
{
	return _flags;
}

Eo::u64 Eo::ACharacter::getPlayerID() const
{
	return _playerID;
}

bool Eo::ACharacter::isValidMove(Eo::Rc<Eo::Map> map, Eo::vec3 newPos)
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

