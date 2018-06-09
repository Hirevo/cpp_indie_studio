/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Floor
*/

#include "Floor.hpp"

Eo::Floor::Floor(irr::f32 size, vec3 pos)
	: AObject(Eo::IObject::FLOOR, 0, pos), _size(size)
{
}

void Eo::Floor::insertInScene(const Eo::Rc<Eo::IScene> scene)
{
	auto manager = scene->getSceneManager();
	auto texture = scene->getSceneManager()->getVideoDriver()
		->getTexture("../assets/img/floor.png");
	auto mesh = manager->getGeometryCreator()->createPlaneMesh(
		irr::core::dimension2df(_size, _size), {1, 1}, nullptr,
		{_size, _size});
	_node = manager->addMeshSceneNode(mesh);
	_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	Eo::Floor::updateInScene();
	_node->setMaterialTexture(0, texture);
	_hasPositionChanged = false;
	_placedInScene = true;
}

void Eo::Floor::updateInScene()
{
	_node->setPosition(_pos);
	_hasPositionChanged = false;
}
