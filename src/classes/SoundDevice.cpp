//
// EPITECH Project, 2018
// bomberman
// File description:
// SoundDevice.cpp
//

#include <iostream>
#include <fstream>
#include "SoundDevice.hpp"
#include "JsonWrite.hpp"
#include "JsonRead.hpp"

const std::unordered_map<Eo::SoundDevice::SoundPath, std::string> Eo::SoundDevice::_soundPath = {
	{MENUBGM, currPath + "../assets/sounds/BGM/main_theme.mp3"},
	{GAMEBGM, currPath + "../assets/sounds/BGM/game_theme.mp3"},
	{PAUSE, currPath + "../assets/sounds/effects/buttons/PAUSE.wav"},
	{CONFIRM, currPath + "../assets/sounds/effects/buttons/confirm.wav"},
	{RESET, currPath + "../assets/sounds/effects/buttons/reset.wav"},
	{SELECT, currPath + "../assets/sounds/effects/buttons/select.wav"},
	{BOMBS, currPath + "../assets/sounds/effects/inGame/bombS.wav"},
	{BOMBM, currPath + "../assets/sounds/effects/inGame/bombL.wav"},
	{BOMBL, currPath + "../assets/sounds/effects/inGame/bombL.wav"},
	{PLAY, currPath + "../assets/sounds/effects/inGame/play.wav"},
	{SETBOMB, currPath + "../assets/sounds/effects/inGame/setBomb.wav"},
	{DEATH, currPath + "../assets/sounds/effects/inGame/death.wav"},
	{GETITEM, currPath + "../assets/sounds/effects/inGame/getItem.wav"},
	{HURRY, currPath + "../assets/sounds/effects/inGame/hurry.wav"},
	{VICTORY, currPath + "../assets/sounds/BGM/victory.mp3"}
};

const std::unordered_map<Eo::SoundDevice::SoundPath, Eo::SoundDevice::SoundType> Eo::SoundDevice::_soundType = {
	{MENUBGM, MUSIC},
	{GAMEBGM, MUSIC},
	{PAUSE, EFFECT},
	{CONFIRM, EFFECT},
	{RESET, EFFECT},
	{SELECT, EFFECT},
	{BOMBS, EFFECT},
	{BOMBM, EFFECT},
	{BOMBL, EFFECT},
	{PLAY, EFFECT},
	{SETBOMB, EFFECT},
	{DEATH, EFFECT},
	{GETITEM, EFFECT},
	{HURRY, EFFECT},
	{VICTORY, EFFECT}
};

Eo::SoundDevice::SoundDevice()
	: _music(irrklang::createIrrKlangDevice(irrklang::ESOD_AUTO_DETECT,
	irrklang::ESEO_DEFAULT_OPTIONS /*- irrklang::ESEO_PRINT_DEBUG_INFO_TO_STDOUT*/)),
	  _effects(irrklang::createIrrKlangDevice(irrklang::ESOD_AUTO_DETECT,
		  irrklang::ESEO_DEFAULT_OPTIONS /*- irrklang::ESEO_PRINT_DEBUG_INFO_TO_STDOUT*/)),
	  _gVolume(1.0f), _eVolume(_effects->getSoundVolume()),
	  _mVolume(_music->getSoundVolume()),
	  _gIsMute(false), _eIsMute(false), _mIsMute(false)
{
	Eo::JsonRead file(".soundSettings");
	if (file.good()) {
		auto mat = file.readMatrix("sound_settings");
		_gVolume = static_cast<float>(mat.at(0).at(0)) / 100.0f;
		_eVolume = static_cast<float>(mat.at(0).at(1)) / 100.0f;
		_mVolume = static_cast<float>(mat.at(0).at(2)) / 100.0f;
		_effects->setSoundVolume(_gVolume * _eVolume);
		_music->setSoundVolume(_gVolume * _mVolume);
		_gIsMute = mat.at(1).at(0) != 0;
		if (_gIsMute)
			this->mute();
		_eIsMute = mat.at(1).at(1) != 0;
		if (_eIsMute)
			this->muteEffects();
		_mIsMute = mat.at(1).at(2) != 0;
		if (_mIsMute)
			this->muteMusic();
	}
}

