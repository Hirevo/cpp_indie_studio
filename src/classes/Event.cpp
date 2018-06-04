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

static const std::map<std::pair<Eo::eventType, irr::s32>, Eo::eventHandler>
	events = {{{Eo::eventType::EGET_BUTTON_CLICKED,
			   Eo::MainMenu::ButtonType::Play},
			  [](Eo::Device &device, Eo::Options &options,
				  Eo::SceneHandler &sceneHandler) {
				  std::cout << sceneHandler.getSceneCount();
				  std::cout << std::endl;
				  sceneHandler.loadScene(new Eo::Game(
					  device, "../map2.json"));
				  std::cout << sceneHandler.getSceneCount()
					    << std::endl;
			  }},
		{{Eo::eventType::EGET_BUTTON_CLICKED,
			 Eo::MainMenu::ButtonType::Exit},
			[](Eo::Device &device, Eo::Options &options,
				Eo::SceneHandler &sceneHandler) {
				options.setExit(true);
			}},
		{{Eo::eventType::EGET_BUTTON_CLICKED, Eo::MainMenu::Settings},
			[](Eo::Device &device, Eo::Options &options,
				Eo::SceneHandler &sceneHandler) {
				sceneHandler.loadScene(
					new Eo::SettingsMenu(device));
			}},
		  {{Eo::eventType::EGET_BUTTON_CLICKED,
			   Eo::SettingsMenu::ButtonType::Return},
			  [](Eo::Device &device, Eo::Options &options,
				  Eo::SceneHandler &sceneHandler) {
				  sceneHandler.unloadCurrentScene();
			  }},};

Eo::Event::Event(Eo::Options &options, Eo::Device &device,
	Eo::SceneHandler &sceneHandler)
	: _options(options), _device(device), _sceneHandler(sceneHandler)
{
}

bool Eo::Event::OnEvent(const Eo::event &event)
{
	// std::map<Eo::keyCode, void (*)(const Eo::event &)> keyHandler{
	// 	{_options.getKeyExit(), &Eo::Event::keyExit},
	// 	{_options.getKeyDebugMode(), &Eo::Event::keyDebugToggle}};

	try {
		if (event.EventType == irr::EET_KEY_INPUT_EVENT)
			Eo::Event::handleKeyEvent(event);
		else if (event.EventType == irr::EET_GUI_EVENT) {
			irr::s32 id = event.GUIEvent.Caller->getID();
			auto type = event.GUIEvent.EventType;
			auto callback = events.at(
				std::pair<Eo::eventType, irr::s32>(type, id));
			callback(_device, _options, _sceneHandler);
		}
		else
			return false;
	}
	catch (const std::exception &execption) {
		return false;
	}
	return true;
}

void Eo::Event::handleKeyEvent(const Eo::event &event)
{
	auto matches = _events.equal_range(event.KeyInput.Key);
	auto n = std::distance(matches.first, matches.second);
	if (n == 0)
		throw std::out_of_range("Event not registered.");
	std::for_each(matches.first, matches.second, [&event](auto &pair) {
		pair.second.second(pair.second.first, event);
	});
	auto it = _events.begin();
	while (it != _events.end())
		if (it->second.first)
			it = _events.erase(it);
		else
			++it;
}

void Eo::Event::addKeyHandler(
	const Eo::keyCode &code, Eo::Event::keyHandle handle)
{
	_events.emplace(code, handle);
}

void Eo::Event::clearKeyHandlers(const Eo::keyCode &code)
{
	auto it = _events.begin();
	while (it != _events.end())
		if (it->first == code)
			it = _events.erase(it);
		else
			++it;
}

// void Eo::Event::removeKeyHandler(
// 	const Eo::keyCode &code, const Eo::Event::keyHandle &handle)
// {
// 	auto it = _events.begin();
// 	while (it != _events.end())
// 		if (it->first == code && it->second == handle)
// 			it = _events.erase(it);
// 		else
// 			++it;
// }

void Eo::Event::keyExit(const Eo::event &event)
{
	static_cast<void>(event);
	_options.setExit(true);
}

void Eo::Event::keyDebugToggle(const Eo::event &event)
{
	if (event.KeyInput.PressedDown) {
		_options.setDebugMode(!_options.isDebugMode());
		if (!_options.isDebugMode())
			_device.setDeviceTitle(L"Eo Bombermanz");
	}
}
