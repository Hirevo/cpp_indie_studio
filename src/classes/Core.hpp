/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#ifndef BOMBERMAN_CORE_HPP
#define BOMBERMAN_CORE_HPP

#include <memory>
#include <stack>
#include "irrlicht.h"
#include "Options.hpp"
#include "Camera.hpp"
#include "Game.hpp"
#include "Device.hpp"
#include "Debug.hpp"
#include "SceneHandler.hpp"

namespace Eo {
	class Core {
	public:
		Core();
		virtual ~Core();
	private:
		Eo::Options _options;
		Eo::Device _device;
		Eo::SceneHandler _sceneHandler;
		Eo::Camera _camera;
		Eo::Debug _debug;
		bool _debugMode;
	};


}

#endif
