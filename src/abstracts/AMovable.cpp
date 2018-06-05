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

void Eo::AMovable::setPosition(Eo::f32 x, Eo::f32 y, Eo::f32 z)
{
	Eo::AMovable::setPosition(Eo::vec3(x, y, z));
}

void Eo::AMovable::setPosition(Eo::f32 v)
{
	Eo::AMovable::setPosition(Eo::vec3(v, v, v));
}

void Eo::AMovable::translate(const Eo::vec3 &v)
{
	if (v.X || v.Y || v.Z) {
		_pos += v;
		_hasPositionChanged = true;
	}
}

void Eo::AMovable::translate(Eo::f32 v)
{
	if (v) {
		_pos.X += v;
		_pos.Y += v;
		_pos.Z += v;
		_hasPositionChanged = true;
	}
}

void Eo::AMovable::translate(Eo::f32 x, Eo::f32 y, Eo::f32 z)
{
	if (x || y || z) {
		_pos.X += x;
		_pos.Y += y;
		_pos.Z += z;
		_hasPositionChanged = true;
	}
}

void Eo::AMovable::translateX(Eo::f32 x)
{
	if (x) {
		_pos.X += x;
		_hasPositionChanged = true;
	}
}

void Eo::AMovable::translateY(Eo::f32 y)
{
	if (y) {
		_pos.Y += y;
		_hasPositionChanged = true;
	}
}

void Eo::AMovable::translateZ(Eo::f32 z)
{
	if (z) {
		_pos.Z += z;
		_hasPositionChanged = true;
	}
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
