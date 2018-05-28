/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "AGame.hpp"

Eo::AGame::AGame(Eo::Device &device) : _device(device)
{
	_sceneManager = _device.get_device()->getSceneManager();
}

Eo::AGame::~AGame()
{

}

irr::scene::ISceneManager *Eo::AGame::get_sceneManager() const
{
	return _sceneManager;
}
