/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#ifndef BOMBERMAN_CORE_HPP
#define BOMBERMAN_CORE_HPP

#include "Scene.hpp"

namespace Eo {
	class Core {
	public:
	private:
		std::stack<std::unique_ptr<Scene>> _stateMachine;
	};
}

#endif
