/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** SceneHandler.cpp
*/

#include <iostream>
#include "SceneHandler.hpp"
#include "Game.hpp"
#include "Types.hpp"

Eo::SceneHandler::SceneHandler(Eo::Rc<Eo::Device> device)
{
}

Eo::SceneHandler::~SceneHandler()
{
	while (!_scenes.empty())
		_scenes.pop();
}

Eo::Rc<Eo::IScene> Eo::SceneHandler::getCurrentScene() const
{
	return !_scenes.empty() ? _scenes.top() : Eo::Rc<Eo::IScene>(nullptr);
}

bool Eo::SceneHandler::loadScene(Eo::Rc<Eo::IScene> scene)
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
	scn = this->getCurrentScene();
	if (scn.get())
		scn->draw();
	return true;
}

std::size_t Eo::SceneHandler::getSceneCount() const
{
	return this->_scenes.size();
}
