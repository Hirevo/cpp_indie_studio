/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Bomb.hpp"
#include "Flame.hpp"
#include <chrono>
#include <iostream>

Eo::Bomb::Bomb(Eo::Rc<Eo::Game> scene, const Eo::vec2i &mapPos,
	const Eo::vec3 &pos)
	: AModel(Eo::IObject::Type::BOMB, pos),
	  _clock(std::chrono::high_resolution_clock::now()), _scene(scene),
	  _map(scene->getMap())
{
	Eo::AModel::loadModel(scene, "../assets/Bomberman/Bomb.x", "");
	_node->setScale(Eo::vec3(0.5, 0.5, 0.5));
	prepareExplosion(mapPos, scene);
}

Eo::Bomb::~Bomb()
{
	_explode();
}

void Eo::Bomb::propagateExplosion(
	Eo::vec2i pos, Eo::vec2i sizes, Eo::vec2i dir)
{
	if (sizes.Y > sizes.X)
		return;
	auto obj = _map->getObject(
		pos.X + dir.X * sizes.Y, pos.Y + dir.Y * sizes.Y);
	if (obj.get() == nullptr || obj->getType() != Eo::IObject::WALL) {
		Eo::Bomb::propagateExplosion(
			pos, sizes + Eo::vec2i(0, 1), dir);
		_map->putObject(
			Eo::initRc<Eo::Flame>(Eo::vec3(pos.X, pos.Y, 0)),
			pos.X + dir.X * sizes.Y, pos.Y + dir.Y * sizes.Y);
	}
}

void Eo::Bomb::prepareExplosion(const Eo::vec2i &mapPos, Eo::Rc<Eo::Game> scene)
{
	_explode = [this, mapPos, scene] {
		auto map = scene->getMap();
		Eo::Bomb::propagateExplosion(mapPos + Eo::vec2i(1, 0),
			Eo::vec2i(3, 0), Eo::vec2i(1, 0));
		Eo::Bomb::propagateExplosion(mapPos + Eo::vec2i(-1, 0),
			Eo::vec2i(3, 0), Eo::vec2i(-1, 0));
		Eo::Bomb::propagateExplosion(mapPos + Eo::vec2i(0, 1),
			Eo::vec2i(3, 0), Eo::vec2i(0, 1));
		Eo::Bomb::propagateExplosion(mapPos + Eo::vec2i(0, -1),
			Eo::vec2i(3, 0), Eo::vec2i(0, -1));
	};
}

#include <iostream>

bool Eo::Bomb::update()
{
	std::chrono::milliseconds diff =
		std::chrono::duration_cast<std::chrono::milliseconds>(
			std::chrono::high_resolution_clock::now() - _clock);
	std::cout << "Bomb Diff: " << diff.count() << std::endl;
	using namespace std::chrono_literals;
	return (diff <= EXPLODE_DELAY);
}