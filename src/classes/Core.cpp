/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Core.hpp"
#include "JsonRead.hpp"

Eo::Core::~Core()
{
}

Eo::Core::Core() :
	_options(),
	_device(_options),
	_sceneHandler(_device),
	_camera(_sceneHandler.getCurrentScene()),
	_debug(_device, _sceneHandler.getCurrentScene()),
	_debugMode(false)
{
	_device.get_device()->getCursorControl()->setVisible(false);

	_debugMode = true;
	irr::video::SColor color(255, 255, 2, 255);
	while (_device.get_device()->run()) {
		_device.get_driver()->beginScene(true, true, color);
		if (_debugMode)
			_debug.dumpDebug();
		this->_sceneHandler.getCurrentScene()->get_sceneManager()->drawAll();
		_device.get_driver()->endScene();
	}
	_device.get_device()->drop();
}
