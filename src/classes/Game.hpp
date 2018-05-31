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
#include "Camera.hpp"
#include "IScene.hpp"
#include "irrlicht.h"
#include "AScene.hpp"
#include <memory>
#include <stack>

namespace Eo {
	class Game : public AScene {
	public:
		Game(Eo::Device &device, const std::string &mapPath);
		~Game();
		irr::scene::ICameraSceneNode *getCamera() const override;

	private:
		Eo::JsonRead _json;
		Eo::Map _map;
		Eo::Camera _camera;
	};
}
#endif
