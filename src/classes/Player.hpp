/*
** EPITECH PROJECT, 2018
** indie_studio
** File description:
** Player
*/

#pragma once

#include "AModel.hpp"
#include "Device.hpp"
#include "Event.hpp"
#include "IScene.hpp"
#include "irrlicht.h"

namespace Eo {
#pragma warning(disable : 4250)
	class Game;
	class Player : public AModel {
	public:
		enum Motion { Forward = 1, Backward = 2, Left = 4, Right = 8 };
		Player(Eo::IScene &game, Eo::Event &event,
			const Eo::vec3 &pos = Eo::vec3(0));
		~Player() override;
		void setFlag(Eo::u8 flags);
		void unsetFlag(Eo::u8 flags);
		Eo::u8 getFlag() const;
		void update();

	private:
		void addEvents(Eo::IScene &game);
		Eo::vec2 pos;
		Eo::f32 _angle;
		Eo::f32 _speed;
		Eo::u32 _maxBomb;
		Eo::u32 _bombAvailable;
		Eo::Event &_event;
		Eo::u8 _flags;
	};
}
