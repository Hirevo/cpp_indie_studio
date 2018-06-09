/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** GameMenu.cpp
*/

#include "GameMenu.hpp"
#include "SceneHandler.hpp"
#include "SettingsMenu.hpp"

static const irr::io::path FONT_PATH =
	"../assets/font/fonthaettenschweiler.bmp";

Eo::GameMenu::GameMenu(Eo::Rc<Eo::Event> event, Eo::Rc<Eo::Device> device,
	Eo::Rc<Eo::SceneHandler> sceneHandler, Eo::Rc<Eo::SoundDevice> sound)
	: AScene(event, device, sceneHandler, sound)
{
	_event->clearEventHandlers(Eo::Event::eventKey(
		Eo::eventType::EGET_BUTTON_CLICKED,
		Eo::GameMenu::ButtonType::Quit));
	// _event->clearEventHandlers(Eo::Event::eventKey(
	// 	Eo::eventType::EGET_BUTTON_CLICKED,
	// 	Eo::GameMenu::ButtonType::Save));
	_event->clearEventHandlers(Eo::Event::eventKey(
		Eo::eventType::EGET_BUTTON_CLICKED,
		Eo::GameMenu::ButtonType::Resume));
	_event->clearEventHandlers(Eo::Event::eventKey(
		Eo::eventType::EGET_BUTTON_CLICKED,
		Eo::GameMenu::ButtonType::Settings));
	this->addEvents(event);
	this->draw();
	_sound->play(Eo::SoundDevice::PAUSE);
}

Eo::GameMenu::~GameMenu()
{
	_sound->play(Eo::SoundDevice::PAUSE);
}

bool Eo::GameMenu::draw()
{
	auto *env = _device->getDevice()->getGUIEnvironment();
	irr::gui::IGUISkin *skin = env->getSkin();
	irr::gui::IGUIFont *font = env->getFont(FONT_PATH);
	if (font)
		skin->setFont(font);
	this->putBackgroundImage();
	this->putSettingsMenu();
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

void Eo::GameMenu::putSettingsMenu()
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
		Eo::GameMenu::ButtonType::Settings, L"Settings",
		L"Open the Settings");
}

void Eo::GameMenu::addEvents(Eo::Rc<Eo::Event> event)
{
	event->addGUIHandler(
		Eo::Event::eventKey(Eo::eventType::EGET_BUTTON_CLICKED,
			Eo::GameMenu::ButtonType::Quit),
		[this](bool &toRemove, const Eo::event &event) {
			_sound->stopMusic();
			_sound->play(Eo::SoundDevice::MENUBGM, true);
			this->_sceneHandler->unloadCurrentScene();
			this->_sceneHandler->unloadCurrentScene();
			this->_sceneHandler->unloadCurrentScene();
		});
	event->addGUIHandler(
		Eo::Event::eventKey(Eo::eventType::EGET_BUTTON_CLICKED,
			Eo::GameMenu::ButtonType::Resume),
		[this](bool &toRemove, const Eo::event &event) {
			this->_sceneHandler->unloadCurrentScene();
		});
	event->addGUIHandler(
		Eo::Event::eventKey(Eo::eventType::EGET_BUTTON_CLICKED,
			Eo::GameMenu::ButtonType::Settings),
		[this](bool &toRemove, const Eo::event &event) {
			this->_sceneHandler->loadScene(
				Eo::initRc<Eo::SettingsMenu>(_event, _device,
					_sceneHandler, _sound));
		});
}
