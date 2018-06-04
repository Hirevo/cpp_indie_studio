/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** SettingsMenu.cpp
*/

#include "SettingsMenu.hpp"

Eo::SettingsMenu::SettingsMenu(Eo::Device &_device) : AScene(_device)
{
	this->draw();
}

Eo::SettingsMenu::~SettingsMenu()
{

}

bool Eo::SettingsMenu::draw()
{
	irr::gui::IGUIEnvironment *env =
		this->_device.getDevice()->getGUIEnvironment();
	irr::gui::IGUISkin *skin = env->getSkin();
	irr::gui::IGUIFont *font = env->getFont("../assets/font/fonthaettenschweiler.bmp");
	if (font)
		skin->setFont(font);
	this->putBackgroundImage();
	skin->setFont(env->getBuiltInFont(), irr::gui::EGDF_TOOLTIP);
	return true;
}

void Eo::SettingsMenu::putBackgroundImage()
{
	irr::gui::IGUIEnvironment *env =
		this->_device.getDevice()->getGUIEnvironment();
	env->addImage(this->_device.getDriver()->getTexture(
		"../assets/img/menu-background.jpg"), {0, 0});
}