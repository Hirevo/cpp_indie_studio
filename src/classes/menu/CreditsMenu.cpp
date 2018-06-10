/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** CreditsMenu.cpp
*/

#include "CreditsMenu.hpp"
#include "SettingsMenu.hpp"
#include "SceneHandler.hpp"

Eo::CreditsMenu::CreditsMenu(Eo::Rc<Eo::Event> event,
	Eo::Rc<Eo::Device> device, Eo::Rc<Eo::SceneHandler> sceneHandler,
	Eo::Rc<Eo::SoundDevice> sound)
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
		env->getFont((currPath + "../assets/font/fonthaettenschweiler.bmp").c_str());
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
		(currPath + "../assets/img/menu-background.jpg").c_str()),
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
	auto image = env->addImage(this->_device->getDriver()->getTexture(
		(currPath + "../assets/img/credits.png").c_str()),
		{0, 0});

	image->setMaxSize({static_cast<const u32 &>(w),
		static_cast<const u32 &>(h)});
	image->setAlignment(irr::gui::EGUI_ALIGNMENT::EGUIA_CENTER,
		irr::gui::EGUI_ALIGNMENT::EGUIA_CENTER,
		irr::gui::EGUI_ALIGNMENT::EGUIA_CENTER,
		irr::gui::EGUI_ALIGNMENT::EGUIA_CENTER);
	image->setScaleImage(true);
}
