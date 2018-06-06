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
		enum Motion {
			Forward = 1 << 0,
			Backward = 1 << 1,
			Left = 1 << 2,
			Right = 1 << 3
		};
		enum Facing {
			//Todo Change direction logique
			North = Eo::Player::Motion::Forward,
			South = Eo::Player::Motion::Backward,
			West = Eo::Player::Motion::Right,
			East = Eo::Player::Motion::Left,
			NorthWest = North | East,
			NorthEast = North | West,
			SouthWest = South | West,
			SouthEast = South | East
		};
		using Directions =
			std::unordered_map<Eo::Player::Facing, Eo::f32>;
		static const Eo::Player::Directions _dirs;
		explicit Player(Eo::IScene &, Eo::Event &, Eo::Options &,
			const vec3 &pos = vec3(0), Eo::u64 id = 0);
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
		irr::f32 _speed = 0.03f;
		irr::u32 _maxBomb;
		irr::u32 _bombAvailable;
		irr::u64 _playerId;
		Eo::Event &_event;
		Eo::Options &_options;
	};
}
