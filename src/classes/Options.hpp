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
		bool _exit;
		irr::EKEY_CODE _keyExit;
		irr::EKEY_CODE _keyDebugMode;
	public:
		const irr::core::dimension2d<irr::u32> &get_windowSize() const;
		void set_windowSize(
			const irr::core::dimension2d<irr::u32> &_windowSize
		);
		bool isExit() const;
		void setExit(bool _exit);
		irr::EKEY_CODE getKeyExit() const;
		void setKeyExit(irr::EKEY_CODE _keyExit);
		irr::EKEY_CODE getKeyDebugMode() const;
		void setKeyDebugMode(irr::EKEY_CODE _keyDebugMode);
	};
}

#endif
