/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** MainMenu.cpp
*/

#include "MainMenu.hpp"
#include <Device.hpp>
#include <iostream>

Eo::MainMenu::MainMenu(Eo::Device &device) : AScene(device)
{
	irr::gui::IGUIEnvironment *env =
		this->_device.getDevice()->getGUIEnvironment();

	irr::gui::IGUISkin *skin = env->getSkin();
	irr::gui::IGUIFont *font = env->getFont("./fonthaettenschweiler.bmp");
	if (font)
		skin->setFont(font);
	this->putPlayButton();
	this->putSettingsButton();
	this->putExitButton();
	skin->setFont(env->getBuiltInFont(), irr::gui::EGDF_TOOLTIP);
}

Eo::MainMenu::~MainMenu()
{
}

void Eo::MainMenu::putPlayButton()
{
	irr::gui::IGUIEnvironment *env = this->_device.getDevice()->getGUIEnvironment();
	auto windowSize = this->_device.getOptions().get_windowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;

	env->addButton({(int)(w / 6),
			(int)(h / 6),
			(int)(w / 6 + 2 * w / 3),
			(int)(h / 6 + h / 6)},
		0,
		GUI_ID_MAIN_PLAY_BUTTON, L"Play", L"Play the game");
}

void Eo::MainMenu::putSettingsButton()
{
	irr::gui::IGUIEnvironment *env = this->_device.getDevice()->getGUIEnvironment();
	auto windowSize = this->_device.getOptions().get_windowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;

	env->addButton({(int)(w / 6),
			(int)((h / 6) * 2),
			(int)(w / 6 + 2 * w / 3),
			(int)((h / 6) * 2 + h / 6)},
		0,
		GUI_ID_MAIN_SETTINGS_BUTTON, L"Settings", L"Open the settings");
}

void Eo::MainMenu::putExitButton()
{
	irr::gui::IGUIEnvironment *env = this->_device.getDevice()->getGUIEnvironment();
	auto windowSize = this->_device.getOptions().get_windowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;

	env->addButton({(int)(w / 6),
			(int)((h / 6) * 3),
			(int)(w / 6 + 2 * w / 3),
			(int)((h / 6) * 3 + h / 6)},
		0,
		GUI_ID_MAIN_EXIT_BUTTON, L"Exit", L"Exit the game");
}
