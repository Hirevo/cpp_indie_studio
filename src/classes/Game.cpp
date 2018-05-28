/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Game.hpp"

Eo::Game::Game(Eo::Device &device, const std::string &mapPath)
	: AGame(device), _json(mapPath),
	  _map(_json.readMatrix("map").size(),
		  _json.readMatrix("map").at(0).size()), _camera(this)
{
}

Eo::Game::~Game()
{
}

irr::scene::ICameraSceneNode *Eo::Game::getCamera() const
{
	return _camera.getCameraHandle();
}
