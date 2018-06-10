/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** EndGameMenu.cpp
*/

#include "EndGameMenu.hpp"

static const irr::io::path FONT_PATH =
	(Eo::currPath + "../assets/font/fonthaettenschweiler.bmp").c_str();

Eo::EndGameMenu::EndGameMenu(Eo::Rc<Eo::Event> event,
	Eo::Rc<Eo::Device> device, Eo::Rc<Eo::SceneHandler> sceneHandler,
	Eo::Rc<Eo::SoundDevice> sound) : AScene(event, device, sceneHandler,
	sound)
{
	this->draw();
	//Todo : add the sound of victory.
}

Eo::EndGameMenu::~EndGameMenu()
{

}

bool Eo::EndGameMenu::draw()
{
	auto *env = _device->getDevice()->getGUIEnvironment();
	irr::gui::IGUISkin *skin = env->getSkin();
	irr::gui::IGUIFont *font = env->getFont(FONT_PATH);
	if (font)
		skin->setFont(font);
	this->putBackgroundImage();
	skin->setFont(env->getBuiltInFont(), irr::gui::EGDF_TOOLTIP);
	return true;
}

void Eo::EndGameMenu::putBackgroundImage()
{
	auto *env = _device->getDevice()->getGUIEnvironment();
	env->addImage(_device->getDriver()->getTexture(
		(currPath + "../assets/img/menu-background.jpg").c_str()),
		{0, 0});
}
