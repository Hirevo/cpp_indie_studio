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
	_event->clearEventHandlers(Eo::Event::eventKey(Eo::eventType::EGET_SCROLL_BAR_CHANGED,
		Eo::SettingsMenu::ButtonType::SoundGeneral));
	_event->clearEventHandlers(Eo::Event::eventKey(Eo::eventType::EGET_SCROLL_BAR_CHANGED,
		Eo::SettingsMenu::ButtonType::SoundMusic));
	_event->clearEventHandlers(Eo::Event::eventKey(Eo::eventType::EGET_SCROLL_BAR_CHANGED,
		Eo::SettingsMenu::ButtonType::SoundFX));
	_event->clearEventHandlers(Eo::Event::eventKey(Eo::eventType::EGET_BUTTON_CLICKED,
		Eo::SettingsMenu::ButtonType::MuteGeneral));
	_event->clearEventHandlers(Eo::Event::eventKey(Eo::eventType::EGET_BUTTON_CLICKED,
		Eo::SettingsMenu::ButtonType::MuteMusic));
	_event->clearEventHandlers(Eo::Event::eventKey(Eo::eventType::EGET_BUTTON_CLICKED,
		Eo::SettingsMenu::ButtonType::MuteFX));
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

	env->addButton({(int)(w / 6 + w / 2),
			(int)(((h / 8) * pos) / 2),
			(int)(w / 6 + 2 * w / 3),
			(int)(((h / 8) * pos + h / 8) / 2)},
		nullptr, Eo::SettingsMenu::ButtonType::MuteGeneral,
		this->_sound->generalIsMute() ? L"Mute" : L"Unmute", L"Mute");
	env->addStaticText(L"General Volume",
			{(int)(w / 6),
				(int)(((h / 8) * pos) / 2),
				(int)(w / 6 + 2 * w / 4),
				(int)(((h / 8) * pos + h / 8) / 2)})
		->setTextAlignment(irr::gui::EGUI_ALIGNMENT::EGUIA_CENTER,
			irr::gui::EGUI_ALIGNMENT::EGUIA_CENTER);
	env->addScrollBar(true, {(int)(w / 6), (int)(((h / 8) * pos) / 2),
			(int)(w / 6 + 2 * w / 4),
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

	env->addButton({
			(int)(w / 6 + w / 2),
			(int)(((h / 8) * pos) / 2),
			(int)(w / 6 + 2 * w / 3),
			(int)(((h / 8) * pos + h / 8) / 2)
		},
		nullptr, Eo::SettingsMenu::ButtonType::MuteMusic,
		this->_sound->musicIsMute() ? L"Mute" : L"Unmute", L"Mute");
	env->addStaticText(L"Music Volume",
			{(int)(w / 6), (int)(((h / 8) * pos) / 2),
				(int)(w / 6 + 2 * w / 4),
				(int)(((h / 8) * pos + h / 8) / 2)})
		->setTextAlignment(irr::gui::EGUI_ALIGNMENT::EGUIA_CENTER,
			irr::gui::EGUI_ALIGNMENT::EGUIA_CENTER);
	env->addScrollBar(true, {(int)(w / 6), (int)(((h / 8) * pos) / 2),
			(int)(w / 6 + 2 * w / 4),
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

	env->addButton({
			(int)(w / 6 + w / 2),
			(int)(((h / 8) * pos) / 2),
			(int)(w / 6 + 2 * w / 3),
			(int)(((h / 8) * pos + h / 8) / 2)
		},
		nullptr, Eo::SettingsMenu::ButtonType::MuteFX,
		this->_sound->effectsIsMute() ? L"Mute" : L"Unmute", L"Mute");
	auto text = env->addStaticText(L"Effects Volume",
		{(int)(w / 6),
			(int)(((h / 8) * pos) / 2),
			(int)(w / 6 + 2 * w / 4),
			(int)(((h / 8) * pos + h / 8) / 2)});
	text->setTextAlignment(irr::gui::EGUI_ALIGNMENT::EGUIA_CENTER,
		irr::gui::EGUI_ALIGNMENT::EGUIA_CENTER);
	env->addScrollBar(true, {(int)(w / 6), (int)(((h / 8) * pos) / 2),
			(int)(w / 6 + 2 * w / 4),
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
	event->addGUIHandler(
		Eo::Event::eventKey(Eo::eventType::EGET_SCROLL_BAR_CHANGED,
			Eo::SettingsMenu::ButtonType::SoundGeneral),
		[this](bool &toRemove, const Eo::event &event) {
			auto bar = ((irr::gui::IGUIScrollBar *)event.
				GUIEvent.Caller);
			auto val = (float)bar->getPos() / (float)bar->getMax();
			_sound->setGeneralVolume(val);
		});
	event->addGUIHandler(
		Eo::Event::eventKey(Eo::eventType::EGET_SCROLL_BAR_CHANGED,
			Eo::SettingsMenu::ButtonType::SoundMusic),
		[this](bool &toRemove, const Eo::event &event) {
			auto bar = ((irr::gui::IGUIScrollBar *)event.
				GUIEvent.Caller);
			auto val = (float)bar->getPos() / (float)bar->getMax();
			_sound->setMusicVolume(val);
		});
	event->addGUIHandler(
		Eo::Event::eventKey(Eo::eventType::EGET_SCROLL_BAR_CHANGED,
			Eo::SettingsMenu::ButtonType::SoundFX),
		[this](bool &toRemove, const Eo::event &event) {
			auto bar = ((irr::gui::IGUIScrollBar *)event.
				GUIEvent.Caller);
			auto val = (float)bar->getPos() / (float)bar->getMax();
			_sound->setEffectsVolume(val);
			_sound->play(Eo::SoundDevice::SELECT);
		});

	event->addGUIHandler(
		Eo::Event::eventKey(Eo::eventType::EGET_BUTTON_CLICKED,
			Eo::SettingsMenu::ButtonType::MuteGeneral),
		[this](bool &toRemove, const Eo::event &event) {
			if (_sound->generalIsMute()) {
				_sound->unMute();
				event.GUIEvent.Caller->setText(L"Mute");
			} else {
				_sound->mute();
				event.GUIEvent.Caller->setText(L"Unmute");
			}
			_sound->play(Eo::SoundDevice::SELECT);
		});
	event->addGUIHandler(
		Eo::Event::eventKey(Eo::eventType::EGET_BUTTON_CLICKED,
			Eo::SettingsMenu::ButtonType::MuteMusic),
		[this](bool &toRemove, const Eo::event &event) {
			if (_sound->musicIsMute()) {
				_sound->unMuteMusic();
				event.GUIEvent.Caller->setText(L"Mute");
			} else {
				_sound->muteMusic();
				event.GUIEvent.Caller->setText(L"Unmute");
			}
			_sound->play(Eo::SoundDevice::SELECT);
		});
	event->addGUIHandler(
		Eo::Event::eventKey(Eo::eventType::EGET_BUTTON_CLICKED,
			Eo::SettingsMenu::ButtonType::MuteFX),
		[this](bool &toRemove, const Eo::event &event) {
			if (_sound->effectsIsMute()) {
				_sound->unMuteEffects();
				event.GUIEvent.Caller->setText(L"Mute");
			} else {
				_sound->muteEffects();
				event.GUIEvent.Caller->setText(L"Unmute");
			}
			_sound->play(Eo::SoundDevice::SELECT);
		});
}
