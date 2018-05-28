/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#ifndef BOMBERMAN_CAMERA_HPP
#define BOMBERMAN_CAMERA_HPP

#include <SKeyMap.h>
#include "Game.hpp"
#include "irrlicht.h"

namespace Eo {
	class Camera {
	public:
		Camera(Eo::Scene &scene);
		~Camera() = default;

	private:
		irr::SKeyMap _keyMap[5];
		Eo::Scene &_scene;
		irr::scene::ICameraSceneNode *_camera;
	};


}

#endif
