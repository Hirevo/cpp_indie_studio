/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Scene.hpp"

Eo::Scene::Scene(Eo::Device &device) :
	_device(device)
{
	_sceneManager = _device.get_device()->getSceneManager();
}

/*addCubeSceneNode(	f32 		size = 10.0f,
**			ISceneNode * 	parent = 0,
**			s32 		id = -1,
**const core::vector3df & 		position = core::vector3df(0, 0, 0),
**const core::vector3df & 		rotation = core::vector3df(0, 0, 0),
**const core::vector3df & 		scale = core::vector3df(1.0f,1.0f,1.0f)
*/
void Eo::Scene::addMapBlock(irr::f32 unitSize, const irr::core::vector3df &pos)
{
	irr::scene::IMeshSceneNode* cube = _sceneManager->addCubeSceneNode(
			unitSize,
			nullptr,
			-1,
			pos);
	cube->setMaterialFlag(irr::video::EMF_WIREFRAME, true);
	_map.push(cube);
}

void Eo::Scene::addMapBlock(irr::f32 x, irr::f32 y, irr::f32 z)
{
	irr::f32 unitSize = 10.0f;
	irr::core::vector3df pos;

	pos.X = x;
	pos.Y = y;
	pos.Z = z;
	irr::scene::IMeshSceneNode* cube = _sceneManager->addCubeSceneNode(
		unitSize,
		nullptr,
		-1,
		pos);
	cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	cube->setMaterialTexture( 0, _device.get_driver()->getTexture("../assets/img/oui.jpg") );

	_map.push(cube);
}

irr::scene::ISceneManager *Eo::Scene::get_sceneManager() const
{
	return _sceneManager;
}
