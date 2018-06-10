/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** MapMenu.cpp
*/

#include <algorithm>
#include "MapMenu.hpp"
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#include <tchar.h>
#elif __linux__
#include <dirent.h>
#endif
#include "menu/MainMenu.hpp"

Eo::MapMenu::MapMenu(Eo::Rc<Eo::Event> event, Eo::Rc<Eo::Device> device, Eo::Rc<Eo::SceneHandler> sceneHandler, Eo::Rc<Eo::SoundDevice> sound)
	: AScene(event, device, sceneHandler, sound)
{
	this->draw();
}

Eo::MapMenu::~MapMenu()
{
}

bool Eo::MapMenu::draw()
{
	irr::gui::IGUIEnvironment *env =
		_device->getDevice()->getGUIEnvironment();
	irr::gui::IGUISkin *skin = env->getSkin();
	irr::gui::IGUIFont *font =
		env->getFont((currPath +
		"../assets/font/fonthaettenschweiler.bmp").c_str());
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
	irr::gui::IGUIEnvironment *env =
		this->_device->getDevice()->getGUIEnvironment();
	env->addImage(this->_device->getDriver()->getTexture(
		"../assets/img/menu-background.jpg"),
	              {0, 0});
}

static int mapfilter(const struct dirent *dir)
{
	const char *s = dir->d_name;
	int len = strlen(s);
	if(len >= 0)
	{
		if (strncmp(s, "map", 3) == 0)
			return 1;
		else if (strcmp(s, "save.json") == 0)
			return 1;
	}
	return 0;
}

void Eo::MapMenu::putLoadButton()
{
	auto *env = this->_device->getDevice()->getGUIEnvironment();
	auto windowSize = this->_device->getOptions()->getWindowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;
	auto pos = 5;
	auto listbox = env->addListBox({(int)(w / 6),
		(int)((h / 8) * pos), (int)(w / 6 + 2 * w / 3),
	        (int)((h / 8) * pos + h / 8)});
	listbox->setDrawBackground(true);
	std::string path = currPath + "../assets/maps/";
#ifdef _WIN32
	WIN32_FIND_DATA data;
	HANDLE handle = FindFirstFile(LPCWSTR(path.c_str()), &data);
	do {
		auto name = data.cFileName;
		std::cout << name << std::endl;
		std::string tmp = name;
		tmp = tmp.substr(0, tmp.size() - 5);
		std::wstring text(tmp.begin(), tmp.end());
		listbox->addItem(text.c_str());
	} while (FindNextFile(handle, &data));
	FindClose(handle);
#elif __linux__
	struct dirent **fileListTemp;
	int nb = scandir(path.c_str(), &fileListTemp, mapfilter, alphasort);
	for(int i = 0; i < nb; i++) {
		if (fileListTemp[i]->d_type != DT_REG)
			continue;
		std::cout << fileListTemp[i]->d_name << std::endl;
		std::string tmp = fileListTemp[i]->d_name;
		tmp = tmp.substr(0, tmp.size() - 5);
		std::wstring text(tmp.begin(), tmp.end());
		listbox->addItem(text.c_str());
	}
#endif
	pos = 4;
	env->addButton(
		{(int)(w / 6), (int)((h / 8) * pos), (int)(w / 6 + 2 * w / 3),
		 (int)((h / 8) * pos + h / 8)},
		nullptr, Eo::MapMenu::ButtonType::Load, L"Load Map",
		L"Load Map");
}

void Eo::MapMenu::putReturnButton()
{
	auto *env = _device->getDevice()->getGUIEnvironment();
	auto windowSize = _device->getOptions()->getWindowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;

	env->addButton({(int)(w / 24), (int)((h / 24)), (int)(3 * w / 24),
	                (int)((h / 24) + h / 12)},
	               nullptr, Eo::MapMenu::ButtonType::Return, L"Return",
	               L"Return to main menu");
}

void Eo::MapMenu::putTitle()
{
	auto *env = _device->getDevice()->getGUIEnvironment();
	auto windowSize = _device->getOptions()->getWindowSize();
	auto w = windowSize.Width;
	auto *image = _device->getDriver()->getTexture(
		"../assets/img/bomberman-title.png");
	env->addImage(image, {(int)(w / 2 - 400), 0}, true);
}
