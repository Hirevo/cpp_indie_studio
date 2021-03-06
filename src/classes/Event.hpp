/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#pragma once

#include "Types.hpp"
#include <functional>
#include <irrlicht.h>
#include <unordered_map>
#include <queue>

namespace Eo {
	class Event : public irr::IEventReceiver {
	public:
		struct pairHash {
			template <class T1, class T2>
			std::size_t operator () (const std::pair<T1,T2> &p) const {
				return std::hash<T1>{}(p.first) ^ std::hash<T2>{}(p.second);
			}
		};
		using keyHandle = std::pair<bool, Eo::keyHandler>;
		using keyMap = std::unordered_multimap<Eo::keyCode,
			Eo::Event::keyHandle>;
		using eventHandle = std::pair<bool, Eo::eventHandler>;
		using eventKey = std::pair<Eo::eventType, irr::s32>;
		using eventMap = std::unordered_multimap<Eo::Event::eventKey,
			Eo::Event::eventHandle, Eo::Event::pairHash>;
		Event();
		~Event() = default;
		virtual bool OnEvent(const Eo::event &event);
		void addKeyHandler(
			const Eo::keyCode &code, Eo::keyHandler handle);
		void addGUIHandler(
			const Eo::Event::eventKey &code,
			Eo::eventHandler handle);
		void clearKeyHandlers(const Eo::keyCode &code);
		void clearEventHandlers(const Eo::Event::eventKey &key);
		void scheduleTask(Eo::task task);
		void clearTasks();

	private:

		void handleKeyEvent(const Eo::event &event);
		void handleEvent(const Eo::event &event);
		void execTasks();
		Eo::Event::keyMap _keyMap;
		Eo::Event::eventMap _eventMap;
		std::queue<Eo::task> _tasks;
	};
}
