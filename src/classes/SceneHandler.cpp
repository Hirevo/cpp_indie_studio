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
	// auto scene = new Eo::Game(device);
	// scene->addMapBlock(0, 5, 20);
	// scene->addMapBlock(0, 5, 30);
	// scene->addMapBlock(0, 5, 40);
	// scene->addMapBlock(0, 5, 50);
	// scene->addMapBlock(0, 5, 60);
	// scene->addMapBlock(10, 5, 40);
	// scene->addMapBlock(-10, 5, 40);
	// scene->addMapBlock(20, 5, 40);
	// scene->addMapBlock(-20, 5, 40);
	// scene->addMapBlock(-20, 5, 50);
	// scene->addMapBlock(-20, 5, 60);
	// scene->addMapBlock(20, 5, 30);
	// scene->addMapBlock(20, 5, 20);
	// scene->addMapBlock(-10, 5, 20);
	// scene->addMapBlock(-20, 5, 20);
	// scene->addMapBlock(10, 5, 60);
	// scene->addMapBlock(20, 5, 60);
	// scene->addMapFloor();
	// Eo::SceneHandler::addScene(scene);
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
