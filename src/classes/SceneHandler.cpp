/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** SceneHandler.cpp
*/

#include "SceneHandler.hpp"

SceneHandler::SceneHandler(Eo::IScene *scene)
{
	this->addScene(scene);
}

SceneHandler::~SceneHandler()
{
	while (!this->scenes.empty())
		this->scenes.pop();
}

Eo::IScene *SceneHandler::getCurrentScene()
{
	return this->scenes.top();
}

bool SceneHandler::addScene(Eo::IScene *scene)
{
	this->scenes.push(scene);
	return true;
}

bool SceneHandler::endCurrentScene()
{
	this->scenes.pop();
	return true;
}
