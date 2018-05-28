/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Game.hpp"

Eo::Game::Game(Eo::Device &device) : AGame(device)
{
}

irr::scene::ISceneManager *Eo::Game::getSceneManager() const
{
	return _sceneManager;
}
