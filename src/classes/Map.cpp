/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Map
*/

#include <Wall.hpp>
#include "Map.hpp"
#include "JsonRead.hpp"

Eo::Map::Map(size_t w, size_t h)
	: _w(w),
	  _h(h)
{
	_map.reserve(w * h);
	for (size_t i = 0; i < w; i++)
		for (size_t j = 0; j < w; j++)
			_map.emplace_back(0);
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

void Eo::Map::generateMap(const std::string &mapPath)
{
	auto json = Eo::JsonRead(mapPath);
	size_t width = json.readMatrix("map").size();
	size_t height = json.readMatrix("map").at(0).size();

	for (size_t l = 0; l < height; ++l) {
		putObject(new Wall(Eo::Wall::INDESTRUCTIBLE), 0, l);
		putObject(new Wall(Eo::Wall::INDESTRUCTIBLE), height, l);
	}
	for (size_t l = 1; l < width - 1; ++l) {
		putObject(new Wall(Eo::Wall::INDESTRUCTIBLE), 0, 1);
		putObject(new Wall(Eo::Wall::INDESTRUCTIBLE), l, height - 1);
	}
}
