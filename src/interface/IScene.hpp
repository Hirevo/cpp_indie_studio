/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#ifndef BOMBERMAN_ISCENE_HPP
	#define BOMBERMAN_ISCENE_HPP

	#include "irrlicht.h"

namespace Eo {
	class IScene {
	public:
		virtual ~IScene() = default;
		virtual irr::scene::ISceneManager *get_sceneManager() const = 0;
	private:
	};
}

#endif
