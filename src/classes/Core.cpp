/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Core.hpp"

Eo::Core::~Core()
{
}

Eo::Core::Core()
{
	_device = irr::createDevice(
		irr::video::EDT_OPENGL,
		_options.get_windowSize(),
		32);
	_driver = _device->getVideoDriver();
}

irr::IrrlichtDevice *Eo::Core::get_device() const
{
	return _device;
}
