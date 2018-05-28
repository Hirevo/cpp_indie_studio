/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Core.hpp"
#include "JsonRead.hpp"
#include "abstract/AWall.hpp"

Eo::Core::~Core()
{
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
