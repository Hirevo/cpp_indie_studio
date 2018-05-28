/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "AGame.hpp"

Eo::AGame::AGame(Eo::Device &device) : _device(device)
{
	_sceneManager = _device.getDevice()->getSceneManager();
}

Eo::AGame::~AGame()
{

}

irr::scene::ISceneManager *Eo::AGame::getSceneManager() const
{
	return _sceneManager;
}
