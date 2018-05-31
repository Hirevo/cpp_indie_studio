/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** AMovable
*/

#include "AMovable.hpp"

Eo::AMovable::AMovable(Eo::vec3 pos) : _pos(pos), _hasPositionChanged(true)
{
}

Eo::AMovable::~AMovable() = default;

Eo::vec3 Eo::AMovable::getPosition() const
{
	return _pos;
}

void Eo::AMovable::setPosition(const Eo::vec3 &pos)
{
	if (_pos != pos) {
		_pos = pos;
		_hasPositionChanged = true;
	}
}

void Eo::AMovable::setPosition(float x, float y, float z)
{
	Eo::AMovable::setPosition(Eo::vec3(x, y, z));
}

void Eo::AMovable::setPosition(float v)
{
	Eo::AMovable::setPosition(Eo::vec3(v, v, v));
}

void Eo::AMovable::translate(const Eo::vec3 &v)
{
	if (v.X != 0 || v.Y != 0 || v.Z != 0) {
		_pos += v;
		_hasPositionChanged = true;
	}
}

void Eo::AMovable::translate(float v)
{
	Eo::AMovable::translate(Eo::vec3(v, v, v));
}

void Eo::AMovable::translate(float x, float y, float z)
{
	Eo::AMovable::translate(Eo::vec3(x, y, z));
}

void Eo::AMovable::translateX(float x)
{
	Eo::AMovable::translate(Eo::vec3(x, 0, 0));
}

void Eo::AMovable::translateY(float y)
{
	Eo::AMovable::translate(Eo::vec3(0, y, 0));
}

void Eo::AMovable::translateZ(float z)
{
	Eo::AMovable::translate(Eo::vec3(0, 0, z));
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
