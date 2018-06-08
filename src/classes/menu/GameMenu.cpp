/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** GameMenu.cpp
*/

#include "GameMenu.hpp"

static const irr::io::path FONT_PATH =
	"../assets/font/fonthaettenschweiler.bmp";

Eo::GameMenu::GameMenu(Eo::Rc<Eo::Event> event, Eo::Rc<Eo::Device> device)
	: AScene(event, device)
{
	this->draw();
}

Eo::GameMenu::~GameMenu()
{

}

bool Eo::GameMenu::draw()
{
	auto *env = _device->getDevice()->getGUIEnvironment();
	irr::gui::IGUISkin *skin = env->getSkin();
	irr::gui::IGUIFont *font = env->getFont(FONT_PATH);
	if (font)
		skin->setFont(font);
	this->putBackgroundImage();
	this->putSaveButton();
	this->putResumeButton();
	this->putQuitButton();
	skin->setFont(env->getBuiltInFont(), irr::gui::EGDF_TOOLTIP);
	return true;
}

void Eo::GameMenu::putBackgroundImage()
{
	auto *env = _device->getDevice()->getGUIEnvironment();
	env->addImage(_device->getDriver()->getTexture(
		"../assets/img/menu-background.jpg"),
		{0, 0});
}

void Eo::GameMenu::putResumeButton()
{
	auto *env = _device->getDevice()->getGUIEnvironment();
	auto windowSize = _device->getOptions()->getWindowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;
	auto pos = 5;

	env->addButton({(int)(w / 6),
			(int)((h / 8) * pos),
			(int)(w / 6 + 2 * w / 3),
			(int)((h / 8) * pos + h / 8)},
		nullptr,
		Eo::GameMenu::ButtonType::Resume, L"Resume",
		L"Return to game");
}

void Eo::GameMenu::putQuitButton()
{
	auto *env = _device->getDevice()->getGUIEnvironment();
	auto windowSize = _device->getOptions()->getWindowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;
	auto pos = 6;

	env->addButton({(int)(w / 6),
			(int)((h / 8) * pos),
			(int)(w / 6 + 2 * w / 3),
			(int)((h / 8) * pos + h / 8)},
		nullptr,
		Eo::GameMenu::ButtonType::Quit, L"Quit to main menu",
		L"Return to main menu");
}

void Eo::GameMenu::putSaveButton()
{
	auto *env = _device->getDevice()->getGUIEnvironment();
	auto windowSize = _device->getOptions()->getWindowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;
	auto pos = 4;

	env->addButton({(int)(w / 6),
			(int)((h / 8) * pos),
			(int)(w / 6 + 2 * w / 3),
			(int)((h / 8) * pos + h / 8)},
		nullptr,
		Eo::GameMenu::ButtonType::Quit, L"Save",
		L"Save the game");
}
