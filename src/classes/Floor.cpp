/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Floor
*/

#include "Floor.hpp"

Eo::Floor::Floor(size_t size, irr::core::vector3df pos)
	: AObject(Eo::IObject::FLOOR), AMovable(pos), _size(size)
{
}

void Eo::Floor::insertInScene(Eo::IScene *scene)
{
	auto manager = scene->getSceneManager();
	irr::f32 unitSize = 10.0f;

	if (_placedInScene == true)
		return;
	auto mesh = manager->getGeometryCreator()->createPlaneMesh(
		irr::core::dimension2df(_size, _size));
	_node = manager->addMeshSceneNode(mesh);
	_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_hasPositionChanged = false;
	_placedInScene = true;
}

void Eo::Floor::removeFromScene(Eo::IScene *scene)
{
	(void)(scene);
	if (_placedInScene == false)
		return;
	_node->remove();
	_hasPositionChanged = false;
	_placedInScene = false;
}

void Eo::Floor::updateInScene(Eo::IScene *scene)
{
	_node->setPosition(_pos);
	_hasPositionChanged = false;
}