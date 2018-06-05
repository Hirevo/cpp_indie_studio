/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#ifndef BOMBERMAN_SCENE_HPP
#define BOMBERMAN_SCENE_HPP

#include "AScene.hpp"
#include "Camera.hpp"
#include "Device.hpp"
#include "IScene.hpp"
#include "JsonRead.hpp"
#include "Map.hpp"
#include "irrlicht.h"
#include <memory>
#include <stack>
#include <AModel.hpp>

namespace Eo {
	class Game : public AScene {
	public:
		Game(Eo::Event &event,
			Eo::Device &device,
			const std::string &mapPath,
			Eo::Options &options);
		~Game();
		irr::scene::ICameraSceneNode *getCamera() const override;
		bool draw() override;
		void addEvents(Eo::AModel *model);

	private:
		Eo::JsonRead _json;
		Eo::Map _map;
		Eo::Camera _camera;
		Eo::Options &_options;
	};
}
#endif
