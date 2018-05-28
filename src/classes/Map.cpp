/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Map
*/

#include "Map.hpp"

Eo::Map::Map(size_t w, size_t h) : _w(w), _h(h)
{
	_map.reserve(w * h);
	for (size_t i = 0; i < w; i++)
		for (size_t j = 0; j < w; j++)
			_map.push_back(0);
}

Eo::IObject *Eo::Map::getObject(size_t x, size_t y)
{
	return _map.at(x + y * _w);
}

Eo::IObject *Eo::Map::putObject(Eo::IObject *object, size_t x, size_t y)
{
	_map.at(x + y * _w) = object;
	return object;
}

std::vector<Eo::IObject *> &Eo::Map::getObjects()
{
	return _map;
}
