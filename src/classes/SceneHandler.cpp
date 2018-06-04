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

bool Eo::SceneHandler::loadScene(Eo::IScene *scene)
{
	auto scn = this->getCurrentScene();
	if (scn != nullptr)
		scn->clear();
	_scenes.push(scene);
	this->getCurrentScene()->draw();
	return true;
}

bool Eo::SceneHandler::unloadCurrentScene()
{
	auto scn = this->getCurrentScene();
	if (scn != nullptr)
		scn->clear();
	_scenes.pop();
	return true;
}

std::size_t Eo::SceneHandler::getSceneCount() const
{
	return this->_scenes.size();
}
