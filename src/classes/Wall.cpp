/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Wall
*/

#include "Wall.hpp"

const std::unordered_map<Eo::Wall::WallType, std::string> Eo::Wall::_textures{
	{Eo::Wall::WallType::DESTRUCTIBLE, "../assets/img/bricks.png"},
	{Eo::Wall::WallType::INDESTRUCTIBLE, "../assets/img/block.png"}};

Eo::Wall::Wall(Eo::Wall::WallType wallType, Eo::vec3 pos)
	: AObject(static_cast<Eo::IObject::Type>(wallType)),
	  _wallType(wallType)
{
}

void Eo::Wall::insertInScene(const Eo::IScene *scene)
{
	auto manager = scene->getSceneManager();
	irr::f32 unitSize = 1.0f;

	if (_placedInScene == true)
		return;
	_node = manager->addCubeSceneNode(unitSize, nullptr, -1, _pos);
	_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_node->setMaterialTexture(0,
		manager->getVideoDriver()->getTexture(
			_textures.at(_wallType).c_str()));
	Eo::Wall::updateInScene(scene);
	_hasPositionChanged = false;
	_placedInScene = true;
}

void Eo::Wall::removeFromScene(const Eo::IScene *scene)
{
	(void)(scene);
	if (_placedInScene == false || _hasNode == false)
		return;
	_node->remove();
	_hasPositionChanged = false;
	_placedInScene = false;
}

void Eo::Wall::updateInScene(const Eo::IScene *scene)
{
	if (_placedInScene == false || _hasNode == false)
		return;
	_node->setPosition(_pos);
	_hasPositionChanged = false;
}
