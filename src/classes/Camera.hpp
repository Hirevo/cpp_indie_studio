/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#ifndef BOMBERMAN_CAMERA_HPP
#define BOMBERMAN_CAMERA_HPP

#include <SKeyMap.h>
#include "Scene.hpp"

namespace Eo {
	class Camera {
	public:
		Camera(Eo::Scene &scene);
		~Camera();
	private:
		irr::SKeyMap _keyMap[5];
		Eo::Scene &_scene;
	};


}

#endif
