/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Map
*/

#include "Map.hpp"
#include "Booster.hpp"
#include "Floor.hpp"
#include "Flame.hpp"
#include "JsonRead.hpp"
#include "Wall.hpp"
#include <iostream>

Eo::Map::Map(Eo::u32 w, Eo::u32 h) : _w(w), _h(h)
{
	_map.reserve(_w * _h);
	for (Eo::u32 i = 0; i < _h; i++)
		for (Eo::u32 j = 0; j < _w; j++) {
			auto isWall = i == 0 || j == 0;
			isWall |= i == (_w - 1) || j == (_h - 1);
			_map.emplace_back(isWall ?
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
		[] {
			return new Eo::Booster(
				Eo::Booster::BoosterType::SPEED);
		},
		[] {
			return new Eo::Booster(
				Eo::Booster::BoosterType::SUPERBOMB);
		},
		[] {
			return new Eo::Booster(
				Eo::Booster::BoosterType::NBBOMB);
		}};

	_w = matrix.size();
	_h = matrix.at(0).size();
	_map.reserve(_w * _h);
	for (Eo::u32 i = 0; i < _h; i++)
		for (Eo::u32 j = 0; j < _w; j++)
			_map.emplace_back(v.at(matrix.at(i).at(j))());
}

Eo::i32 Eo::Map::getWidth() const
{
	return _w;
}

Eo::i32 Eo::Map::getHeight() const
{
	return _h;
}

Eo::Rc<Eo::IObject> Eo::Map::getObject(Eo::u32 x, Eo::u32 y)
{
	return _map.at(x + y * _w);
}

Eo::Rc<Eo::IObject> Eo::Map::putObject(
	const Eo::Rc<Eo::IObject> &object, Eo::u32 x, Eo::u32 y)
{
	_map.at(x + y * _w) = object;
	return object;
}

Eo::Rc<Eo::IObject> Eo::Map::putObject(
	Eo::IObject *object, Eo::u32 x, Eo::u32 y)
{
	auto &loc = _map.at(x + y * _w);
	loc = Eo::Rc<Eo::IObject>(object);
	return loc;
}

std::vector<Eo::Rc<Eo::IObject>> &Eo::Map::getObjects()
{
	return _map;
}

void Eo::Map::generateMap(const std::string &mapPath)
{
	auto json = Eo::JsonRead(mapPath);
	_w = json.readMatrix("map").size();
	_h = json.readMatrix("map").at(0).size();

	for (Eo::u32 l = 0; l < _h; ++l) {
		putObject(new Eo::Wall(Eo::Wall::INDESTRUCTIBLE), 0, l);
		putObject(new Eo::Wall(Eo::Wall::INDESTRUCTIBLE), _h, l);
	}
	for (Eo::u32 l = 1; l < _w - 1; ++l) {
		putObject(new Eo::Wall(Eo::Wall::INDESTRUCTIBLE), 0, 1);
		putObject(new Eo::Wall(Eo::Wall::INDESTRUCTIBLE), l, _h - 1);
	}
}

bool Eo::Map::update(Eo::Rc<Eo::IScene> scene)
{
	std::for_each(_map.begin(), _map.end(),
		[scene](Eo::Rc<Eo::IObject> &obj) {
		// std::cout << "HERE !" << std::endl;
		// if (obj.get() != nullptr)
		// 	std::cout << obj->getType() << std::endl;
		if (obj.get() != nullptr && obj->update() == false) {
			auto isBomb = obj->getType() == Eo::IObject::Type::BOMB;
			if (isBomb)
				obj = Eo::initRc<Eo::Flame>(scene,
					obj->getPosition());
			else
				obj = nullptr;
		}
	});
	return true;
}
