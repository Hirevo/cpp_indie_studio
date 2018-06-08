/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Device.hpp"

Eo::Device::Device(Eo::Rc<Eo::Options> options)
	: _options(options)
{
	_device = irr::createDevice(irr::video::EDT_OPENGL,
		_options->getWindowSize(), 32, false, false, true, nullptr);
	_driver = _device->getVideoDriver();
}

irr::IrrlichtDevice *Eo::Device::getDevice() const
{
	return _device;
}

irr::video::IVideoDriver *Eo::Device::getDriver() const
{
	return _driver;
}

void Eo::Device::setDeviceTitle(const wchar_t *title)
{
	this->getDevice()->setWindowCaption(title);
}

Eo::Rc<Eo::Options> Eo::Device::getOptions()
{
	return _options;
}
