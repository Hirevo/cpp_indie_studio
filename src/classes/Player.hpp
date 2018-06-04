/*
** EPITECH PROJECT, 2018
** indie_studio
** File description:
** Player
*/

#pragma once

#include "AModel.hpp"
#include "Core.hpp"
#include "Device.hpp"
#include "irrlicht.h"

namespace Eo {
	class Player : public AModel {
	public:
		Player(vec3 pos = vec3(0, 0, 0));
		~Player();
		// vec3 getPosition();
		// void movePlayer(vec3 &newPos);

	private:
	};
}
