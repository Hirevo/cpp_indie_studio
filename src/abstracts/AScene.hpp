/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#pragma once

#include "IScene.hpp"
#include "Device.hpp"
#include "Event.hpp"

namespace Eo {
	class AScene : public IScene {
	public:
		AScene(Eo::Event &event, Eo::Device &device);
		virtual ~AScene() = 0;
		irr::scene::ISceneManager *getSceneManager() const override;
		irr::scene::ICameraSceneNode *getCamera() const override;
		bool clear() override;
		bool draw() override;
		void update() override;

	protected:
		Device _device;
		Event &_event;
 		irr::scene::ISceneManager *_sceneManager;
	};
};
