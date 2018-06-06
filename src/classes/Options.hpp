/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#ifndef BOMBERMAN_OPTIONS_HPP
#define BOMBERMAN_OPTIONS_HPP

#include <Types.hpp>
#include "irrlicht.h"

namespace Eo {
	class Options {
	public:
		Options();
	private:
		typedef struct PlayerKeys_s {
			Eo::keyCode _up;
			Eo::keyCode _left;
			Eo::keyCode _down;
			Eo::keyCode _right;
			Eo::keyCode _bomb;
		} PlayerKey_t;
		std::array<PlayerKeys_s,2> _playerKeys;
		irr::core::dimension2d<irr::u32> _windowSize;
		bool _exit;
		bool _debugMode;
		irr::EKEY_CODE _keyExit;
		irr::EKEY_CODE _keyDebugMode;
		size_t _nbPlayer;
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
		bool isDebugMode() const;
		void setDebugMode(bool _debugMode);
		size_t getNbPlayer() const;
		void setNbPlayer(size_t _nbPlayer);
		const std::array<PlayerKeys_s, 2> &getPlayerKeys() const;
		void setPlayerKeys(
			const std::array<PlayerKeys_s, 2> &_playerKeys
		);
	};
}

#endif
