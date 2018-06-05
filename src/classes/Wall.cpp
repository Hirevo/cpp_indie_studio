/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Wall
*/

#include "Wall.hpp"

Eo::Wall::Wall(Eo::Wall::WallType wallType, Eo::vec3 pos)
	: AObject(Eo::IObject::WALL), _wallType(wallType)
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
