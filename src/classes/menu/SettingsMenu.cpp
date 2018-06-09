/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** SettingsMenu.cpp
*/

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
		"../assets/font/fonthaettenschweiler.bmp");
	if (font)
		skin->setFont(font);
	this->putBackgroundImage();
	this->putReturnButton();
	this->putSetVolumeSound();
	this->putSetVolumeSoundMus();
	this->putSetVolumeSoundEffect();
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

void Eo::SettingsMenu::putSetVolumeSound()
{
	auto *env = this->_device->getDevice()->getGUIEnvironment();
	auto windowSize = this->_device->getOptions()->getWindowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;
	auto pos = 4;

	env->addButton(
		{(int)(w / 6), (int)(((h / 8) * pos) / 2), (int)(w / 6 + 2 * w / 3),
		 (int)(((h / 8) * pos + h / 8) / 2)},
		nullptr, Eo::SettingsMenu::ButtonType::SoundMore, L"Sound +",
		L"Sound +");
	pos = 5;
	env->addButton(
		{(int)(w / 6), (int)(((h / 8) * pos) / 2), (int)(w / 6 + 2 * w / 3),
		 (int)(((h / 8) * pos + h / 8) / 2)},
		nullptr, Eo::SettingsMenu::ButtonType::SoundLess, L"Sound -",
		L"Sound -");
}

void Eo::SettingsMenu::putSetVolumeSoundMus()
{
	auto *env = this->_device->getDevice()->getGUIEnvironment();
	auto windowSize = this->_device->getOptions()->getWindowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;
	auto pos = 7;

	env->addButton(
		{(int)(w / 6), (int)(((h / 8) * pos) / 2), (int)(w / 6 + 2 * w / 3),
		 (int)(((h / 8) * pos + h / 8) / 2)},
		nullptr, Eo::SettingsMenu::ButtonType::SoundMoreMus, L"Sound Musique +",
		L"Sound +");
	pos = 8;
	env->addButton(
		{(int)(w / 6), (int)(((h / 8) * pos) / 2), (int)(w / 6 + 2 * w / 3),
		 (int)(((h / 8) * pos + h / 8) / 2)},
		nullptr, Eo::SettingsMenu::ButtonType::SoundLessMus, L"Sound Musique -",
		L"Sound -");
}

void Eo::SettingsMenu::putSetVolumeSoundEffect()
{
	auto *env = this->_device->getDevice()->getGUIEnvironment();
	auto windowSize = this->_device->getOptions()->getWindowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;
	auto pos = 10;

	env->addButton(
		{(int)(w / 6), (int)(((h / 8) * pos) / 2), (int)(w / 6 + 2 * w / 3),
		 (int)(((h / 8) * pos + h / 8) / 2)},
		nullptr, Eo::SettingsMenu::ButtonType::SoundMoreEffect, L"Sound Effect +",
		L"Sound +");
	pos = 11;
	env->addButton(
		{(int)(w / 6), (int)(((h / 8) * pos) / 2), (int)(w / 6 + 2 * w / 3),
		 (int)(((h / 8) * pos + h / 8) / 2)},
		nullptr, Eo::SettingsMenu::ButtonType::SoundLessEffect, L"Sound Effect -",
		L"Sound -");
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
