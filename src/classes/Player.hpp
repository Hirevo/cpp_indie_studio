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
#include "Event.hpp"

namespace Eo {
	#pragma warning(disable:4250)

	class Player : public AModel {
	public:
		explicit Player(Eo::Game &, Eo::Event &, const vec3 &pos = vec3(0));
		~Player() override;
	private:
		irr::f32 _angle;
		irr::f32 _speed;
		irr::u32 _maxBomb;
		irr::u32 _bombAvailable;
		Eo::Event &_event;
	private:
		void addEvents(Eo::Game &game);
	};
}
