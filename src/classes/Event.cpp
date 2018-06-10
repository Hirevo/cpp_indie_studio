/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Event.hpp"
#include "Game.hpp"
#include "Types.hpp"
#include <algorithm>
#include <iostream>
#include <map>
#include <menu/MainMenu.hpp>
#include <menu/SettingsMenu.hpp>
#include <menu/CreditsMenu.hpp>

// static const std::map<std::pair<Eo::eventType, irr::s32>, Eo::eventHandler>
// 	events = {{{Eo::eventType::EGET_BUTTON_CLICKED,
// 			Eo::MainMenu::EventType::Play},
			//   [](Eo::Device &device, Eo::Options &options,
			// 	  Eo::SceneHandler &sceneHandler) {
			// 	  std::cout << sceneHandler.getSceneCount();
			// 	  std::cout << std::endl;
			// 	  sceneHandler.loadScene(new Eo::Game(
			// 		  device, "../map3.json"));
			// 	  std::cout << sceneHandler.getSceneCount()
			// 		  << std::endl;
			//   }},
// 		  {{Eo::eventType::EGET_BUTTON_CLICKED,
// 			Eo::MainMenu::EventType::Exit},
// 			  [](Eo::Device &device, Eo::Options &options,
// 				  Eo::SceneHandler &sceneHandler) {
// 				  options.setExit(true);
// 			  }},
// 		  {{Eo::eventType::EGET_BUTTON_CLICKED,
// 			Eo::MainMenu::EventType::Credits},
			//   [](Eo::Device &device, Eo::Options &options,
			// 	  Eo::SceneHandler &sceneHandler) {
			// 	  sceneHandler.loadScene(
			// 		  new Eo::CreditsMenu(device));
			//   }},
// 		  {{Eo::eventType::EGET_BUTTON_CLICKED, Eo::MainMenu::Settings},
			//   [](Eo::Device &device, Eo::Options &options,
			// 	  Eo::SceneHandler &sceneHandler) {
			// 	  sceneHandler.loadScene(
			// 		   new Eo::SettingsMenu(device));
			//   }},
// 		  {{Eo::eventType::EGET_BUTTON_CLICKED,
// 			   Eo::SettingsMenu::EventType::Return},
			//   [](Eo::Device &device, Eo::Options &options,
			// 	  Eo::SceneHandler &sceneHandler) {
			// 	  sceneHandler.unloadCurrentScene();
			//   }},
// 		  {{Eo::eventType::EGET_BUTTON_CLICKED,
// 			   Eo::CreditsMenu::EventType::Return},
// 			  [](Eo::Device &device, Eo::Options &options,
// 				  Eo::SceneHandler &sceneHandler) {
// 				  sceneHandler.unloadCurrentScene();
// 			  }}};

Eo::Event::Event()
{
}

bool Eo::Event::OnEvent(const Eo::event &event)
{
	// Todo For polo memories
	// std::map<Eo::keyCode, void (*)(const Eo::event &)> keyHandler{
	// 	{_options.getKeyExit(), &Eo::Event::keyExit},
	// 	{_options.getKeyDebugMode(), &Eo::Event::keyDebugToggle}};

	try {
		if (event.EventType == irr::EET_KEY_INPUT_EVENT)
			Eo::Event::handleKeyEvent(event);
		else if (event.EventType == irr::EET_GUI_EVENT)
			Eo::Event::handleEvent(event);
		else
			return false;
	}
	catch (const std::exception &exception) {
		static_cast<void>(exception);
		return false;
	}
	return true;
}

void Eo::Event::handleKeyEvent(const Eo::event &event)
{
	auto matches = _keyMap.equal_range(event.KeyInput.Key);
	auto n = std::distance(matches.first, matches.second);
	if (n == 0)
		throw std::out_of_range("Event not registered.");
	std::for_each(matches.first, matches.second, [&event](auto &pair) {
		pair.second.second(pair.second.first, event);
	});
	auto it = _keyMap.begin();
	while (it != _keyMap.end())
		if (it->second.first)
			it = _keyMap.erase(it);
		else
			++it;
}

void Eo::Event::handleEvent(const Eo::event &event)
{
	irr::s32 id = event.GUIEvent.Caller->getID();
	auto type = event.GUIEvent.EventType;
	auto key = Eo::Event::eventKey(type, id);
	auto matches = _eventMap.equal_range(key);
	auto n = std::distance(matches.first, matches.second);
	if (n == 0)
		throw std::out_of_range("Event not registered.");
	std::for_each(matches.first, matches.second, [&event](auto &pair) {
		pair.second.second(pair.second.first, event);
	});
	auto it = _eventMap.begin();
	while (it != _eventMap.end())
		if (it->second.first)
			it = _eventMap.erase(it);
		else
			++it;
}

void Eo::Event::addKeyHandler(const Eo::keyCode &code, Eo::keyHandler handle)
{
	_keyMap.emplace(code, Eo::Event::keyHandle(false, handle));
}

void Eo::Event::addGUIHandler(
	const Eo::Event::eventKey &key, Eo::eventHandler handle)
{
	_eventMap.emplace(key, Eo::Event::eventHandle(false, handle));
}

void Eo::Event::clearKeyHandlers(const Eo::keyCode &code)
{
	auto it = _keyMap.begin();
	while (it != _keyMap.end())
		if (it->first == code)
			it = _keyMap.erase(it);
		else
			++it;
}

void Eo::Event::clearEventHandlers(const Eo::Event::eventKey &key)
{
	auto it = _eventMap.begin();
	while (it != _eventMap.end())
		if (it->first == key)
			it = _eventMap.erase(it);
		else
			++it;
}

// Todo not working currently
// void Eo::Event::removeKeyHandler(
// 	const Eo::keyCode &code, const Eo::Event::keyHandle &handle)
// {
// 	auto it = _keyMap.begin();
// 	while (it != _keyMap.end())
// 		if (it->first == code && it->second == handle)
// 			it = _keyMap.erase(it);
// 		else
// 			++it;
// }

// void Eo::Event::keyExit(const Eo::event &event)
// {
// 	static_cast<void>(event);
// 	_options.setExit(true);
// }

// void Eo::Event::keyDebugToggle(const Eo::event &event)
// {
// 	if (event.KeyInput.PressedDown) {
// 		_options.isDebugMode() ?
// 			_options.setDebugMode(false) :
// 			_options.setDebugMode(true);
// 		if (!_options.isDebugMode()) {
// 			_device.setDeviceTitle(L"Eo Bombermanz");
// 			_debug.clearDebugList(_device.getDevice()->getSceneManager());
// 		}
// 	}
// }
