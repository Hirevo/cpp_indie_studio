/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Options.hpp"
#include "Types.hpp"
#include <iostream>

Eo::Options::Options()
	: _windowSize(1280, 720), _exit(false), _debugMode(false),
	  _keyExit(irr::EKEY_CODE::KEY_F4),
	  _keyDebugMode(irr::EKEY_CODE::KEY_F2), _nbPlayer(1)
{
	_playerKeys.at(0)._bomb = Eo::keyCode::KEY_KEY_A;
	_playerKeys.at(0)._up = Eo::keyCode::KEY_KEY_Z;
	_playerKeys.at(0)._left = Eo::keyCode::KEY_KEY_Q;
	_playerKeys.at(0)._down = Eo::keyCode::KEY_KEY_S;
	_playerKeys.at(0)._right = Eo::keyCode::KEY_KEY_D;
	_playerKeys.at(1)._bomb = Eo::keyCode::KEY_KEY_U;
	_playerKeys.at(1)._up = Eo::keyCode::KEY_KEY_I;
	_playerKeys.at(1)._left = Eo::keyCode::KEY_KEY_J;
	_playerKeys.at(1)._down = Eo::keyCode::KEY_KEY_K;
	_playerKeys.at(1)._right = Eo::keyCode::KEY_KEY_L;
}

const irr::core::dimension2d<irr::u32> &Eo::Options::get_windowSize() const
{
	return _windowSize;
}

void Eo::Options::set_windowSize(
	const irr::core::dimension2d<irr::u32> &_windowSize)
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

size_t Eo::Options::getNbPlayer() const
{
	return _nbPlayer;
}

void Eo::Options::setNbPlayer(size_t nbPlayer)
{
	_nbPlayer = nbPlayer;
}

const std::array<Eo::Options::PlayerKeys, 2> &
Eo::Options::getPlayerKeys() const
{
	return _playerKeys;
}

void Eo::Options::setPlayerKeys(
	const std::array<Eo::Options::PlayerKeys, 2> &_playerKeys)
{
	Options::_playerKeys = _playerKeys;
}
