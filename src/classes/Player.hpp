/*
** EPITECH PROJECT, 2018
** indie_studio
** File description:
** Player
*/

#pragma once

#include "AModel.hpp"
#include "ACharacter.hpp"
#include "Device.hpp"
#include "Event.hpp"
#include "IScene.hpp"
#include "irrlicht.h"
#include "Map.hpp"

namespace Eo {
#pragma warning(disable : 4250)
	class Game;
	class Player : public AModel, public ACharacter {
	public:
		enum Motion {
			Forward = 1 << 0,
			Backward = 1 << 1,
			Left = 1 << 2,
			Right = 1 << 3
		};
		enum Facing {
			North = Eo::Player::Motion::Forward,
			South = Eo::Player::Motion::Backward,
			West = Eo::Player::Motion::Left,
			East = Eo::Player::Motion::Right,
			NorthWest = North | West,
			NorthEast = North | East,
			SouthWest = South | West,
			SouthEast = South | East
		};
		using Directions =
			std::unordered_map<Eo::Player::Facing, Eo::f32>;
		static const Eo::Player::Directions _dirs;
		explicit Player(Eo::Rc<Eo::IScene>, Eo::Rc<Eo::Event>,
			Eo::Rc<Eo::Options>, const vec3 &pos = vec3(0),
			Eo::u64 id = 0);
		~Player() override;
		void move(Eo::Rc<Eo::Game> scene);
		void draw(Eo::Rc<Eo::IScene> scene) override;

	private:
		void addEvents(Eo::Rc<Eo::IScene> game);
		bool isValidMove(Eo::Rc<Eo::Map> map, Eo::vec3 newPos,
			Eo::u64 id);
		Eo::f32 _angle;
		std::string _path;
		Eo::Rc<Eo::Event> _event;
		Eo::Rc<Eo::Options> _options;
	};
}
