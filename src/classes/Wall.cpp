/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Wall
*/

#include "Wall.hpp"

const std::unordered_map<Eo::Wall::WallType, std::string> Eo::Wall::_models{
	{Eo::Wall::WallType::DESTRUCTIBLE,
		currPath + "../assets/Bomberman/Brick.x"},
	{Eo::Wall::WallType::INDESTRUCTIBLE,
		currPath + "../assets/Bomberman/Block.x"},
	{Eo::Wall::WallType::BOUNDS,
		currPath + "../assets/Bomberman/Bound.x"}};

const std::unordered_map<Eo::Wall::WallType, std::string> Eo::Wall::_textures{
	{Eo::Wall::WallType::DESTRUCTIBLE,
		currPath + "../assets/img/brick.png"},
	{Eo::Wall::WallType::INDESTRUCTIBLE,
		currPath + "../assets/img/pylone.png"},
	{Eo::Wall::WallType::BOUNDS,
		currPath + "../assets/img/block.png"}};

Eo::Wall::Wall(Eo::Wall::WallType wallType, Eo::vec3 pos)
	: AModel(static_cast<Eo::IObject::Type>((wallType == BOUNDS)
	? INDESTRUCTIBLE : wallType), pos), _wallType(wallType)
{
}

Eo::Wall::~Wall()
{
}

void Eo::Wall::insertInScene(const Eo::Rc<Eo::IScene> scene)
{
	Eo::AModel::loadModel(scene, _models.at(_wallType),
		_textures.at(_wallType));
	_node->setScale(Eo::vec3(0.25, 0.25, 0.25));
}

void Eo::Wall::updateInScene()
{
	if (_placedInScene == false || _hasNode == false)
		return;
	_node->setPosition(_pos);
	_hasPositionChanged = false;
}
