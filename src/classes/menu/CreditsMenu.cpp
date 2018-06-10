/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** CreditsMenu.cpp
*/

#include "CreditsMenu.hpp"
#include "SettingsMenu.hpp"
#include "SceneHandler.hpp"

Eo::CreditsMenu::CreditsMenu(Eo::Rc<Eo::Event> event, Eo::Rc<Eo::Device> device, Eo::Rc<Eo::SceneHandler> sceneHandler, Eo::Rc<Eo::SoundDevice> sound)
	: AScene(event, device, sceneHandler, sound)
{
	this->addEvents(event);
	this->draw();
}

Eo::CreditsMenu::~CreditsMenu()
{
}

bool Eo::CreditsMenu::draw()
{
	irr::gui::IGUIEnvironment *env =
		this->_device->getDevice()->getGUIEnvironment();
	irr::gui::IGUISkin *skin = env->getSkin();
	irr::gui::IGUIFont *font =
		env->getFont("../assets/font/fonthaettenschweiler.bmp");
	if (font)
		skin->setFont(font);
	this->putBackgroundImage();
	this->putCredits();
	this->putReturnButton();
	skin->setFont(env->getBuiltInFont(), irr::gui::EGDF_TOOLTIP);
	return true;
}

void Eo::CreditsMenu::putBackgroundImage()
{
	irr::gui::IGUIEnvironment *env =
		this->_device->getDevice()->getGUIEnvironment();
	env->addImage(this->_device->getDriver()->getTexture(
			      "../assets/img/menu-background.jpg"),
		{0, 0});
}

void Eo::CreditsMenu::putReturnButton()
{
	auto *env = this->_device->getDevice()->getGUIEnvironment();
	auto windowSize = this->_device->getOptions()->getWindowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;

	env->addButton({(int)(w / 24), (int)((h / 24)), (int)(3 * w / 24),
			       (int)((h / 24) + h / 12)},
		nullptr, Eo::CreditsMenu::ButtonType::Return, L"Return",
		L"Return to main menu");
}

void Eo::CreditsMenu::addEvents(Eo::Rc<Eo::Event> event)
{
}

void Eo::CreditsMenu::putCredits()
{
	auto *env = this->_device->getDevice()->getGUIEnvironment();
	auto windowSize = this->_device->getOptions()->getWindowSize();
	irr::s32 w = windowSize.Width;
	irr::s32 h = windowSize.Height;
	env->addImage(this->_device->getDriver()->getTexture(
		"../assets/img/credits.png"),
		{w / 2 - 512, h / 2 - 512});
}
