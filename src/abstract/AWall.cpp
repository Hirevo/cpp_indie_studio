/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "AWall.hpp"

Eo::AWall::AWall(Eo::AWall::WallType wallType, irr::core::vector3df pos)
	: AObject(Eo::IObject::WALL), AMovable(pos), _wallType(wallType)
{
}

void Eo::AWall::insertInScene(Eo::IScene *scene)
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

void Eo::AWall::removeFromScene(Eo::IScene *scene)
{
	(void)(scene);
	if (_placedInScene == false)
		return;
	_node->remove();
	_hasPositionChanged = false;
	_placedInScene = false;
}

void Eo::AWall::updateInScene(Eo::IScene *scene)
{
	_node->setPosition(_pos);
	_hasPositionChanged = false;
}
