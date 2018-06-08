/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** SettingsMenu.cpp
*/

#include "SettingsMenu.hpp"

Eo::SettingsMenu::SettingsMenu(Eo::Rc<Eo::Event> event, Eo::Rc<Eo::Device> device) : AScene(event, device)
{
	this->draw();
}

Eo::SettingsMenu::~SettingsMenu()
{

}

bool Eo::SettingsMenu::draw()
{
	irr::gui::IGUIEnvironment *env =
		this->_device->getDevice()->getGUIEnvironment();
	irr::gui::IGUISkin *skin = env->getSkin();
	irr::gui::IGUIFont *font = env->getFont(
		"../assets/font/fonthaettenschweiler.bmp");
	if (font)
		skin->setFont(font);
	this->putBackgroundImage();
	this->putReturnButton();
	skin->setFont(env->getBuiltInFont(), irr::gui::EGDF_TOOLTIP);
	return true;
}

void Eo::SettingsMenu::putBackgroundImage()
{
	irr::gui::IGUIEnvironment *env =
		this->_device->getDevice()->getGUIEnvironment();
	env->addImage(this->_device->getDriver()->getTexture(
		"../assets/img/menu-background.jpg"), {0, 0});
}

void Eo::SettingsMenu::putReturnButton()
{
	auto *env = this->_device->getDevice()->getGUIEnvironment();
	auto windowSize = this->_device->getOptions()->getWindowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;

	env->addButton({(int)(w / 24),
			(int)((h / 24)),
			(int)(3 * w / 24),
			(int)((h / 24) + h / 12)},
		nullptr,
		Eo::SettingsMenu::ButtonType::Return, L"Return",
		L"Return to main menu");
}