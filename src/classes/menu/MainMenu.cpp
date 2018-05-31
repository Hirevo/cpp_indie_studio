/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** MainMenu.cpp
*/

#include "MainMenu.hpp"
#include <Device.hpp>
#include <iostream>

Eo::MainMenu::MainMenu(Eo::Device &device) : AScene(device)
{
	irr::gui::IGUIEnvironment *env = this->_device.getDevice()->getGUIEnvironment();

	irr::video::IVideoDriver *driver =
		this->_device.getDevice()->getVideoDriver();
	irr::gui::IGUIEnvironment *env =
		this->_device.getDevice()->getGUIEnvironment();

	irr::gui::IGUISkin *skin = env->getSkin();
	irr::gui::IGUIFont *font = env->getFont("./fonthaettenschweiler.bmp");
	if (font)
		skin->setFont(font);
	this->putPlayButton();
	this->putSettingsButton();
	this->putExitButton();
	skin->setFont(env->getBuiltInFont(), irr::gui::EGDF_TOOLTIP);
	env->addButton({10, 240, 110, 240 + 32}, 0, GUI_ID_QUIT_BUTTON,
		L"Quit", L"Exits Program");
	env->addButton({10, 280, 110, 280 + 32}, 0, GUI_ID_NEW_WINDOW_BUTTON,
		L"New Window", L"Launches a new Window");
	env->addButton({10, 320, 110, 320 + 32}, 0, GUI_ID_FILE_OPEN_BUTTON,
		L"File Open", L"Opens a file");
	driver->beginScene(true, true, {0, 200, 200, 200});

	env->addStaticText(L"Transparent Control:", {150, 20, 350, 40}, true);
	irr::gui::IGUIScrollBar *scrollbar = env->addScrollBar(
		true, {150, 45, 350, 60}, 0, GUI_ID_TRANSPARENCY_SCROLL_BAR);
	scrollbar->setMax(255);
	scrollbar->setPos(255);

	scrollbar->setPos(
		env->getSkin()->getColor(irr::gui::EGDC_WINDOW).getAlpha());

	env->addStaticText(L"Logging ListBox:", {50, 110, 250, 130}, true);
	irr::gui::IGUIListBox *listbox = env->addListBox({50, 140, 250, 210});
	env->addEditBox(L"Editable Text", {350, 80, 550, 100});
	env->addImage(driver->getTexture("./irrlichtlogo2.png"), {10, 10});
	device.getDevice()->run();
}

Eo::MainMenu::~MainMenu()
{
}

void Eo::MainMenu::putPlayButton()
{
	irr::gui::IGUIEnvironment *env = this->_device.getDevice()->getGUIEnvironment();
	auto windowSize = this->_device.getOptions().get_windowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;

	env->addButton({(int)(w / 6),
			(int)(h / 6),
			(int)(w / 6 + 2 * w / 3),
			(int)(h / 6 + h / 6)},
		0,
		GUI_ID_MAIN_PLAY_BUTTON, L"Play", L"Play the game");
}

void Eo::MainMenu::putSettingsButton()
{
	irr::gui::IGUIEnvironment *env = this->_device.getDevice()->getGUIEnvironment();
	auto windowSize = this->_device.getOptions().get_windowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;

	env->addButton({(int)(w / 6),
			(int)((h / 6) * 2),
			(int)(w / 6 + 2 * w / 3),
			(int)((h / 6) * 2 + h / 6)},
		0,
		GUI_ID_MAIN_SETTINGS_BUTTON, L"Settings", L"Open the settings");
}

void Eo::MainMenu::putExitButton()
{
	irr::gui::IGUIEnvironment *env = this->_device.getDevice()->getGUIEnvironment();
	auto windowSize = this->_device.getOptions().get_windowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;

	env->addButton({(int)(w / 6),
			(int)((h / 6) * 3),
			(int)(w / 6 + 2 * w / 3),
			(int)((h / 6) * 3 + h / 6)},
		0,
		GUI_ID_MAIN_EXIT_BUTTON, L"Exit", L"Exit the game");
}
