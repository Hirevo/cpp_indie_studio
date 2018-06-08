/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#ifndef BOMBERMAN_DEBUG_HPP
#define BOMBERMAN_DEBUG_HPP

#include <list>
#include "Game.hpp"
#include "Device.hpp"
#include "SceneHandler.hpp"

namespace Eo {
	class Debug {
	public:
		Debug(Eo::Rc<Eo::Device> device, Eo::Rc<Eo::SceneHandler> scenehandler);
		virtual ~Debug();
		void dumpDebug(Eo::Rc<Eo::IScene> scene);
		void clearDebugList(irr::scene::ISceneManager *scene);
		bool isCameraPosTitleWindow() const;
		void setCameraPosTitleWindow(bool _cameraPosTitleWindow);
		//void toogleFpsCameraOff(Game *);
	private:
		Eo::Rc<Eo::Device> _device;
		Eo::Rc<Eo::SceneHandler> _sceneHandler;
		bool _cameraPosTitleWindow = true;
		bool _cameraPos = true;
		void dumpCameraPosTitleWindow(irr::scene::ISceneManager *scene);
		void dumpCameraPos(irr::scene::ISceneManager *scene);
		//void toogleFpsCameraOn(Eo::Game *);
	};
}

#endif
