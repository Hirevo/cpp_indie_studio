/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#ifndef BOMBERMAN_ISCENE_HPP
#define BOMBERMAN_ISCENE_HPP

#include <IVideoDriver.h>
#include <memory>

namespace Eo {
	class IScene {
	private:
		std::unique_ptr <irr::video::IVideoDriver> _driver;
	public:
	};
}

#endif
