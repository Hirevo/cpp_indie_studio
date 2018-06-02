/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Event.hpp"
#include <iostream>
#include <menu/MainMenu.hpp>

static const std::map<irr::gui::EGUI_EVENT_TYPE, std::map<irr::s32,
	std::function<void(const irr::SEvent &, Eo::Options &)>>> GUI_EVENTS =
	{
		{
			irr::gui::EGUI_EVENT_TYPE::EGET_BUTTON_CLICKED,
			{
				{
					Eo::MainMenu::GUI_ID_MAIN_PLAY_BUTTON,
					[](const irr::SEvent &event,
						Eo::Options &options) {
						std::cout << "YOU CLICKED PLAY"
							<< std::endl;
					}
				},
				{
					Eo::MainMenu::GUI_ID_MAIN_EXIT_BUTTON,
					[](const irr::SEvent &event,
						Eo::Options &options) {
						options.setExit(true);
					}
				}
			}
		}
	};

bool Eo::Event::OnEvent(const irr::SEvent &event)
{
	std::map<irr::EKEY_CODE, void (Eo::Event::*)(const irr::SEvent &)>
		keyHandler = {{_options.getKeyExit(),      &Eo::Event::keyExit},
			      {_options.getKeyDebugMode(), &Eo::Event::keyDebugToggle}};

	try {
		if (event.EventType == irr::EET_KEY_INPUT_EVENT)
			(this->*keyHandler.at(event.KeyInput.Key))(event);
		else if (event.EventType == irr::EET_GUI_EVENT) {
			irr::s32 id = event.GUIEvent.Caller->getID();
			auto type = event.GUIEvent.EventType;
			GUI_EVENTS.at(type).at(id)(event, this->_options);
		} else
			return false;
	}
	catch (const std::exception &execption) {
		// std::cout << execption.what() << std::endl;
		return false;
	}
	return true;
}

Eo::Event::Event(Eo::Options &options, Eo::Device &device)
	: _options(options), _device(device)
{
}

void Eo::Event::keyExit(const irr::SEvent &event)
{
	static_cast<void>(event);
	_options.setExit(true);
}

void Eo::Event::keyDebugToggle(const irr::SEvent &event)
{
	if (event.KeyInput.PressedDown) {
		_options.isDebugMode() ? _options.setDebugMode(false) :
			_options.setDebugMode(true);
		if (!_options.isDebugMode())
			_device.setDeviceTitle(L"Eo Bombermanz");
	}
}
