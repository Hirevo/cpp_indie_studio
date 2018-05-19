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
#include <Irrlicht.h>
#include "Options.hpp"
#include "Camera.hpp"
#include "Scene.hpp"
#include "Device.hpp"

namespace Eo {
	class Core {
	public:
		Core();
		virtual ~Core();
	private:
		Eo::Options _options;
		Eo::Device _device;
		Eo::Scene _scene;
		//Eo::Camera _camera;

		//std::stack<std::unique_ptr<Eo::Scene>> _stateMachine;
	};


}

#endif
