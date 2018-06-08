/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** PlayMenu.cpp
*/

#include <iostream>
#include "menu/MainMenu.hpp"
#include "PlayMenu.hpp"

Eo::PlayMenu::PlayMenu(Eo::Rc<Eo::Event> event, Eo::Rc<Eo::Device> device)
	: AScene(event, device)
{
	this->draw();
}

Eo::PlayMenu::~PlayMenu()
{
}

bool Eo::PlayMenu::draw()
{
	irr::gui::IGUIEnvironment *env =
		_device->getDevice()->getGUIEnvironment();
	irr::gui::IGUISkin *skin = env->getSkin();
	irr::gui::IGUIFont *font =
		env->getFont("../assets/font/fonthaettenschweiler.bmp");
	if (font)
		skin->setFont(font);
	this->putBackgroundImage();
	this->putPlayButton();
	this->putPlayButtonSecond();
	this->putReturnButton();
	this->putTitle();
	skin->setFont(env->getBuiltInFont(), irr::gui::EGDF_TOOLTIP);
	return true;
}

void Eo::PlayMenu::putBackgroundImage()
{
	irr::gui::IGUIEnvironment *env =
		this->_device->getDevice()->getGUIEnvironment();
	env->addImage(this->_device->getDriver()->getTexture(
		"../assets/img/menu-background.jpg"),
	              {0, 0});
}

void Eo::PlayMenu::putPlayButton()
{
	auto *env = this->_device->getDevice()->getGUIEnvironment();
	auto windowSize = this->_device->getOptions()->getWindowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;
	auto pos = 3;

	env->addButton(
		{(int)(w / 6), (int)((h / 8) * pos), (int)(w / 6 + 2 * w / 3),
		 (int)((h / 8) * pos + h / 8)},
		nullptr, Eo::MainMenu::ButtonType::PlayGamePlayer, L"1 PLayer",
		L"Play the game with one player");
}

void Eo::PlayMenu::putPlayButtonSecond()
{
	auto *env = this->_device->getDevice()->getGUIEnvironment();
	auto windowSize = this->_device->getOptions()->getWindowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;
	auto pos = 4;

	env->addButton(
		{(int)(w / 6), (int)((h / 8) * pos), (int)(w / 6 + 2 * w / 3),
		 (int)((h / 8) * pos + h / 8)},
		nullptr, Eo::MainMenu::ButtonType::PlayGamePlayers, L"2 PLayers",
		L"Play the game with two players");
}

void Eo::PlayMenu::putReturnButton()
{
	auto *env = this->_device->getDevice()->getGUIEnvironment();
	auto windowSize = this->_device->getOptions()->getWindowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;

	env->addButton({(int)(w / 24), (int)((h / 24)), (int)(3 * w / 24),
	                (int)((h / 24) + h / 12)},
	               nullptr, Eo::PlayMenu::ButtonType::Return, L"Return",
	               L"Return to main menu");
}

void Eo::PlayMenu::putTitle()
{
	auto *env = this->_device->getDevice()->getGUIEnvironment();
	auto windowSize = this->_device->getOptions()->getWindowSize();
	auto w = windowSize.Width;
	auto *image = this->_device->getDriver()->getTexture(
		"../assets/img/bomberman-title.png");
	env->addImage(image, {(int)(w / 2 - 400), 0}, true);
}
