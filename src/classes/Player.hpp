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
	#pragma warning(disable:4250)
	class Player : public AModel {
	public:
		Player(vec3 pos = vec3(0, 0, 0));
		~Player();

	private:
		Eo::vec2 pos;
		float angle;
		float speed;
		int maxBomb;
		int bombAvailable;
	};
}
