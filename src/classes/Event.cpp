/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include <iostream>
#include "Event.hpp"

bool Eo::Event::OnEvent(const irr::SEvent &event)
{
	std::map<irr::EKEY_CODE, std::function<void (
		const irr::SEvent &)>> _keyHandler = {
		{
			_options.getKeyExit(),
			[this] (const irr::SEvent &event) {
				keyExit();
			}
		},
		{
			_options.getKeyDebugMode(),
			[this] (const irr::SEvent &event) {
				keyDebugToggle(event);
			}
		}
	};
	try {
		if(event.EventType == irr::EET_KEY_INPUT_EVENT)
			_keyHandler.at(event.KeyInput.Key)(event);
		else
			return false;
	} catch (const std::exception &execption) {
		return false;
	}
	return true;
}

Eo::Event::Event(Eo::Options &options, Eo::Device &device) :
	_options(options),
	_device(device)
{
}

void Eo::Event::keyExit()
{
		_options.setExit(true);
}

void Eo::Event::keyDebugToggle(const irr::SEvent &event)
{
	if (event.KeyInput.PressedDown) {
		_options.isDebugMode() ?
			_options.setDebugMode(false) :
			_options.setDebugMode(true);
		if (!_options.isDebugMode())
			_device.setDeviceTitle(L"Eo Bombermanz");
	}
}

