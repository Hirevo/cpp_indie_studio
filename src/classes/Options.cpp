/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Options.hpp"

Eo::Options::Options() :
	_windowSize(1680, 1250)
{
}

const irr::core::dimension2d<irr::u32> &Eo::Options::get_windowSize() const
{
	return _windowSize;
}
