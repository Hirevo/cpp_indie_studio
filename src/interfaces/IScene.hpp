/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#pragma once

#include "irrlicht.h"
#include "Types.hpp"

namespace Eo {
	class IScene {
	private:
	public:
		virtual ~IScene() = default;
		virtual irr::scene::ISceneManager *getSceneManager() const = 0;
		virtual irr::scene::ICameraSceneNode *getCamera() const = 0;
		virtual bool clear() = 0;
		virtual bool draw() = 0;
		virtual void update() = 0;
	};
}
