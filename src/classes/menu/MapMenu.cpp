/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** MapMenu.cpp
*/

#include <algorithm>
#include "MapMenu.hpp"
#include <iostream>
#include <filesystem>
#include "menu/MainMenu.hpp"

Eo::MapMenu::MapMenu(Eo::Rc<Eo::Event> event, Eo::Rc<Eo::Device> device,
	Eo::Rc<Eo::SceneHandler> sceneHandler, Eo::Rc<Eo::SoundDevice> sound
)
	: AScene(event, device, sceneHandler, sound)
{
}

Eo::MapMenu::~MapMenu()
{
}

bool Eo::MapMenu::draw()
{
	irr::gui::IGUIEnvironment *env = _device->getDevice()->getGUIEnvironment();
	irr::gui::IGUISkin *skin = env->getSkin();
	irr::gui::IGUIFont *font = env->getFont((currPath +
		"assets/font/fonthaettenschweiler.bmp").c_str());
	if (font) {
		skin->setFont(font);
	}
	this->putBackgroundImage();
	this->putLoadButton();
	this->putReturnButton();
	this->putTitle();
	skin->setFont(env->getBuiltInFont(), irr::gui::EGDF_TOOLTIP);
	return true;
}

void Eo::MapMenu::putBackgroundImage()
{
	irr::gui::IGUIEnvironment *env = this->_device->getDevice()
		->getGUIEnvironment();
	env->addImage(this->_device->getDriver()->getTexture(
		(currPath + "assets/img/menu-background.jpg").c_str()),
		{0, 0});
}

void Eo::MapMenu::putLoadButton()
{
	auto *env = this->_device->getDevice()->getGUIEnvironment();
	auto windowSize = this->_device->getOptions()->getWindowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;
	auto pos = 3;
	auto listbox = env->addListBox(
		{(int)(w / 6), (int)((h / 8) * (pos + 1)),
			(int)(w / 6 + 2 * w / 3),
			(int)((h / 8) * (pos + 1) + h / 8 * 2)}, 0, 1337);
	listbox->setDrawBackground(true);
	std::string path = currPath + "assets/maps/";
	for (auto &p : std::filesystem::directory_iterator(path)) {
		std::wstring tmp = p.path().filename().wstring();
		tmp = tmp.substr(0, tmp.size() - 5);
		listbox->addItem(tmp.c_str());
	}
	env->addButton(
		{(int)(w / 6), (int)((h / 8) * pos), (int)(w / 6 + 2 * w / 3),
			(int)((h / 8) * pos + h / 8)}, nullptr,
		Eo::MapMenu::ButtonType::Load, L"Load Map", L"Load Map");
}

void Eo::MapMenu::putReturnButton()
{
	auto *env = _device->getDevice()->getGUIEnvironment();
	auto windowSize = _device->getOptions()->getWindowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;
	env->addButton({(int)(w / 24), (int)((h / 24)), (int)(3 * w / 24),
			(int)((h / 24) + h / 12)}, nullptr,
		Eo::MapMenu::ButtonType::Return, L"Return",
		L"Return to main menu");
}

void Eo::MapMenu::putTitle()
{
	auto *env = _device->getDevice()->getGUIEnvironment();
	auto windowSize = _device->getOptions()->getWindowSize();
	auto w = windowSize.Width;
	auto *image = _device->getDriver()->getTexture(
		"assets/img/bomberman-title.png");
	env->addImage(image, {(int)(w / 2 - 400), 0}, true);
}
