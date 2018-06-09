/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** MainMenu.cpp
*/

#include "MainMenu.hpp"
#include "Event.hpp"
#include "PlayMenu.hpp"
#include "SettingsMenu.hpp"
#include "CreditsMenu.hpp"
#include <Device.hpp>
#include <iostream>
#include <Game.hpp>
#include <SceneHandler.hpp>

Eo::MainMenu::MainMenu(Eo::Rc<Eo::Event> event, Eo::Rc<Eo::Device> device,
	Eo::Rc<Eo::SceneHandler> sceneHandler, Eo::Rc<Eo::SoundDevice> sound)
	: AScene(event, device, sceneHandler, sound)
{
	if (Eo::SoundDevice::_soundPath.count(Eo::SoundDevice::MENUBGM) > 0) {
		sound->stop();
		sound->play(Eo::SoundDevice::
		_soundPath.at(Eo::SoundDevice::MENUBGM), true);
	}
	this->addEvents(event);
	this->draw();
}

Eo::MainMenu::~MainMenu()
{
}

void Eo::MainMenu::putPlayButton()
{
	auto *env = this->_device->getDevice()->getGUIEnvironment();
	auto windowSize = this->_device->getOptions()->getWindowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;
	auto pos = 3;

	env->addButton(
		{(int)(w / 6), (int)((h / 8) * pos), (int)(w / 6 + 2 * w / 3),
			(int)((h / 8) * pos + h / 8)},
		nullptr, Eo::MainMenu::ButtonType::Play, L"Play",
		L"Play the game");
}

void Eo::MainMenu::putSettingsButton()
{
	auto *env = this->_device->getDevice()->getGUIEnvironment();
	auto windowSize = this->_device->getOptions()->getWindowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;
	auto pos = 4;

	env->addButton(
		{(int)(w / 6), (int)((h / 8) * pos), (int)(w / 6 + 2 * w / 3),
			(int)((h / 8) * pos + h / 8)},
		nullptr, Eo::MainMenu::ButtonType::Settings, L"Settings",
		L"Open the settings");
}

void Eo::MainMenu::putCreditsButton()
{
	auto *env = this->_device->getDevice()->getGUIEnvironment();
	auto windowSize = this->_device->getOptions()->getWindowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;
	auto pos = 5;

	env->addButton(
		{(int)(w / 6), (int)((h / 8) * pos), (int)(w / 6 + 2 * w / 3),
			(int)((h / 8) * pos + h / 8)},
		nullptr, Eo::MainMenu::ButtonType::Credits, L"Credits",
		L"Show the credits");
}

void Eo::MainMenu::putExitButton()
{
	auto *env = this->_device->getDevice()->getGUIEnvironment();
	auto windowSize = this->_device->getOptions()->getWindowSize();
	auto w = windowSize.Width;
	auto h = windowSize.Height;
	auto pos = 6;

	env->addButton(
		{(int)(w / 6), (int)((h / 8) * pos), (int)(w / 6 + 2 * w / 3),
			(int)((h / 8) * pos + h / 8)},
		nullptr, Eo::MainMenu::ButtonType::Exit, L"Exit",
		L"Exit the game");
}

static const irr::io::path FONT_PATH =
	"../assets/font/fonthaettenschweiler.bmp";

bool Eo::MainMenu::draw()
{
	auto *env = this->_device->getDevice()->getGUIEnvironment();
	irr::gui::IGUISkin *skin = env->getSkin();
	irr::gui::IGUIFont *font = env->getFont(FONT_PATH);
	if (font)
		skin->setFont(font);
	this->putBackgroundImage();
	this->putTitle();
	this->putPlayButton();
	this->putSettingsButton();
	this->putCreditsButton();
	this->putExitButton();
	skin->setFont(env->getBuiltInFont(), irr::gui::EGDF_TOOLTIP);
	return true;
}

void Eo::MainMenu::putBackgroundImage()
{
	auto *env = this->_device->getDevice()->getGUIEnvironment();
	env->addImage(this->_device->getDriver()->getTexture(
		"../assets/img/menu-background.jpg"),
		{0, 0});
}

void Eo::MainMenu::putTitle()
{
	auto *env = this->_device->getDevice()->getGUIEnvironment();
	auto windowSize = this->_device->getOptions()->getWindowSize();
	auto w = windowSize.Width;
	auto *image = this->_device->getDriver()->getTexture(
		"../assets/img/bomberman-title.png");
	env->addImage(image, {(int)(w / 2 - 400), 0}, true);
}

