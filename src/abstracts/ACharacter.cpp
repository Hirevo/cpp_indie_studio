/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** ACharacter
*/

#include "ACharacter.hpp"
#include <irrlicht.h>
#include <iostream>

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

bool Eo::ACharacter::isValidMove(Eo::Rc<Eo::Map> map, Eo::vec3 myPos,
	Eo::vec3 newDir)
{
	auto posX = roundf(myPos.X + newDir.X) + map->getWidth() / 2;
	auto posY = roundf(myPos.Z + newDir.Z) + map->getHeight() / 2;
	Eo::vec2 newPos(posX, posY);

	auto newObject = map->getObject(newPos.X, newPos.Y);
	auto currObj = map->getObject(roundf(myPos.X) + map->getWidth() / 2,
		roundf(myPos.Z) + map->getHeight() / 2);
	if (!newObject)
		return true;
	Eo::IObject::Type currObjType = Eo::IObject::Type::NONE;
	if (currObj)
		currObjType = currObj->getType();
	return ((newObject->getType() != IObject::WALL &&
		newObject->getType() != IObject::DEST_WALL &&
		newObject->getType() != IObject::BOMB) ||
		(currObjType == IObject::BOMB &&
			newObject->getType() != IObject::WALL &&
			newObject->getType() != IObject::DEST_WALL));
}

bool Eo::ACharacter::isWallPass() const
{
	return _wallPass;
}

void Eo::ACharacter::setWallPass(bool _wallPass)
{
	ACharacter::_wallPass = _wallPass;
}

