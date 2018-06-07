/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#pragma once

#include "AScene.hpp"
#include "Camera.hpp"
#include "Device.hpp"
#include "IScene.hpp"
#include "JsonRead.hpp"
#include "Map.hpp"
#include "Booster.hpp"
#include "Player.hpp"
#include "Computer.hpp"
#include "irrlicht.h"
#include <AModel.hpp>
#include <list>
#include <memory>
#include <stack>

namespace Eo {
	class Game : public AScene {
	public:
		Game(Eo::Event &event, Eo::Device &device,
			const std::string &mapPath, Eo::Options &options);
		~Game();
		irr::scene::ICameraSceneNode *getCamera() const override;
		bool draw() override;
		void addEvents();
		void addPlayerEvents(Eo::Player *player);
		void update();
		const Map &getMap() const;

	private:
		void insertMap(Eo::vec2i v);
		void placeObject(Eo::vec2i size, Eo::vec2i cur);
		Eo::keyHandler getPlayerEventFunc(
			Eo::Player *player, Eo::Player::Motion flag);
		bool isValidMove(Eo::vec3 newPos, irr::u64 id);
		Eo::Booster::BoosterType CollectibleMove(Eo::vec3 Pos, irr::u64 id);
		std::array<Eo::Player *, 2> _players;
		std::array<Eo::Computer *, 3> _computers;
		std::list<Eo::IObject *> _objects;
		Eo::JsonRead _json;
		Eo::Map _map;
		Eo::Camera _camera;
		Eo::Options &_options;
	};
}
