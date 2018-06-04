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
	this->draw();
}

Eo::MainMenu::~MainMenu()
{
}

void Eo::MainMenu::putPlayButton()
{
	auto *env = this->_device.getDevice()->getGUIEnvironment();
	auto windowSize = this->_device.getOptions().get_windowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;

	env->addButton({(int)(w / 6),
			(int)((h / 6) * 2),
			(int)(w / 6 + 2 * w / 3),
			(int)((h / 6) * 2 + h / 6)},
		nullptr,
		Eo::MainMenu::ButtonType::Play , L"Play", L"Play the game");
}

void Eo::MainMenu::putSettingsButton()
{
	auto *env = this->_device.getDevice()->getGUIEnvironment();
	auto windowSize = this->_device.getOptions().get_windowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;

	env->addButton({(int)(w / 6),
			(int)((h / 6) * 3),
			(int)(w / 6 + 2 * w / 3),
			(int)((h / 6) * 3 + h / 6)},
		nullptr,
		Eo::MainMenu::ButtonType::Settings,
		L"Settings", L"Open the settings");
}

void Eo::MainMenu::putExitButton()
{
	auto *env = this->_device.getDevice()->getGUIEnvironment();
	auto windowSize = this->_device.getOptions().get_windowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;

	env->addButton({(int)(w / 6),
			(int)((h / 6) * 4),
			(int)(w / 6 + 2 * w / 3),
			(int)((h / 6) * 4 + h / 6)},
		nullptr,
		Eo::MainMenu::ButtonType::Exit, L"Exit", L"Exit the game");
}

bool Eo::MainMenu::draw()
{
	auto *env = this->_device.getDevice()->getGUIEnvironment();
	irr::gui::IGUISkin *skin = env->getSkin();
	irr::gui::IGUIFont *font = env->getFont("../assets/font/fonthaettenschweiler.bmp");
	if (font)
		skin->setFont(font);
	this->putBackgroundImage();
	this->putPlayButton();
	this->putSettingsButton();
	this->putExitButton();
	this->putTitle();
	skin->setFont(env->getBuiltInFont(), irr::gui::EGDF_TOOLTIP);
	return true;
}

void Eo::MainMenu::putBackgroundImage()
{
	auto *env = this->_device.getDevice()->getGUIEnvironment();
	auto windowSize = this->_device.getOptions().get_windowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;
	env->addImage(this->_device.getDriver()->getTexture(
		"../assets/img/menu-background.jpg"), {0, 0});
}

void Eo::MainMenu::putTitle()
{
	auto *env = this->_device.getDevice()->getGUIEnvironment();
	auto windowSize = this->_device.getOptions().get_windowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;

	env->addStaticText(L"Bomberman 3D", {(int)(w / 6),
		(int)0,
		(int)(w / 6 + 2 * w / 3),
		(int)(h / 6)}, true);
}
