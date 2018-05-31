/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include <iostream>
#include "EventGame.hpp"

bool Eo::EventGame::OnEvent(const irr::SEvent &event)
{
	std::map<irr::EKEY_CODE, std::function<void (
		const irr::SEvent &)>> _keyHandler = {
		{
			_options.getKeyExit(),
			[this] (const irr::SEvent &event) {
				_options.setExit(true);
			}
		},
		{
			_options.getKeyDebugMode(),
			[this] (const irr::SEvent &event) {
				_options.isDebugMode() ?
					_options.setDebugMode(false) :
					_options.setDebugMode(true);

			}
		}
	};
	try {
		if(event.EventType == irr::EET_KEY_INPUT_EVENT)
			_keyHandler.at(event.KeyInput.Key)(event);
	} catch (const std::exception &execption) {

	}
	return true;
}

Eo::EventGame::EventGame(Eo::Options &options) :
	_options(options)
{
}

