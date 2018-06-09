/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Computer.hpp"

Eo::Computer::Computer(Eo::Rc<Eo::IScene> game, const Eo::vec3 &pos,
	Eo::u32 playerID)
	: AModel(Eo::IObject::Type::CHARACTER, pos), ACharacter(playerID)
{
	std::stringstream path;
	path << "../assets/img/bomberboy_";
	path << playerID + 1;
	path << ".png";
	this->loadModel(game, "../assets/Bomberman/Character.x",
		path.str().c_str());
	_scale = vec3(0.28f);
	this->getAnimatedNode()->setScale(_scale);
	this->getAnimatedNode()->setAnimationSpeed(2000.f);
	_counter = 0;
	_dir = Eo::vec3(0);
}

Eo::vec3 Eo::Computer::getDirection() const
{
	return _dir;
}

Eo::i32 Eo::Computer::getCounter() const
{
	return _counter;
}

void Eo::Computer::searchDirection(Eo::Rc<Eo::Map> map)
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::vector<std::pair<Eo::vec3, Eo::i32>> directions;

	directions.push_back(std::make_pair(vec3(0, 0, _speed), 270));
	directions.push_back(std::make_pair(vec3(0, 0, -_speed), 90));
	directions.push_back(std::make_pair(vec3(_speed, 0, 0), 0));
	directions.push_back(std::make_pair(vec3(-_speed, 0, 0), 180));
	std::uniform_real_distribution<> dist(0, directions.size());
	Eo::i32 rand = dist(mt);
	_dir = directions.at(rand).first;
	this->setRotation(directions.at(rand).second);
	dist = std::uniform_real_distribution<>(10, 150);
	_counter = dist(mt);
}

void Eo::Computer::updatePosition(Eo::Rc<Eo::Map> map)
{
	if (_counter == 0)
		searchDirection(map);
	if (isValidDirection(this->getPosition() + _dir, map)) {
		this->translate(_dir);
		_counter--;
	} else
		_counter = 0;
}

bool Eo::Computer::checkPoseBomb(Eo::Rc<Eo::Map> map)
{
	bool ret = false;
	std::vector<Eo::IObject::Type> outline;
	auto type = getObjectType(this->getPosition(), map);

	if (type != IObject::BOMB) {
		outline.push_back(getObjectType(vec3(this->getPosition() + vec3(0, 0, 0.5)), map));
		outline.push_back(getObjectType(vec3(this->getPosition() + vec3(0, 0, -0.5)), map));
		outline.push_back(getObjectType(vec3(this->getPosition() + vec3(0.5, 0, 0)), map));
		outline.push_back(getObjectType(vec3(this->getPosition() + vec3(-0.5, 0, 0)), map));
		if (std::find(outline.begin(), outline.end(), Eo::IObject::DEST_WALL) != outline.end()) {
			ret = true;
		}
	}
	return ret;
}

Eo::IObject::Type Eo::Computer::getObjectType(Eo::vec3 pos, Eo::Rc<Eo::Map> map)
{
	IObject::Type type = NONE;

	auto posX = roundf(pos.X) + map->getWidth() / 2;
	auto posY = roundf(pos.Z) + map->getHeight() / 2;
	auto object = map->getObject(posX, posY);
	if (object)
		type = object->getType();
	return type;
}

bool Eo::Computer::isValidDirection(Eo::vec3 pos, Eo::Rc<Eo::Map> map)
{
	auto type = getObjectType(pos, map);

	return !(type == IObject::WALL || type == IObject::DEST_WALL);
}