void Eo::SoundDevice::deleteSoundDevice()
{
	std::vector<std::vector<Eo::i32>> v;
	v.push_back({static_cast<int>(_gVolume * 100),
		static_cast<int>(_eVolume * 100),
		static_cast<int>(_mVolume * 100)});
	v.push_back({_gIsMute, _eIsMute, _mIsMute});
	Eo::JsonWrite file;
	file.writeMatrix("sound_settings", v);
	file.generateJson(".soundSettings");
}

Eo::SoundDevice::~SoundDevice()
{
	_music->drop();
	_effects->drop();
}

void Eo::SoundDevice::stop()
{
	_music->stopAllSounds();
	_effects->stopAllSounds();
}

void Eo::SoundDevice::stopMusic()
{
	_music->stopAllSounds();
}

void Eo::SoundDevice::stopEffects()
{
	_music->stopAllSounds();
}

void Eo::SoundDevice::playEffects(const std::string &path, bool loop)
{
	_effects->play2D(path.c_str(), loop);
}

void Eo::SoundDevice::playMusic(const std::string &path, bool loop)
{
	_music->play2D(path.c_str(), loop);
}

void Eo::SoundDevice::play(const Eo::SoundDevice::SoundPath path, bool loop)
{
	auto exists = _soundType.count(path) > 0 && _soundPath.count(path) > 0;
	if (exists) {
		if (_soundType.at(path) == MUSIC) {
			this->playMusic(_soundPath.at(path), loop);
		} else {
			this->playEffects(_soundPath.at(path), loop);
		}
	}
}

float Eo::SoundDevice::getGeneralVolume() const
{
	return _gVolume;
}

void Eo::SoundDevice::setGeneralVolume(const float volume)
{
	if (_gIsMute)
		this->unMute();
	auto newVol = volume;
	if (newVol < 0.0f)
		newVol = 0.0f;
	else if (newVol > 1.0f)
		newVol = 1.0f;
	_gVolume = newVol;
	_effects->setSoundVolume(_eVolume * newVol);
	_music->setSoundVolume(_mVolume * newVol);
}

float Eo::SoundDevice::getMusicVolume() const
{
	return _mVolume;
}

void Eo::SoundDevice::setMusicVolume(const float volume)
{
	if (_mIsMute)
		this->unMuteMusic();
	auto newVol = volume;
	if (newVol < 0.0f)
		newVol = 0.0f;
	else if (newVol > 1.0f)
		newVol = 1.0f;
	_mVolume = newVol;
	_music->setSoundVolume(_mVolume * _gVolume);
}

float Eo::SoundDevice::getEffectsVolume() const
{
	return _eVolume;
}

void Eo::SoundDevice::setEffectsVolume(const float volume)
{
	if (_eIsMute)
		this->unMuteEffects();
	auto newVol = volume;
	if (newVol < 0.0f)
		newVol = 0.0f;
	else if (newVol > 1.0f)
		newVol = 1.0f;
	_eVolume = newVol;
	_effects->setSoundVolume(_eVolume * _gVolume);
}

void Eo::SoundDevice::muteEffects()
{
	_effects->setSoundVolume(0.0f);
	_eIsMute = true;
}

void Eo::SoundDevice::muteMusic()
{
	_music->setSoundVolume(0.0f);
	_mIsMute = true;
}

void Eo::SoundDevice::mute()
{
	_gIsMute = true;
	_music->setSoundVolume(0.0f);
	_effects->setSoundVolume(0.0f);
}

void Eo::SoundDevice::unMute()
{
	_gIsMute = false;
	if (!_mIsMute)
		_music->setSoundVolume(_mVolume * _gVolume);
	if (!_eIsMute)
		_effects->setSoundVolume(_eVolume * _gVolume);
}

void Eo::SoundDevice::unMuteEffects()
{
	_eIsMute = false;
	_gIsMute = false;
	_effects->setSoundVolume(_eVolume * _gVolume);
}

void Eo::SoundDevice::unMuteMusic()
{
	_mIsMute = false;
	_gIsMute = false;
	_music->setSoundVolume(_mVolume * _gVolume);
}

bool Eo::SoundDevice::generalIsMute() const
{
	return _gIsMute;
}

bool Eo::SoundDevice::musicIsMute() const
{
	return _mIsMute;
}

bool Eo::SoundDevice::effectsIsMute() const
{
	return _eIsMute;
}