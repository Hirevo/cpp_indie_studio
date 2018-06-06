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
		explicit Player(Eo::IScene &, Eo::Event &, Eo::Options &, const vec3 &pos = vec3(0), Eo::u64 id = 0);
		~Player() override;
		void setFlag(Eo::u8 flags);
		void unsetFlag(Eo::u8 flags);
		Eo::u8 getFlag() const;
		void update();
		u64 getPlayerId() const;
		f32 getSpeed() const;
		void setSpeed(f32 _speed);
	private:
		void addEvents(Eo::IScene &game);
		Eo::u8 _flags;
		irr::f32 _angle;
		irr::f32 _speed = 0.03;
		irr::u32 _maxBomb;
		irr::u32 _bombAvailable;
		irr::u64 _playerId;
		Eo::Event &_event;
		Eo::Options &_options;
	};
}
