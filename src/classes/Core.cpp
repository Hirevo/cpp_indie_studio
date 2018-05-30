/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Core.hpp"
#include "Game.hpp"
#include "JsonRead.hpp"
#include "Wall.hpp"
#include <iostream>
#include <menu/MainMenu.hpp>

Eo::Core::~Core()
{
}

//static void sampleScene(Eo::SceneHandler *sceneHandler, Eo::Device *device)
//{
//	Eo::Game *scene = new Eo::Game(*device, "../map.json");
//	sceneHandler->addScene(scene);
//}

Eo::Core::Core()
	: _options(),
	  _device(_options),
	  _sceneHandler(_device)
{
	_sceneHandler.addScene(new Eo::Game(_device, "../map2.json"));
	_sceneHandler.addScene(new Eo::MainMenu(_device));

	while (_device.getDevice()->run()) {
		_device.getDriver()->beginScene();
		_sceneHandler.getCurrentScene()->getSceneManager()->drawAll();
		_device.getDevice()->getGUIEnvironment()->drawAll();
		_device.getDriver()->endScene();
	}
	_device.getDevice()->drop();
}
