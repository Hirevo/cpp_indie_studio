/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** AMovable
*/

#include "AMovable.hpp"

Eo::AMovable::AMovable(irr::core::vector3df pos)
	: _pos(pos), _hasPositionChanged(true)
{
}

irr::core::vector3df Eo::AMovable::getPosition() const
{
	return _pos;
}

void Eo::AMovable::setPosition(const irr::core::vector3df &pos)
{
	if (_pos != pos) {
		_pos = pos;
		_hasPositionChanged = true;
	}
}

void Eo::AMovable::setPosition(float x, float y, float z)
{
	Eo::AMovable::setPosition(irr::core::vector3df(x, y, z));
}

void Eo::AMovable::setPosition(float v)
{
	Eo::AMovable::setPosition(irr::core::vector3df(v, v, v));
}

void Eo::AMovable::translate(const irr::core::vector3df &v)
{
	if (v.X != 0 || v.Y != 0 || v.Z != 0) {
		_pos += v;
		_hasPositionChanged = true;
	}
}

void Eo::AMovable::translate(float v)
{
	Eo::AMovable::translate(irr::core::vector3df(v, v, v));
}

void Eo::AMovable::translate(float x, float y, float z)
{
	Eo::AMovable::translate(irr::core::vector3df(x, y, z));
}

void Eo::AMovable::translateX(float x)
{
	Eo::AMovable::translate(irr::core::vector3df(x, 0, 0));
}

void Eo::AMovable::translateY(float y)
{
	Eo::AMovable::translate(irr::core::vector3df(0, y, 0));
}

void Eo::AMovable::translateZ(float z)
{
	Eo::AMovable::translate(irr::core::vector3df(0, 0, z));
}

bool Eo::AMovable::hasPositionChanged() const
{
	return _hasPositionChanged;
}

void Eo::AMovable::setPositionChanged(bool changed)
{
	_hasPositionChanged = changed;
}

void Eo::AMovable::resetPositionChanged()
{
	Eo::AMovable::setPositionChanged(false);
}
