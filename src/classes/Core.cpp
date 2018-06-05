/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Core.hpp"
#include "Game.hpp"
#include "JsonRead.hpp"
#include "menu/MainMenu.hpp"
#include "menu/CreditsMenu.hpp"
#include "menu/SettingsMenu.hpp"
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
	  _debug(_device, _sceneHandler),
	  _event()
{
	_event.addEventHandler(
		Eo::Event::eventKey(Eo::eventType::EGET_BUTTON_CLICKED,
			Eo::MainMenu::ButtonType::Play),
		[this](bool &toRemove, const Eo::event &event) {
			std::cout << _sceneHandler.getSceneCount();
			std::cout << std::endl;
			_sceneHandler.loadScene(new Eo::Game(
				_device, "../map2.json"));
			std::cout << _sceneHandler.getSceneCount() << std::endl;
		});
	_event.addEventHandler(
		Eo::Event::eventKey(Eo::eventType::EGET_BUTTON_CLICKED,
			Eo::MainMenu::ButtonType::Exit),
		[this](bool &toRemove, const Eo::event &event) {
			_options.setExit(true);
		});
	_event.addEventHandler(
		Eo::Event::eventKey(Eo::eventType::EGET_BUTTON_CLICKED,
			Eo::MainMenu::ButtonType::Settings),
		[this](bool &toRemove, const Eo::event &event) {
			_sceneHandler.loadScene(new Eo::SettingsMenu(_device));
		});
	_event.addEventHandler(
		Eo::Event::eventKey(Eo::eventType::EGET_BUTTON_CLICKED,
			Eo::MainMenu::ButtonType::Credits),
		[this](bool &toRemove, const Eo::event &event) {
			_sceneHandler.loadScene(new Eo::CreditsMenu(_device));
		});
	_event.addEventHandler(
		Eo::Event::eventKey(Eo::eventType::EGET_BUTTON_CLICKED,
			Eo::SettingsMenu::ButtonType::Return),
		[this](bool &toRemove, const Eo::event &event) {
			_sceneHandler.unloadCurrentScene();
		});
	_event.addEventHandler(
		Eo::Event::eventKey(Eo::eventType::EGET_BUTTON_CLICKED,
			Eo::CreditsMenu::ButtonType::Return),
		[this](bool &toRemove, const Eo::event &event) {
			_sceneHandler.unloadCurrentScene();
		});
	_device.getDevice()->setResizable(false);
	_device.getDevice()->setEventReceiver(&_event);
	_sceneHandler.loadScene(new Eo::MainMenu(_device));

	while (_device.getDevice()->run() && !_options.isExit()) {
		Eo::Debug debug(_device, _sceneHandler);
		if(_options.isDebugMode())
			_debug.dumpDebug(_sceneHandler.getCurrentScene());
		_device.getDriver()->beginScene();
		_sceneHandler.getCurrentScene()->getSceneManager()->drawAll();
		_device.getDevice()->getGUIEnvironment()->drawAll();
		_device.getDriver()->endScene();
	}
	_device.getDevice()->drop();
}