static void playButtonClickedSound(Eo::Rc<Eo::SoundDevice> sound)
{
	if (Eo::SoundDevice::_soundPath.count(Eo::SoundDevice::CONFIRM) > 0) {
		sound->play(Eo::SoundDevice::
		_soundPath.at(Eo::SoundDevice::CONFIRM));
	}
}

void Eo::MainMenu::addEvents(Eo::Rc<Eo::Event> event)
{
	event->addGUIHandler(
		Eo::Event::eventKey(Eo::eventType::EGET_BUTTON_CLICKED,
			Eo::MainMenu::ButtonType::PlayGamePlayer),
		[this](bool &toRemove, const Eo::event &event) {
			playButtonClickedSound(_sound);
			auto options = this->_device->getOptions();
			options->setNbPlayer(1);
			_sceneHandler->loadScene(Eo::initRc<Eo::Game>(
				_event, _device, "../map2.json", options,
				_sceneHandler, _sound));
		});
	event->addGUIHandler(
		Eo::Event::eventKey(Eo::eventType::EGET_BUTTON_CLICKED,
			Eo::MainMenu::ButtonType::PlayGamePlayers),
		[this](bool &toRemove, const Eo::event &event) {
			playButtonClickedSound(_sound);
			auto options = this->_device->getOptions();
			options->setNbPlayer(2);
			_sceneHandler->loadScene(Eo::initRc<Eo::Game>(
				_event, _device, "../map2.json", options,
				_sceneHandler, _sound));
		});
	event->addGUIHandler(
		Eo::Event::eventKey(Eo::eventType::EGET_BUTTON_CLICKED,
			Eo::MainMenu::ButtonType::Play),
		[this](bool &toRemove, const Eo::event &event) {
			playButtonClickedSound(_sound);
			_sceneHandler->loadScene(
				Eo::initRc<Eo::PlayMenu>(_event, _device,
					_sceneHandler, _sound));
		});
	event->addGUIHandler(
		Eo::Event::eventKey(Eo::eventType::EGET_BUTTON_CLICKED,
			Eo::MainMenu::ButtonType::Exit),
		[this](bool &toRemove, const Eo::event &event) {
			playButtonClickedSound(_sound);
			auto options = this->_device->getOptions();
			options->setExit(true);
		});
	event->addGUIHandler(
		Eo::Event::eventKey(Eo::eventType::EGET_BUTTON_CLICKED,
			Eo::MainMenu::ButtonType::Settings),
		[this](bool &toRemove, const Eo::event &event) {
			playButtonClickedSound(_sound);
			_sceneHandler->loadScene(
				Eo::initRc<Eo::SettingsMenu>(_event, _device,
					_sceneHandler, _sound));
		});
	event->addGUIHandler(
		Eo::Event::eventKey(Eo::eventType::EGET_BUTTON_CLICKED,
		                    Eo::SettingsMenu::ButtonType::SoundMore),
		[this](bool &toRemove, const Eo::event &event) {
			_sound->setVolume(_sound->getVolume() + 0.1);
		});
	event->addGUIHandler(
		Eo::Event::eventKey(Eo::eventType::EGET_BUTTON_CLICKED,
		                    Eo::SettingsMenu::ButtonType::SoundLess),
		[this](bool &toRemove, const Eo::event &event) {
			_sound->setVolume(_sound->getVolume() - 0.1);
		});
	event->addGUIHandler(
		Eo::Event::eventKey(Eo::eventType::EGET_BUTTON_CLICKED,
			Eo::MainMenu::ButtonType::Credits),
		[this](bool &toRemove, const Eo::event &event) {
			playButtonClickedSound(_sound);
			_sceneHandler->loadScene(
				Eo::initRc<Eo::CreditsMenu>(_event, _device,
					_sceneHandler, _sound));
		});
	event->addGUIHandler(
		Eo::Event::eventKey(Eo::eventType::EGET_BUTTON_CLICKED,
			Eo::ButtonType::Return),
		[this](bool &toRemove, const Eo::event &event) {
			playButtonClickedSound(_sound);
			this->_sceneHandler->unloadCurrentScene();
		});
}
