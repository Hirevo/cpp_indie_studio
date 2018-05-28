/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#ifndef BOMBERMAN_SCENE_HPP
#define BOMBERMAN_SCENE_HPP

#include "Device.hpp"
#include "JsonRead.hpp"
#include "Map.hpp"
#include "interfaces/IScene.hpp"
#include "irrlicht.h"
#include <AGame.hpp>
#include <memory>
#include <stack>
namespace Eo {
	class Game : public AGame {
	public:
		Game(Eo::Device &device, const std::string &mapPath);
		virtual ~Game() = default;
		irr::scene::ISceneManager *getSceneManager() const override;
		irr::scene::ICameraSceneNode *getCamera() const override;

	private:
		Eo::JsonRead _json;
		Eo::Map _map;
	};
}
#endif
