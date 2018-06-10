/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** SettingsMenu.cpp
*/

#include <iostream>
#include "SettingsMenu.hpp"
#include "SceneHandler.hpp"

Eo::SettingsMenu::SettingsMenu(Eo::Rc<Eo::Event> event,
	Eo::Rc<Eo::Device> device, Eo::Rc<Eo::SceneHandler> sceneHandler,
	Eo::Rc<Eo::SoundDevice> sound)
	: AScene(event, device, sceneHandler, sound)
{
	this->addEvents(event);
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
		(currPath + "../assets/font/fonthaettenschweiler.bmp").c_str());
	if (font)
		skin->setFont(font);
	this->putBackgroundImage();
	this->putReturnButton();
	this->putSetGeneralVolume();
	this->putSetVolumeMusic();
	this->putSetVolumeFX();
	skin->setFont(env->getBuiltInFont(), irr::gui::EGDF_TOOLTIP);
	return true;
}

void Eo::SettingsMenu::putBackgroundImage()
{
	auto *env = this->_device->getDevice()->getGUIEnvironment();
	env->addImage(this->_device->getDriver()->getTexture(
		(currPath + "../assets/img/menu-background.jpg").c_str())
		, {0, 0});
}

void Eo::SettingsMenu::putSetGeneralVolume()
{
	auto *env = this->_device->getDevice()->getGUIEnvironment();
	auto windowSize = this->_device->getOptions()->getWindowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;
	auto pos = 4;

	env->addStaticText(L"General Volume",
			{(int)(w / 6), (int)(((h / 8) * pos) / 2),
				(int)(w / 6 + 2 * w / 3),
				(int)(((h / 8) * pos + h / 8) / 2)})
		->setTextAlignment(irr::gui::EGUI_ALIGNMENT::EGUIA_CENTER,
			irr::gui::EGUI_ALIGNMENT::EGUIA_CENTER);
	env->addScrollBar(true, {(int)(w / 6), (int)(((h / 8) * pos) / 2),
			(int)(w / 6 + 2 * w / 3),
			(int)(((h / 8) * pos + h / 8) / 2)}, nullptr,
		Eo::SettingsMenu::ButtonType::SoundGeneral)->setPos(
		static_cast<irr::s32>(_sound->getGeneralVolume() * 100));
}

void Eo::SettingsMenu::putSetVolumeMusic()
{
	auto *env = this->_device->getDevice()->getGUIEnvironment();
	auto windowSize = this->_device->getOptions()->getWindowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;
	auto pos = 6;

	env->addStaticText(L"Music Volume",
			{(int)(w / 6), (int)(((h / 8) * pos) / 2),
				(int)(w / 6 + 2 * w / 3),
				(int)(((h / 8) * pos + h / 8) / 2)})
		->setTextAlignment(irr::gui::EGUI_ALIGNMENT::EGUIA_CENTER,
			irr::gui::EGUI_ALIGNMENT::EGUIA_CENTER);
	env->addScrollBar(true, {(int)(w / 6), (int)(((h / 8) * pos) / 2),
			(int)(w / 6 + 2 * w / 3),
			(int)(((h / 8) * pos + h / 8) / 2)}, nullptr,
		Eo::SettingsMenu::ButtonType::SoundMusic)->setPos(
		static_cast<irr::s32>(_sound->getMusicVolume() * 100));
}

void Eo::SettingsMenu::putSetVolumeFX()
{
	auto *env = this->_device->getDevice()->getGUIEnvironment();
	auto windowSize = this->_device->getOptions()->getWindowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;
	auto pos = 8;

	auto text = env->addStaticText(L"Effects Volume",
		{(int)(w / 6), (int)(((h / 8) * pos) / 2),
			(int)(w / 6 + 2 * w / 3),
			(int)(((h / 8) * pos + h / 8) / 2)});
	text->setTextAlignment(irr::gui::EGUI_ALIGNMENT::EGUIA_CENTER,
			irr::gui::EGUI_ALIGNMENT::EGUIA_CENTER);
	env->addScrollBar(true, {(int)(w / 6), (int)(((h / 8) * pos) / 2),
			(int)(w / 6 + 2 * w / 3),
			(int)(((h / 8) * pos + h / 8) / 2)}, nullptr,
		Eo::SettingsMenu::ButtonType::SoundFX)->setPos(
		static_cast<irr::s32>(_sound->getEffectsVolume() * 100));
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

void Eo::SettingsMenu::addEvents(Eo::Rc<Eo::Event> event)
{
}
