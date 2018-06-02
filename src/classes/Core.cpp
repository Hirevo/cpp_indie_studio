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
#include "Floor.hpp"
#include <iostream>
#include <menu/MainMenu.hpp>

Eo::Core::~Core()
{
}

Eo::Core::Core()
	: _options(),
	  _device(_options),
	  _sceneHandler(_device),
	  _event(_options, _device)
{
	_device.getDevice()->setEventReceiver(&_event);
	_sceneHandler.addScene(new Eo::Game(_device, "../map2.json"));
	auto game = _sceneHandler.getCurrentScene();
	Eo::Debug debug(_device, game);
	_sceneHandler.addScene(new Eo::MainMenu(_device));

	while (_device.getDevice()->run() && !_options.isExit()) {
		if(_options.isDebugMode())
			debug.dumpDebug();
		_device.getDriver()->beginScene();
		_sceneHandler.getCurrentScene()->getSceneManager()->drawAll();
		_device.getDevice()->getGUIEnvironment()->drawAll();
		_device.getDriver()->endScene();
	}
	_device.getDevice()->drop();
}
