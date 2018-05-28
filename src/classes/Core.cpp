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
	: _options(), _device(_options), _sceneHandler(_device),
	  _camera(_sceneHandler.getCurrentScene()),
	  _debug(_device, _sceneHandler.getCurrentScene()), _debugMode(false)
{
	Eo::AWall wall(Eo::AWall::INDESTRUCTIBLE);

	wall.insertInScene(_sceneHandler.getCurrentScene());
	// _sceneHandler.getCurrentScene()->addMapFloor();
	_device.getDevice()->getCursorControl()->setVisible(false);
	_debugMode = true;
	irr::video::SColor color(255, 255, 2, 255);
	float val = 0, inc = 0.03;
	while (_device.getDevice()->run()) {
		wall.setPosition(sin(val) * 50, 0, 0);
		val += inc;
		if (val >= 1)
			inc = -0.03;
		if (val <= -1)
			inc = 0.03;
		wall.updateInScene(_sceneHandler.getCurrentScene());
		_device.getDriver()->beginScene(true, true, color);
		if (_debugMode)
			_debug.dumpDebug();
		_sceneHandler.getCurrentScene()->getSceneManager()->drawAll();
		_device.getDriver()->endScene();
	}
	_device.getDevice()->drop();
}
