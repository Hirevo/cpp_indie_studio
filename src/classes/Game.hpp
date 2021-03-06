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
			Eo::Rc<Eo::SceneHandler> sceneHandler, Eo::Rc<Eo::SoundDevice> sound,
			bool randomize = true);
		~Game();
		irr::scene::ICameraSceneNode *getCamera() const override;
		bool draw() override;
		void addEvents();
		void placeObject(Eo::vec2i size, Eo::vec2i cur);
		void addPlayerEvents(Eo::Rc<Eo::ICharacter> player);
		void update();
		Eo::Rc<Eo::Map> getMap();
		void placeBomb(Eo::Rc<Eo::ICharacter> player, Eo::u32 bombs);
		const std::string &getMapName() const;
		bool clear() override;
		bool gameOver();
		void saveGame();
		void updatePlayerPos();

	private:
		void insertMap(Eo::vec2i v);
		Eo::keyHandler getPlayerEventFunc(
			Eo::Rc<Eo::ICharacter> &player,
			Eo::Player::Motion flag);
		Eo::IObject::Type CollectibleMove(
			Eo::vec3 pos, Eo::u64 id);
		void useCollectible(Eo::IObject::Type,
			Eo::Rc<Eo::ICharacter>);
		std::array<Eo::Rc<Eo::Player>, 2> _players;
		std::array<Eo::Rc<Eo::Computer>, 3> _computers;
		Eo::Rc<Eo::IObject> _floor;
		Eo::JsonRead _json;
		Eo::Rc<Eo::Map> _map;
		Eo::Camera _camera;
		Eo::Rc<Eo::Options> _options;
		Eo::Rc<Eo::SceneHandler> _sceneHandler;
		std::string _mapName = "map4.json";
		std::vector<std::vector<float>> _playersPos;
		Eo::vec3 getPlayerPos(size_t playerId);
		std::vector<std::string> _deathOrder;
		static const float _maxSpeed;
		static const float _speedBonus;
	};
}
