//
// EPITECH Project, 2018
// bomberman
// File description:
// SoundDevice.cpp
//

#include "SoundDevice.hpp"

Eo::SoundDevice::SoundDevice()
	: _device(irrklang::createIrrKlangDevice(irrklang::ESOD_AUTO_DETECT,
	irrklang::ESEO_DEFAULT_OPTIONS/* - irrklang::ESEO_PRINT_DEBUG_INFO_TO_STDOUT*/))
{
}

Eo::SoundDevice::~SoundDevice()
{
	_device->drop();
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