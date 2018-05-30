/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Game.hpp"
#include <iostream>

Eo::Game::Game(Eo::Device &device, const std::string &mapPath)
	: AGame(device), _json(mapPath), _map(_json), _camera()
{
	Eo::IObject *obj;
	ssize_t wth = _map.getWidth();
	ssize_t hgt = _map.getHeight();

	_camera.insertInScene(this);
	for (ssize_t i = 0; i < hgt; i++)
		for (ssize_t j = 0; j < wth; j++) {
			obj = _map.getObject(j, i);
			if (obj) {
				obj->setPosition((j - (wth / 2)) * 10, 0,
					(i - (hgt / 2)) * 10);
				obj->insertInScene(this);
				obj->getSceneNode()->setMaterialFlag(
					irr::video::EMF_WIREFRAME, true);
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
