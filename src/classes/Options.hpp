/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#ifndef BOMBERMAN_OPTIONS_HPP
#define BOMBERMAN_OPTIONS_HPP

#include "irrlicht.h"

namespace Eo {
	class Options {
	public:
		Options();
	private:
		irr::core::dimension2d<irr::u32> _windowSize;
	public:
		const irr::core::dimension2d<irr::u32> &get_windowSize() const;
	};
}

#endif
