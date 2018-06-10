/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** GameMenu.cpp
*/

#include <iostream>
#include "GameMenu.hpp"
#include "SceneHandler.hpp"
#include "SettingsMenu.hpp"

static const irr::io::path FONT_PATH =
	(Eo::currPath + "assets/font/fonthaettenschweiler.bmp").c_str();

Eo::GameMenu::GameMenu(Eo::Rc<Eo::Event> event, Eo::Rc<Eo::Device> device,
	Eo::Rc<Eo::SceneHandler> sceneHandler, Eo::Rc<Eo::SoundDevice> sound)
	: AScene(event, device, sceneHandler, sound)
{
	this->addEvents(event);
	_sound->play(Eo::SoundDevice::PAUSE);
}

Eo::GameMenu::~GameMenu()
{
	_sound->play(Eo::SoundDevice::PAUSE);
}

bool Eo::GameMenu::draw()
{
	auto *env = _device->getDevice()->getGUIEnvironment();
	irr::gui::IGUISkin *skin = env->getSkin();
	irr::gui::IGUIFont *font = env->getFont(FONT_PATH);
	if (font)
		skin->setFont(font);
	this->putBackgroundImage();
	this->putTitle();
	this->putSettingsMenu();
	this->putResumeButton();
	this->putQuitButton();
	skin->setFont(env->getBuiltInFont(), irr::gui::EGDF_TOOLTIP);
	return true;
}

void Eo::GameMenu::putBackgroundImage()
{
	auto *env = _device->getDevice()->getGUIEnvironment();
	env->addImage(_device->getDriver()->getTexture(
		(currPath + "assets/img/menu-background.jpg").c_str()),
		{0, 0});
}

void Eo::GameMenu::putResumeButton()
{
	auto *env = _device->getDevice()->getGUIEnvironment();
	auto windowSize = _device->getOptions()->getWindowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;
	auto pos = 5;

	env->addButton({(int)(w / 6),
			(int)((h / 8) * pos),
			(int)(w / 6 + 2 * w / 3),
			(int)((h / 8) * pos + h / 8)},
		nullptr,
		Eo::GameMenu::EventType::Resume, L"Resume",
		L"Return to game");
}

void Eo::GameMenu::putQuitButton()
{
	auto *env = _device->getDevice()->getGUIEnvironment();
	auto windowSize = _device->getOptions()->getWindowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;
	auto pos = 6;

	env->addButton({(int)(w / 6),
			(int)((h / 8) * pos),
			(int)(w / 6 + 2 * w / 3),
			(int)((h / 8) * pos + h / 8)},
		nullptr,
		Eo::GameMenu::EventType::Quit, L"Return to main menu",
		L"Return to main menu");
}

void Eo::GameMenu::putSettingsMenu()
{
	auto *env = _device->getDevice()->getGUIEnvironment();
	auto windowSize = _device->getOptions()->getWindowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;
	auto pos = 4;

	env->addButton({(int)(w / 6),
			(int)((h / 8) * pos),
			(int)(w / 6 + 2 * w / 3),
			(int)((h / 8) * pos + h / 8)},
		nullptr,
		Eo::GameMenu::EventType::Settings, L"Settings",
		L"Open the Settings");
}

void Eo::GameMenu::addEvents(Eo::Rc<Eo::Event> event)
{
}

void Eo::GameMenu::putTitle()
{
	auto *env = this->_device->getDevice()->getGUIEnvironment();
	auto windowSize = this->_device->getOptions()->getWindowSize();
	auto w = windowSize.Width;
	auto *image = this->_device->getDriver()->getTexture(
		(Eo::currPath + "assets/img/bomberman-title.png").c_str());
	env->addImage(image, {(int)(w / 2 - 400), 0}, true)
		->setScaleImage(true);
}
