/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#pragma once

#include "AScene.hpp"
#include "Booster.hpp"
#include "Camera.hpp"
#include "Computer.hpp"
#include "Device.hpp"
#include "IScene.hpp"
#include "JsonRead.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "irrlicht.h"
#include <AModel.hpp>
#include <list>
#include <memory>
#include <stack>

namespace Eo {
	class Player;
	class Game : public AScene {
	public:
		Game(Eo::Rc<Eo::Event> event, Eo::Rc<Eo::Device> device,
			const std::string &mapPath, Eo::Rc<Eo::Options> options,
			Eo::Rc<Eo::SceneHandler> sceneHandler);
		~Game();
		irr::scene::ICameraSceneNode *getCamera() const override;
		bool draw() override;
		void addEvents();
		void placeObject(Eo::vec2i size, Eo::vec2i cur);
		void addPlayerEvents(Eo::Rc<Eo::Player> &player);
		void update();
		Eo::Rc<Eo::Map> getMap();

	private:
		void insertMap(Eo::vec2i v);
		Eo::keyHandler getPlayerEventFunc(
			Eo::Rc<Eo::Player> &player, Eo::Player::Motion flag);
		bool isValidMove(Eo::vec3 newPos, irr::u64 id);
		Eo::Booster::BoosterType CollectibleMove(
			Eo::vec3 Pos, irr::u64 id);
		std::array<Eo::Rc<Eo::Player>, 2> _players;
		std::array<Eo::Rc<Eo::Computer>, 3> _computers;
		Eo::Rc<Eo::IObject> _floor;
		void useCollectible(Booster::BoosterType, Player *);
		Eo::JsonRead _json;
		Eo::Rc<Eo::Map> _map;
		Eo::Camera _camera;
		Eo::Rc<Eo::Options> _options;
		Eo::Rc<Eo::SceneHandler> _sceneHandler;
	};
}
