/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Game.hpp"
#include "Floor.hpp"
#include <iostream>

Eo::Game::Game(Eo::Device &device, const std::string &mapPath)
	: AGame(device), _json(mapPath), _map(_json), _camera()
{
	Eo::IObject *obj;
	irr::s32 wth = _map.getWidth();
	irr::s32 hgt = _map.getHeight();
	auto texture = device.getDevice()->getSceneManager()->getVideoDriver()->getTexture("../assets/img/red_silk.jpg");
	_camera.insertStaticInScene(this);
	Eo::Floor floor((wth - 1)*(hgt - 1) - 10);
	floor.insertInScene(this);
	for (irr::s32 i = 0; i < hgt; i++)
		for (irr::s32 j = 0; j < wth; j++) {
			obj = _map.getObject(j, i);
			if (obj) {
				obj->setPosition((j - (wth / 2)) * 10, 5,
					(i - (hgt / 2)) * 10);
				obj->insertInScene(this);
				obj->getSceneNode()->setMaterialFlag(irr::video::EMF_LIGHTING,
					false);
				obj->getSceneNode()->setMaterialTexture(0, texture);
			}
		}
}

Eo::Game::~Game()
{
}

irr::scene::ICameraSceneNode *Eo::Game::getCamera() const
{
	return dynamic_cast<irr::scene::ICameraSceneNode *>(
		_camera.getSceneNode());
}

Eo::Camera &Eo::Game::get_camera()
{
	return _camera;
}
