/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** MainMenu.cpp
*/

#include <Device.hpp>
#include <iostream>
#include "MainMenu.hpp"

Eo::MainMenu::MainMenu(Eo::Device &device) : AMenu(device)
{
	this->_device.getDevice()->setResizable(true);

	irr::video::IVideoDriver* driver = this->_device.getDevice()->getVideoDriver();
	irr::gui::IGUIEnvironment* env = this->_device.getDevice()->getGUIEnvironment();

	irr::gui::IGUISkin* skin = env->getSkin();
	irr::gui::IGUIFont* font = env->getFont("./fonthaettenschweiler.bmp");
	if (font)
		skin->setFont(font);

	skin->setFont(env->getBuiltInFont(), irr::gui::EGDF_TOOLTIP);
	env->addButton({10,240,110,240 + 32}, 0, GUI_ID_QUIT_BUTTON, L"Quit", L"Exits Program");
	env->addButton({10,280,110,280 + 32}, 0, GUI_ID_NEW_WINDOW_BUTTON, L"New Window", L"Launches a new Window");
	env->addButton({10,320,110,320 + 32}, 0, GUI_ID_FILE_OPEN_BUTTON, L"File Open", L"Opens a file");
	driver->beginScene(true, true, {0,200,200,200});

	env->addStaticText(L"Transparent Control:", {150,20,350,40}, true);
	irr::gui::IGUIScrollBar* scrollbar = env->addScrollBar(true,
		{150, 45, 350, 60}, 0, GUI_ID_TRANSPARENCY_SCROLL_BAR);
	scrollbar->setMax(255);
	scrollbar->setPos(255);

	// set scrollbar position to alpha value of an arbitrary element
	scrollbar->setPos(env->getSkin()->getColor(irr::gui::EGDC_WINDOW).getAlpha());

	env->addStaticText(L"Logging ListBox:", {50,110,250,130}, true);
	irr::gui::IGUIListBox * listbox = env->addListBox({50, 140, 250, 210});
	env->addEditBox(L"Editable Text", {350, 80, 550, 100});
	env->addImage(driver->getTexture("./irrlichtlogo2.png"), {10,10});
	device.getDevice()->run();
}

Eo::MainMenu::~MainMenu()
{

}
