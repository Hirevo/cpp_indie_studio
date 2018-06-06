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
#include "Player.hpp"
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

	private:
		void insertMap(irr::video::ITexture *texture, irr::s32 wth,
			irr::s32 hgt);
		Eo::keyHandler getPlayerEventFunc(
			Eo::Player *player, Eo::Player::Motion flag);
		std::array<Eo::Player *, 2> _players;
		std::list<Eo::IObject *> _objects;
		Eo::JsonRead _json;
		Eo::Map _map;
		Eo::Camera _camera;
		Eo::Options &_options;
	};
}
