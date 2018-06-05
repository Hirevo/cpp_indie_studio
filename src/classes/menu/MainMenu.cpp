/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** MainMenu.cpp
*/

#include "MainMenu.hpp"
#include "Event.hpp"
#include <Device.hpp>
#include <iostream>

Eo::MainMenu::MainMenu(Eo::Event &event, Eo::Device &device)
	: AScene(event, device)
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
	auto pos = 3;

	env->addButton(
		{(int)(w / 6), (int)((h / 8) * pos), (int)(w / 6 + 2 * w / 3),
			(int)((h / 8) * pos + h / 8)},
		nullptr, Eo::MainMenu::ButtonType::Play, L"Play",
		L"Play the game");
}

void Eo::MainMenu::putSettingsButton()
{
	auto *env = this->_device.getDevice()->getGUIEnvironment();
	auto windowSize = this->_device.getOptions().get_windowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;
	auto pos = 4;

	env->addButton(
		{(int)(w / 6), (int)((h / 8) * pos), (int)(w / 6 + 2 * w / 3),
			(int)((h / 8) * pos + h / 8)},
		nullptr, Eo::MainMenu::ButtonType::Settings, L"Settings",
		L"Open the settings");
}

void Eo::MainMenu::putCreditsButton()
{
	auto *env = this->_device.getDevice()->getGUIEnvironment();
	auto windowSize = this->_device.getOptions().get_windowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;
	auto pos = 5;

	env->addButton(
		{(int)(w / 6), (int)((h / 8) * pos), (int)(w / 6 + 2 * w / 3),
			(int)((h / 8) * pos + h / 8)},
		nullptr, Eo::MainMenu::ButtonType::Credits, L"Credits",
		L"Show the credits");
}

void Eo::MainMenu::putExitButton()
{
	auto *env = this->_device.getDevice()->getGUIEnvironment();
	auto windowSize = this->_device.getOptions().get_windowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;
	auto pos = 6;

	env->addButton(
		{(int)(w / 6), (int)((h / 8) * pos), (int)(w / 6 + 2 * w / 3),
			(int)((h / 8) * pos + h / 8)},
		nullptr, Eo::MainMenu::ButtonType::Exit, L"Exit",
		L"Exit the game");
}

static const irr::io::path FONT_PATH =
	"../assets/font/fonthaettenschweiler.bmp";

bool Eo::MainMenu::draw()
{
	auto *env = this->_device.getDevice()->getGUIEnvironment();
	irr::gui::IGUISkin *skin = env->getSkin();
	irr::gui::IGUIFont *font = env->getFont(FONT_PATH);
	if (font)
		skin->setFont(font);
	this->putBackgroundImage();
	this->putTitle();
	this->putPlayButton();
	this->putSettingsButton();
	this->putCreditsButton();
	this->putExitButton();
	skin->setFont(env->getBuiltInFont(), irr::gui::EGDF_TOOLTIP);
	return true;
}

void Eo::MainMenu::putBackgroundImage()
{
	auto *env = this->_device.getDevice()->getGUIEnvironment();
	env->addImage(this->_device.getDriver()->getTexture(
			      "../assets/img/menu-background.jpg"),
		{0, 0});
}

void Eo::MainMenu::putTitle()
{
	auto *env = this->_device.getDevice()->getGUIEnvironment();
	auto windowSize = this->_device.getOptions().get_windowSize();
	auto w = windowSize.Width;
	auto *image = this->_device.getDriver()->getTexture(
		"../assets/img/bomberman-title.png");
	env->addImage(image, {(int)(w / 2 - 400), 0}, true);
}
