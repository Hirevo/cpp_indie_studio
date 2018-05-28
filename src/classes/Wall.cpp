/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Wall
*/

#include "Wall.hpp"

Eo::Wall::Wall(Eo::Wall::WallType wallType, irr::core::vector3df pos)
	: AObject(Eo::IObject::WALL), AMovable(pos), _wallType(wallType)
{
}

void Eo::Wall::insertInScene(Eo::IScene *scene)
{
	auto manager = scene->getSceneManager();
	irr::f32 unitSize = 10.0f;

	if (_placedInScene == true)
		return;
	_node = manager->addCubeSceneNode(unitSize, nullptr, -1, _pos);
	_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_hasPositionChanged = false;
	_placedInScene = true;
}

void Eo::Wall::removeFromScene(Eo::IScene *scene)
{
	(void)(scene);
	if (_placedInScene == false)
		return;
	_node->remove();
	_hasPositionChanged = false;
	_placedInScene = false;
}

void Eo::Wall::updateInScene(Eo::IScene *scene)
{
	_node->setPosition(_pos);
	_hasPositionChanged = false;
}