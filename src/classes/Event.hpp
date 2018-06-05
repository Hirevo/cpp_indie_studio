/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#pragma once

#include "Device.hpp"
#include "Options.hpp"
#include "SceneHandler.hpp"
#include "Types.hpp"
#include "Debug.hpp"
#include <functional>
#include <irrlicht.h>
#include <unordered_map>

namespace Eo {
	class Event : public irr::IEventReceiver {
	private:
		using keyHandle = std::pair<bool, Eo::keyHandler>;
		using keyMap = std::unordered_multimap<Eo::keyCode,
			Eo::Event::keyHandle>;

	public:
		Event(Eo::Options &, Eo::Device &device, Eo::SceneHandler &, Eo::Debug &);
		~Event() = default;
		virtual bool OnEvent(const Eo::event &event);
		void addKeyHandler(
			const Eo::keyCode &code, Eo::Event::keyHandle handle);
		void clearKeyHandlers(const Eo::keyCode &code);
		// Todo OUech polo doit travailler dessus
		// void removeKeyHandler(
		// 	const Eo::keyCode &code, Eo::Event::keyHandle handle);

	private:
		void handleKeyEvent(const Eo::event &event);
		Eo::Options &_options;
		Eo::Device &_device;
		Eo::SceneHandler &_sceneHandler;
		Eo::Event::keyMap _events;
		Eo::Debug &_debug;
		void keyExit(const Eo::event &event);
		void keyDebugToggle(const Eo::event &event);
	};
}
