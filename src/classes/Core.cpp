/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Core.hpp"
#include "JsonRead.hpp"
#include "Wall.hpp"
#include <iostream>

Eo::Core::~Core()
{
}

static void sampleScene(Eo::SceneHandler *sceneHandler, Eo::Device *device)
{
	auto scene = new Eo::Game(*device);
	sceneHandler->addScene(scene);
}

Eo::Core::Core()
	: _options(),
	  _device(_options),
	  _sceneHandler(_device),
	  _camera(_sceneHandler.getCurrentScene()),
	  _debugMode(false)
{
	while (_device.getDevice()->run()) {

		_sceneHandler.getCurrentScene()->getSceneManager()->drawAll();
		_device.getDriver()->endScene();
	}
	_device.getDevice()->drop();
}
