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
#include <exception>

const std::unordered_map<Eo::Bomb::BombSize, Eo::SoundDevice::SoundPath> Eo::Bomb::_soundPath = {
	{SMALL,  Eo::SoundDevice::BOMBS},
	{MEDIUM, Eo::SoundDevice::BOMBM},
	{LARGE,  Eo::SoundDevice::BOMBL},
};

Eo::Bomb::Bomb(
	Eo::Rc<Eo::Game> scene, Eo::Rc<Eo::ICharacter> player,
	const Eo::vec2i &mapPos, const Eo::vec3 &pos,
	Eo::Rc<Eo::SoundDevice> sound)
	: AModel(Eo::IObject::Type::BOMB, pos),
	_clock(std::chrono::high_resolution_clock::now()), _scene(scene),
	_map(scene->getMap()), _player(player), _sound(sound)
{
	prepareExplosion(mapPos, scene);
	_sound->play(Eo::SoundDevice::SETBOMB);
	Eo::Bomb::insertInScene(scene);
}

Eo::Bomb::~Bomb()
{
	auto bombSize = this->getBombSize();
	if (_soundPath.count(bombSize) > 0)
		_sound->play(_soundPath.at(bombSize));
	_explode();
	Eo::AObject::removeFromScene();
}

void Eo::Bomb::insertInScene(const Eo::Rc<Eo::IScene> scene)
{
	Eo::AModel::loadModel(scene, currPath + "../assets/Bomberman/Bomb.x",
		currPath + "../assets/img/bomb_border.png");
	_node->setScale(Eo::vec3(0.25, 0.25, 0.25));
}

Eo::Bomb::BombSize Eo::Bomb::getBombSize() const
{
	auto radius = _player->getBombRadius();
	if (radius <= 2)
		return Eo::Bomb::SMALL;
	else if (radius <= 5)
		return Eo::Bomb::MEDIUM;
	else
		return Eo::Bomb::LARGE;
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
	if (_map->translate2D(_player->getPosition()).X == posX &&
		_map->translate2D(_player->getPosition()).Y == posY)
		_player->die();
	if (!obj.get() || obj->getType() != Eo::IObject::WALL) {
		if (!obj.get() || obj->getType() != Eo::IObject::DEST_WALL)
			Eo::Bomb::propagateExplosion(
				pos, sizes + Eo::vec2i(0, 1), dir);
		if (obj.get() && obj->getType() == Eo::IObject::DEST_WALL &&
			rand() % 4 == 0) {
			auto val = this->boosterDrop();
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
	auto map = _scene->getMap();
	_explode = [this, mapPos, map] {
		_player->setAvailableBombs(_player->getAvailableBombs() + 1);
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

/*
** More you have a booster in the Array, more is the drop value of this booster.
*/
static const std::vector<Eo::Booster::BoosterType> BOOSTER_DROP_RATE = {
	Eo::Booster::BoosterType::SPEED,
	Eo::Booster::BoosterType::SPEED,
	Eo::Booster::BoosterType::SPEED,
	Eo::Booster::BoosterType::SPEED,
	Eo::Booster::BoosterType::SPEED,
	Eo::Booster::BoosterType::SUPERBOMB,
	Eo::Booster::BoosterType::SUPERBOMB,
	Eo::Booster::BoosterType::SUPERBOMB,
	Eo::Booster::BoosterType::SUPERBOMB,
	Eo::Booster::BoosterType::SUPERBOMB,
	Eo::Booster::BoosterType::NBBOMB,
	Eo::Booster::BoosterType::NBBOMB,
	Eo::Booster::BoosterType::NBBOMB,
	Eo::Booster::BoosterType::NBBOMB,
	Eo::Booster::BoosterType::NBBOMB,
	Eo::Booster::BoosterType::WALLPASS
};

int Eo::Bomb::boosterDrop()
{
	return BOOSTER_DROP_RATE[(rand() % BOOSTER_DROP_RATE.size())];
}
