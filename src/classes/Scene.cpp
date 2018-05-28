/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Scene.hpp"

Eo::Scene::Scene(Eo::Device &device)
	: _device(device)
{
	_sceneManager = _device.get_device()->getSceneManager();
}

/*
 * addMapBlock create a cube with two constructor
 * 	x y z  ||  cubeSize and his pos
 */
void Eo::Scene::addMapBlock(irr::f32 cubeSize, const irr::core::vector3df &pos)
{
	irr::scene::IMeshSceneNode *cube = _sceneManager->addCubeSceneNode(
		cubeSize, nullptr, -1, pos);
	cube->setMaterialFlag(irr::video::EMF_WIREFRAME, true);
	_map.push(cube);
}

void Eo::Scene::addMapFloor()
{
	irr::core::dimension2d<irr::f32> tileSize(50,50);
	irr::core::dimension2d<irr::u32> tileCount(50,50);
	irr::video::SMaterial material;
	irr::core::dimension2d<irr::f32> textureRepeatCount(50,50);

	material.setTexture(0,
		_device.get_driver()->getTexture("../assets/img/damier.jpg"));
	irr::scene::IMesh *cube =
	_sceneManager->getGeometryCreator()->createPlaneMesh(
		tileSize,
		tileCount,
		&material,
		textureRepeatCount);
	cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_sceneManager->addMeshSceneNode(cube);
}

void Eo::Scene::addMapBlock(irr::f32 x, irr::f32 y, irr::f32 z)
{
	irr::f32 unitSize = 10.0f;
	irr::core::vector3df pos;
	pos.X = x;
	pos.Y = y;
	pos.Z = z;
	irr::scene::IMeshSceneNode *cube = _sceneManager->addCubeSceneNode(
		unitSize, nullptr, -1, pos);
	cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	cube->setMaterialTexture(0,
		_device.get_driver()->getTexture("../assets/img/oui.jpg"));
	_map.push(cube);
}

irr::scene::ISceneManager *Eo::Scene::get_sceneManager() const
{
	return _sceneManager;
}

