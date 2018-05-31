/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#ifndef BOMBERMAN_DEVICE_HPP
#define BOMBERMAN_DEVICE_HPP

#include <string>
#include "irrlicht.h"
#include "Options.hpp"

namespace Eo {
	class Device {
	public:
		Device(Eo::Options &options);
	private:
		irr::IrrlichtDevice* _device;
		Eo::Options _options;
		irr::video::IVideoDriver *_driver;
		irr::gui::IGUIEnvironment *_env;
	public:
		irr::IrrlichtDevice *getDevice() const;
		irr::video::IVideoDriver *getDriver() const;
		void setDeviceTitle(const wchar_t *title);
	};
}

#endif
