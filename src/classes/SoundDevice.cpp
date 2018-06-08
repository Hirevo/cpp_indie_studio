//
// EPITECH Project, 2018
// bomberman
// File description:
// SoundDevice.cpp
//

#include "SoundDevice.hpp"

const std::unordered_map<Eo::SoundDevice::SoundPath, std::string> Eo::SoundDevice::_soundPath = {
	{MENUBGM, "../assets/sounds/BGM/main_theme.mp3"},
	{GAMEBGM, "../assets/sounds/BGM/main_theme.mp3"},
	{PAUSE, "../assets/sounds/effects/buttons/PAUSE.wav"},
	{CONFIRM, "../assets/sounds/effects/buttons/confirm.wav"},
	{RESET, "../assets/sounds/effects/buttons/reset.wav"},
	{SELECT, "../assets/sounds/effects/buttons/select.wav"},
	{BOMBS, "../assets/sounds/effects/inGame/bombS.wav"},
	{BOMBM, "../assets/sounds/effects/inGame/bombL.wav"},
	{BOMBL, "../assets/sounds/effects/inGame/bombL.wav"},
	{PLAY, "../assets/sounds/effects/inGame/play.wav"},
	{SETBOMB, "../assets/sounds/effects/inGame/setBomb.wav"},
	{DEATH, "../assets/sounds/effects/inGame/death.wav"},
	{GETITEM, "../assets/sounds/effects/inGame/getItem.wav"},
	{HURRY, "../assets/sounds/effects/inGame/hurry.wav"}
};

Eo::SoundDevice::SoundDevice()
	: _device(irrklang::createIrrKlangDevice(irrklang::ESOD_AUTO_DETECT,
	irrklang::ESEO_DEFAULT_OPTIONS - irrklang::ESEO_PRINT_DEBUG_INFO_TO_STDOUT))
{
}

Eo::SoundDevice::~SoundDevice()
{
	_device->drop();
}

void Eo::SoundDevice::stop()
{
	_device->stopAllSounds();
}

void Eo::SoundDevice::play(const std::string &path, bool loop)
{
	_device->play2D(path.c_str(), loop);
}

int Eo::SoundDevice::getVolume() const
{
	return static_cast<int>(_device->getSoundVolume() * 100);
}

void Eo::SoundDevice::setVolume(const int volume)
{
	_device->setSoundVolume(static_cast<irrklang::ik_f32>(volume / 100));
}
