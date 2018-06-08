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
#include "menu/SettingsMenu.hpp"
#include "menu/PlayMenu.hpp"
#include <iostream>
#include <menu/MainMenu.hpp>

Eo::Core::~Core()
{
}

Eo::Core::Core()
	: _options(), _device(_options), _sceneHandler(_device),
	  _debug(_device, _sceneHandler), _event(), _sound()
{
	_event.addGUIHandler(
		Eo::Event::eventKey(Eo::eventType::EGET_BUTTON_CLICKED,
		                    Eo::MainMenu::ButtonType::PlayGamePlayer),
		[this](bool &toRemove, const Eo::event &event) {
			_options.setNbPlayer(1);
			_sceneHandler.loadScene(
				new Eo::Game(_event, _device, "../map2.json", _options));
		});
	_event.addGUIHandler(
		Eo::Event::eventKey(Eo::eventType::EGET_BUTTON_CLICKED,
		                    Eo::MainMenu::ButtonType::PlayGamePlayers),
		[this](bool &toRemove, const Eo::event &event) {
			_options.setNbPlayer(2);
			_sceneHandler.loadScene(
				new Eo::Game(_event, _device, "../map2.json", _options));
		});
	_event.addGUIHandler(
		Eo::Event::eventKey(Eo::eventType::EGET_BUTTON_CLICKED,
		                    Eo::MainMenu::ButtonType::Play),
		[this](bool &toRemove, const Eo::event &event) {
			_sceneHandler.loadScene(
				new Eo::PlayMenu(_event, _device));
		});
	_event.addGUIHandler(
		Eo::Event::eventKey(Eo::eventType::EGET_BUTTON_CLICKED,
			Eo::MainMenu::ButtonType::Exit),
		[this](bool &toRemove, const Eo::event &event) {
			_options.setExit(true);
		});
	_event.addGUIHandler(
		Eo::Event::eventKey(Eo::eventType::EGET_BUTTON_CLICKED,
			Eo::MainMenu::ButtonType::Settings),
		[this](bool &toRemove, const Eo::event &event) {
			_sceneHandler.loadScene(
				new Eo::SettingsMenu(_event, _device));
		});
	_event.addGUIHandler(
		Eo::Event::eventKey(Eo::eventType::EGET_BUTTON_CLICKED,
			Eo::MainMenu::ButtonType::Credits),
		[this](bool &toRemove, const Eo::event &event) {
			_sceneHandler.loadScene(
				new Eo::CreditsMenu(_event, _device));
		});
	_event.addGUIHandler(
		Eo::Event::eventKey(Eo::eventType::EGET_BUTTON_CLICKED,
			Eo::SettingsMenu::ButtonType::Return),
		[this](bool &toRemove, const Eo::event &event) {
			_sceneHandler.unloadCurrentScene();
		});
	_event.addGUIHandler(
		Eo::Event::eventKey(Eo::eventType::EGET_BUTTON_CLICKED,
			Eo::CreditsMenu::ButtonType::Return),
		[this](bool &toRemove, const Eo::event &event) {
			_sceneHandler.unloadCurrentScene();
		});
	_device.getDevice()->setResizable(false);
	_device.getDevice()->setEventReceiver(&_event);
	_sceneHandler.loadScene(new Eo::MainMenu(_event, _device));

	if (Eo::SoundDevice::_soundPath.count(Eo::SoundDevice::MENUBGM) > 0)
		_sound.play(Eo::SoundDevice::
		_soundPath.at(Eo::SoundDevice::MENUBGM), true);
	while (_device.getDevice()->run() && !_options.isExit()) {
		Eo::Debug debug(_device, _sceneHandler);
		auto scene = _sceneHandler.getCurrentScene();
		if (_options.isDebugMode())
			_debug.dumpDebug(scene);
		_device.getDriver()->beginScene();
		scene->update();
		scene->getSceneManager()->drawAll();
		_device.getDevice()->getGUIEnvironment()->drawAll();
		_device.getDriver()->endScene();
	}
	_device.getDevice()->drop();
}
