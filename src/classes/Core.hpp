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
#include "Event.hpp"
#include "SoundDevice.hpp"

namespace Eo {
	class Core {
	public:
		Core();
		virtual ~Core();
	private:
		Eo::Rc<Eo::Options> _options;
		Eo::Rc<Eo::Device> _device;
		Eo::Rc<Eo::SceneHandler> _sceneHandler;
		Eo::Rc<Eo::Debug> _debug;
		Eo::Rc<Eo::Event> _event;
		Eo::Rc<Eo::SoundDevice> _sound;
	public:

	};
}

#endif
