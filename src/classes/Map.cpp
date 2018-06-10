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

const std::pair<Eo::u32, Eo::u32> Eo::Map::_defaultSize = {21, 21};

Eo::Map::Map(Eo::u32 w, Eo::u32 h) : _w(w), _h(h)
{
	_map.reserve(_w * _h);
	for (Eo::u32 i = 0 ; i < _h ; i++)
		for (Eo::u32 j = 0 ; j < _w ; j++) {
			auto isWall = i == 0 || j == 0 || i == (_h - 1) ||
				j == (_w - 1) || (i % 2 == 0 && j % 2 == 0);
			auto empty = !(
				((i > 0 && i <= 2) && (j > 0 && j <= 2)) ||
					((j < _w - 1 && j >= _w - 3) &&
						(i < _h - 1 && i >= _h - 3)) ||
					((j < _w - 1 && j >= _w - 3) &&
						(i > 0 && i <= 2)) ||
					((j > 0 && j <= 2) &&
						(i < _h - 1 && i >= _h - 3)));
			_map.emplace_back(isWall ?
				new Wall(Eo::Wall::INDESTRUCTIBLE) :
				(empty && rand() % 5 != 1 ? new Wall(
					Eo::Wall::DESTRUCTIBLE) :
					nullptr));
		}
}

Eo::Map::Map(Eo::JsonRead &json, bool randomize) : _w(0), _h(0)
{
	if (!json.good()) {
		*this = Eo::Map(_defaultSize.first, _defaultSize.second);
		return;
	}
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
		},
		[] {
			return new Eo::Booster(
				Eo::Booster::BoosterType::WALLPASS);
		},
		[] { return new Wall(Eo::Wall::WallType::BOUNDS); }};

	_w = matrix.size();
	_h = matrix.at(0).size();
	_map.reserve(_w * _h);
	// std::fill(_map.begin(), _map.end(), Eo::Rc<Eo::IObject>(nullptr));
	for (Eo::u32 i = 0 ; i < _h ; i++)
		for (Eo::u32 j = 0 ; j < _w ; j++) {
			auto empty = !(
				((i > 0 && i <= 2) && (j > 0 && j <= 2)) ||
					((j < _w - 1 && j >= _w - 3) &&
						(i < _h - 1 && i >= _h - 3)) ||
					((j < _w - 1 && j >= _w - 3) &&
						(i > 0 && i <= 2)) ||
					((j > 0 && j <= 2) &&
						(i < _h - 1 && i >= _h - 3)));
			if ((i == 0 || j == 0 || i == (_w - 1) ||
				j == (_h - 1))
				&& matrix.at(i).at(j) == 1)
				_map.emplace_back(v.at(7)());
			else if (randomize && !(matrix.at(i).at(j)))
				if (empty && rand() % 5 != 1)
					_map.emplace_back(v.at(2)());
				else
					_map.emplace_back(v.at(0)());
			else
				_map.emplace_back(v.at(matrix.at(i).at(j))());
		}
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

std::vector<std::vector<Eo::i32>> Eo::Map::generateMatrix()
{
	std::vector<std::vector<Eo::i32>> ret;

	for (int i = 0 ; i < _h ; i++) {
		ret.emplace_back();
		for (int j = 0 ; j < _w ; j++) {
			auto &obj = _map[i * _w + j];
			if (obj && obj->getType() < 7)
				ret[i].emplace_back(obj->getType());
			else
				ret[i].emplace_back(0);
		}
	}
	return ret;
}

void Eo::Map::generateMap(const std::string &mapPath)
{
	auto json = Eo::JsonRead(mapPath);
	_w = json.readMatrix("map").size();
	_h = json.readMatrix("map").at(0).size();

	for (Eo::u32 l = 0 ; l < _h ; ++l) {
		putObject(new Eo::Wall(Eo::Wall::INDESTRUCTIBLE), 0, l);
		putObject(new Eo::Wall(Eo::Wall::INDESTRUCTIBLE), _h, l);
	}
	for (Eo::u32 l = 1 ; l < _w - 1 ; ++l) {
		putObject(new Eo::Wall(Eo::Wall::INDESTRUCTIBLE), 0, 1);
		putObject(new Eo::Wall(Eo::Wall::INDESTRUCTIBLE), l, _h - 1);
	}
}

bool Eo::Map::update(Eo::Rc<Eo::IScene> scene)
{
	std::for_each(_map.begin(), _map.end(),
		[scene](Eo::Rc<Eo::IObject> &obj) {
			if (obj.get() != nullptr && !obj->update()) {
				auto isBomb = obj->getType() ==
					Eo::IObject::Type::BOMB;
				if (isBomb)
					obj = Eo::initRc<Eo::Flame>(scene,
						obj->getPosition());
				else
					obj = nullptr;
			}
		});
	return true;
}

Eo::vec2 Eo::Map::translate2D(Eo::vec3 vec)
{
	Eo::vec2 vec2(std::roundf(vec.X), roundf(vec.Z));
	vec2.X += this->getWidth() / 2;
	vec2.Y += this->getHeight() / 2;
	return vec2;
}

Eo::vec3 Eo::Map::translate3D(Eo::vec2 vec)
{
	Eo::vec3 vec3(vec.X, 0, vec.Y);
	vec3.X -= this->getWidth() / 2;
	vec3.Z -= this->getHeight() / 2;
	return vec3;
}
