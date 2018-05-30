/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** SceneHandler.cpp
*/

#include "SceneHandler.hpp"
#include "Game.hpp"

Eo::SceneHandler::SceneHandler(Eo::Device &device)
{
}

Eo::SceneHandler::~SceneHandler()
{
	while (!_scenes.empty())
		_scenes.pop();
}

Eo::IScene *Eo::SceneHandler::getCurrentScene() const
{
	return !_scenes.empty() ? _scenes.top() : nullptr;
}

bool Eo::SceneHandler::addScene(Eo::IScene *scene)
{
	_scenes.push(scene);
	return true;
}

bool Eo::SceneHandler::endCurrentScene()
{
	_scenes.pop();
	return true;
}
