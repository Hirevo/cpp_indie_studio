/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Floor
*/

#include "Floor.hpp"

Eo::Floor::Floor(size_t size, vec3 pos)
	: AObject(Eo::IObject::FLOOR), _size(size)
{
}

void Eo::Floor::insertInScene(const Eo::IScene *scene)
{
	auto manager = scene->getSceneManager();
	auto texture = scene->getSceneManager()->getVideoDriver()->getTexture(
		"../assets/img/damier.jpg");
	irr::f32 unitSize = 10.0f;

	if (_placedInScene == true)
		return;
	auto mesh = manager->getGeometryCreator()->createPlaneMesh(
		irr::core::dimension2df(_size, _size));
	_node = manager->addMeshSceneNode(mesh);
	_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	Eo::Floor::updateInScene(scene);
	_node->setMaterialTexture(0, texture);
	_hasPositionChanged = false;
	_placedInScene = true;
}

void Eo::Floor::removeFromScene(const Eo::IScene *scene)
{
	(void)(scene);
	if (_placedInScene == false)
		return;
	_node->remove();
	_hasPositionChanged = false;
	_placedInScene = false;
}

void Eo::Floor::updateInScene(const Eo::IScene *scene)
{
	_node->setPosition(_pos);
	_hasPositionChanged = false;
}
