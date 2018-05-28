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

irr::scene::ISceneManager *Eo::Game::getSceneManager() const
{
	return _sceneManager;
}
