/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#pragma once

#include "Device.hpp"
#include "Event.hpp"
#include "IScene.hpp"

namespace Eo {
	class AScene : public IScene {
	public:
		AScene(Eo::Rc<Eo::Event> event, Eo::Rc<Eo::Device> device,
			Eo::Rc<Eo::SceneHandler> _sceneHandler);

		virtual ~AScene() = 0;
		irr::scene::ISceneManager *getSceneManager() const override;
		irr::scene::ICameraSceneNode *getCamera() const override;
		bool clear() override;
		bool draw() override;
		void update() override;

	protected:
		Eo::Rc<Eo::Device> _device;
		Eo::Rc<Eo::Event> _event;
		irr::scene::ISceneManager *_sceneManager;
		Eo::Rc<Eo::SceneHandler> _sceneHandler;
	};
};
