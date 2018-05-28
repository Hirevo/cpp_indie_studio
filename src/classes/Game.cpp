/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Game.hpp"

Eo::Game::Game(Eo::Device &device, const std::string &mapPath) :
	AGame(device),
	_json(mapPath),
	_map(_json.readMatrix("map").size(),
		_json.readMatrix("map").at(0).size())
{
}

void Eo::Game::addMapFloor()
{
	irr::core::dimension2d<irr::f32> tileSize(50,50);
	irr::core::dimension2d<irr::u32> tileCount(50,50);
	irr::video::SMaterial material;
	irr::core::dimension2d<irr::f32> textureRepeatCount(50,50);

	material.setTexture(0,
		_device.getDriver()->getTexture("../assets/img/damier.jpg"));
	irr::scene::IMesh *cube =
	_sceneManager->getGeometryCreator()->createPlaneMesh(
		tileSize,
		tileCount,
		&material,
		textureRepeatCount);
	cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_sceneManager->addMeshSceneNode(cube);
}

void Eo::Game::addMapBlock(irr::f32 x, irr::f32 y, irr::f32 z)
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
		_device.getDriver()->getTexture("../assets/img/oui.jpg"));
}

irr::scene::ISceneManager *Eo::Game::getSceneManager() const
{
	return _sceneManager;
}
