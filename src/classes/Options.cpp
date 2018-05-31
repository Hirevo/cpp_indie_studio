/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include <iostream>
#include "Options.hpp"

Eo::Options::Options()
	: _windowSize(1680, 1250),
	  _exit(false),
	  _debugMode(false),
	  _keyExit(irr::EKEY_CODE::KEY_KEY_K),
	  _keyDebugMode(irr::EKEY_CODE::KEY_F12)
{
}

const irr::core::dimension2d<irr::u32> &Eo::Options::get_windowSize() const
{
	return _windowSize;
}

void Eo::Options::set_windowSize(
	const irr::core::dimension2d<irr::u32> &_windowSize
)
{
	Options::_windowSize = _windowSize;
}

irr::EKEY_CODE Eo::Options::getKeyExit() const
{
	return _keyExit;
}

void Eo::Options::setKeyExit(irr::EKEY_CODE _keyExit)
{
	Options::_keyExit = _keyExit;
}

irr::EKEY_CODE Eo::Options::getKeyDebugMode() const
{
	return _keyDebugMode;
}

bool Eo::Options::isExit() const
{
	return _exit;
}

void Eo::Options::setExit(bool _exit)
{
	Options::_exit = _exit;
}

void Eo::Options::setKeyDebugMode(irr::EKEY_CODE _keyDebugMode)
{
	Options::_keyDebugMode = _keyDebugMode;
}

bool Eo::Options::isDebugMode() const
{
	return _debugMode;
}

void Eo::Options::setDebugMode(bool _debugMode)
{
	Options::_debugMode = _debugMode;
}
