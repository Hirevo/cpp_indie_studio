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
	return _scenes.size() ? _scenes.top() : 0;
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
