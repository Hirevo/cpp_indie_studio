/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#ifndef BOMBERMAN_SCENE_HPP
#define BOMBERMAN_SCENE_HPP

#include <memory>
#include <stack>
#include <AGame.hpp>
#include "Device.hpp"
#include "interfaces/IScene.hpp"
#include "irrlicht.h"
#include "JsonRead.hpp"
#include "Map.hpp"
namespace Eo {
	class Game : public AGame {
	public:
		Game(Eo::Device &device, const std::string &mapPath);

		void addMapFloor();
		void addMapBlock(irr::f32 x, irr::f32 y, irr::f32 z);
		irr::scene::ISceneManager *getSceneManager() const override;
	private:
		Eo::JsonRead _json;
		Eo::Map _map;
	};
}
#endif
