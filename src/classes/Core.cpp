/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Core.hpp"
#include "Floor.hpp"
#include "Wall.hpp"
#include "menu/CreditsMenu.hpp"
#include "menu/MainMenu.hpp"
#include "menu/PlayMenu.hpp"
#include "menu/SettingsMenu.hpp"
#include <iostream>
#include <menu/MainMenu.hpp>

Eo::Core::Core(Eo::Rc<Eo::Options> options, Eo::Rc<Eo::Device> device)
	: _options(options), _device(device),
	_sceneHandler(Eo::initRc<Eo::SceneHandler>(_device)),
	_debug(Eo::initRc<Eo::Debug>(_device, _sceneHandler)),
	_event(Eo::initRc<Eo::Event>()), _sound(Eo::initRc<Eo::SoundDevice>())
{
	_device->getDevice()->setResizable(false);
	_device->getDevice()->setEventReceiver(_event.get());
	_sceneHandler->loadScene(
		Eo::initRc<Eo::MainMenu>(_event, _device, _sceneHandler,
			_sound));

	while (_device->getDevice()->run() && !_options->isExit()) {
		Eo::Debug debug(_device, _sceneHandler);
		auto scene = _sceneHandler->getCurrentScene();
		if (_options->isDebugMode())
			_debug->dumpDebug(scene);
		_device->getDriver()->beginScene();
		scene->update();
		scene->getSceneManager()->drawAll();
		_device->getDevice()->getGUIEnvironment()->drawAll();
		_device->getDriver()->endScene();
	}
	while (_sceneHandler->getSceneCount())
		_sceneHandler->unloadCurrentScene();
	_device->getDevice()->drop();
	_sound->deleteSoundDevice();
}

Eo::Core::~Core() = default;
