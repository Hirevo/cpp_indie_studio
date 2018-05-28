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

Eo::Core::Core()
	: _options(),
	  _device(_options),
	  _scene(_device),
	  _camera(_scene),
	  _debug(_device, _scene),
	  _debugMode(false)
{

	_scene.addMapBlock(0, 5, 20);
	_scene.addMapBlock(0, 5, 30);
	_scene.addMapBlock(0, 5, 40);
	_scene.addMapBlock(0, 5, 50);
	_scene.addMapBlock(0, 5, 60);
	_scene.addMapBlock(10, 5, 40);
	_scene.addMapBlock(-10, 5, 40);
	_scene.addMapBlock(20, 5, 40);
	_scene.addMapBlock(-20, 5, 40);
	_scene.addMapBlock(-20, 5, 50);
	_scene.addMapBlock(-20, 5, 60);
	_scene.addMapBlock(20, 5, 30);
	_scene.addMapBlock(20, 5, 20);
	_scene.addMapBlock(-10, 5, 20);
	_scene.addMapBlock(-20, 5, 20);
	_scene.addMapBlock(10, 5, 60);
	_scene.addMapBlock(20, 5, 60);
	_scene.addMapFloor();
	_device.get_device()->getCursorControl()->setVisible(false);

	_debugMode = true;

	irr::video::SColor color(255, 255, 2, 255);
	while (_device.get_device()->run()) {
		_device.get_driver()->beginScene(true, true, color);
		if (_debugMode)
			_debug.dumpDebug();
		_scene.get_sceneManager()->drawAll();
		_device.get_driver()->endScene();
	}
	_device.get_device()->drop();
}
