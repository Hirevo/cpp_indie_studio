/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Map
*/

#include "Map.hpp"
#include "Floor.hpp"
#include "Booster.hpp"
#include "JsonRead.hpp"
#include "Wall.hpp"

Eo::Map::Map(size_t w, size_t h) : _w(w), _h(h)
{
	_map.reserve(_w * _h);
	for (size_t i = 0; i < _h; i++)
		for (size_t j = 0; j < _w; j++) {
			auto isWall = i == 0 || j == 0;
			isWall |= i == (_w - 1) || j == (_h - 1);
			_map.push_back(isWall ?
					new Wall(Eo::Wall::INDESTRUCTIBLE) :
					nullptr);
		}
}

Eo::Map::Map(Eo::JsonRead &json) : _w(0), _h(0)
{
	auto matrix = json.readMatrix("map");
	const std::vector<std::function<IObject *(void)>> v = {
		[] { return nullptr; },
		[] { return new Wall(Eo::Wall::WallType::INDESTRUCTIBLE); },
		[] { return new Wall(Eo::Wall::WallType::DESTRUCTIBLE); },
		[] { return new Eo::Booster(Eo::Booster::BoosterType::SPEED); }};

	Eo::Floor floor(200);
	_w = matrix.size();
	_h = matrix.at(0).size();
	_map.reserve(_w * _h);
	for (size_t i = 0; i < _h; i++)
		for (size_t j = 0; j < _w; j++)
			_map.push_back(v.at(matrix.at(i).at(j))());
}

size_t Eo::Map::getWidth() const
{
	return _w;
}

size_t Eo::Map::getHeight() const
{
	return _h;
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
	_w = json.readMatrix("map").size();
	_h = json.readMatrix("map").at(0).size();

	for (size_t l = 0; l < _h; ++l) {
		putObject(new Eo::Wall(Eo::Wall::INDESTRUCTIBLE), 0, l);
		putObject(new Eo::Wall(Eo::Wall::INDESTRUCTIBLE), _h, l);
	}
	for (size_t l = 1; l < _w - 1; ++l) {
		putObject(new Eo::Wall(Eo::Wall::INDESTRUCTIBLE), 0, 1);
		putObject(new Eo::Wall(Eo::Wall::INDESTRUCTIBLE), l, _h - 1);
	}
}
