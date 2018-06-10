/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** EndGameMenu.cpp
*/

#include <vector>
#include <iostream>
#include "EndGameMenu.hpp"
#include "MapMenu.hpp"

static const irr::io::path FONT_PATH =
	(Eo::currPath + "../assets/font/fonthaettenschweiler.bmp").c_str();

Eo::EndGameMenu::EndGameMenu(Eo::Rc<Eo::Event> event,
	Eo::Rc<Eo::Device> device, Eo::Rc<Eo::SceneHandler> sceneHandler,
	Eo::Rc<Eo::SoundDevice> sound, std::vector<std::string> deathOrder) :
	AScene(event, device, sceneHandler, sound), _deathOrder(deathOrder)
{
	std::reverse(this->_deathOrder.begin(), this->_deathOrder.end());
	this->_sound->stopMusic();
	this->_sound->play(Eo::SoundDevice::VICTORY);
}

Eo::EndGameMenu::~EndGameMenu()
{

}

static const std::vector<Eo::color> PLAYER_COLORS = {
	{200, 239, 248, 252},
	{200, 41,  41,  41},
	{200, 75,  89,  163},
	{200, 196, 36,  31},
};

bool Eo::EndGameMenu::draw()
{
	auto *env = _device->getDevice()->getGUIEnvironment();
	irr::gui::IGUISkin *skin = env->getSkin();
	irr::gui::IGUIFont *font = env->getFont(FONT_PATH);
	auto windowSize = this->_device->getOptions()->getWindowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;

	if (font)
		skin->setFont(font);
	this->putBackgroundImage();
	this->putOkButton();
	this->putTitle();
	for (int i = 0 ; i < 4 ; ++i) {
		auto player = std::wstring(this->_deathOrder.at(i).begin(),
			this->_deathOrder.at(i).end());
		auto t = env->addStaticText(player.c_str(),
			{(int)(w / 6), (int)((h / 8) * (i + 2)),
				(int)(w / 6 + 2 * w / 3),
				(int)((h / 8) * (i + 2) + h / 8)});
		t->setTextAlignment(irr::gui::EGUI_ALIGNMENT::EGUIA_CENTER,
			irr::gui::EGUI_ALIGNMENT::EGUIA_CENTER);
		t->setBackgroundColor(PLAYER_COLORS[std::stoi(
			player.substr(player.size() - 1, player.size())) - 1]);
	}
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

void Eo::EndGameMenu::putTitle()
{
	auto *env = this->_device->getDevice()->getGUIEnvironment();
	auto windowSize = this->_device->getOptions()->getWindowSize();
	auto w = windowSize.Width;
	auto *image = this->_device->getDriver()->getTexture(
		(currPath + "../assets/img/endgame-title.png").c_str());
	env->addImage(image, {(int)(w / 2 - 512), 0}, true)
		->setScaleImage(true);
}

void Eo::EndGameMenu::putOkButton()
{
	auto *env = this->_device->getDevice()->getGUIEnvironment();
	auto windowSize = this->_device->getOptions()->getWindowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;
	auto pos = 7;

	env->addButton({(int)(w / 6),
			(int)((h / 8) * (pos - 1)),
			(int)(w / 6 + 2 * w / 3),
			(int)((h / 8) * (pos - 1) + h / 8)},
		nullptr, Eo::EndGameMenu::EventType::OK, L"OK",
		L"Return to main menu");
}
