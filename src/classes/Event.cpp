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

Eo::Event::Event()
{
}

bool Eo::Event::OnEvent(const Eo::event &event)
{
	Eo::Event::execTasks();
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

void Eo::Event::scheduleTask(Eo::task task)
{
	_tasks.push(task);
}

void Eo::Event::clearTasks()
{
	while (_tasks.size())
		_tasks.pop();
}

void Eo::Event::execTasks()
{
	while (_tasks.size()) {
		auto f = _tasks.front();
		_tasks.pop();
		f();
	}
}
