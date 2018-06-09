/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Bomb.hpp"
#include "Flame.hpp"
#include <chrono>

Eo::Bomb::Bomb(
	Eo::Rc<Eo::Game> scene, Eo::Rc<Eo::ICharacter> player,
		const Eo::vec2i &mapPos, const Eo::vec3 &pos)
	: AModel(Eo::IObject::Type::BOMB, pos),
	  _clock(std::chrono::high_resolution_clock::now()), _scene(scene),
	  _map(scene->getMap()), _player(player)
{
	Eo::AModel::loadModel(scene, "../assets/Bomberman/Bomb.x",
		"../assets/img/bomb_border.png");
	_node->setScale(Eo::vec3(0.25, 0.25, 0.25));
	prepareExplosion(mapPos, scene);
}

Eo::Bomb::~Bomb()
{
	_explode();
}

void Eo::Bomb::propagateExplosion(
	Eo::vec2i pos, Eo::vec2i sizes, Eo::vec2i dir)
{
	if (sizes.Y >= sizes.X)
		return;
	auto posX = pos.X + dir.X * sizes.Y;
	auto posY = pos.Y + dir.Y * sizes.Y;
	auto inScene = Eo::vec3(posX - _map->getWidth() / 2, 0,
		posY - _map->getHeight() / 2);
	auto obj = _map->getObject(posX, posY);
	if (!obj.get() || obj->getType() != Eo::IObject::WALL) {
		if (!obj.get() || obj->getType() != Eo::IObject::DEST_WALL)
			Eo::Bomb::propagateExplosion(
				pos, sizes + Eo::vec2i(0, 1), dir);
		if (obj.get() && obj->getType() == Eo::IObject::DEST_WALL &&
			rand() % 3 == 0) {
			auto val = (rand() % (Eo::Booster::BONUSCOUNT - 1)) + 1;
			auto en = static_cast<Eo::Booster::BoosterType>(val);
			auto obj = _map->putObject(
				Eo::initRc<Eo::Booster>(en, inScene), posX,
				posY);
			obj->insertInScene(_scene);
		} else
			_map->putObject(Eo::initRc<Eo::Flame>(_scene, inScene),
				posX, posY);
	}
}

void Eo::Bomb::prepareExplosion(
	const Eo::vec2i &mapPos, Eo::Rc<Eo::Game> scene)
{
	_explode = [this, mapPos, scene] {
		_player->setAvailableBombs(_player->getAvailableBombs() + 1);
		auto map = scene->getMap();
		Eo::Bomb::propagateExplosion(mapPos + Eo::vec2i(1, 0),
			Eo::vec2i(_player->getBombRadius(), 0),
			Eo::vec2i(1, 0));
		Eo::Bomb::propagateExplosion(mapPos + Eo::vec2i(-1, 0),
			Eo::vec2i(_player->getBombRadius(), 0),
			Eo::vec2i(-1, 0));
		Eo::Bomb::propagateExplosion(mapPos + Eo::vec2i(0, 1),
			Eo::vec2i(_player->getBombRadius(), 0),
			Eo::vec2i(0, 1));
		Eo::Bomb::propagateExplosion(mapPos + Eo::vec2i(0, -1),
			Eo::vec2i(_player->getBombRadius(), 0),
			Eo::vec2i(0, -1));
	};
}

bool Eo::Bomb::update()
{
	std::chrono::milliseconds diff =
		std::chrono::duration_cast<std::chrono::milliseconds>(
			std::chrono::high_resolution_clock::now() - _clock);
	using namespace std::chrono_literals;
	return (diff <= EXPLODE_DELAY);
}