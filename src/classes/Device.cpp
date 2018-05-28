/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Device.hpp"

Eo::Device::Device(Eo::Options &options) :
	_options(options)
{
	_device = irr::createDevice(
		irr::video::EDT_OPENGL, _options.get_windowSize(), 32);
	_driver = _device->getVideoDriver();
}

irr::IrrlichtDevice *Eo::Device::get_device() const
{
	return _device;
}

irr::video::IVideoDriver *Eo::Device::get_driver() const
{
	return _driver;
}
