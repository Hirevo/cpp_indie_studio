/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#pragma once

#include "AModel.hpp"

namespace Eo {
	class Computer : public AModel {
	public:
		Computer(Eo::Rc<Eo::IScene> game, const Eo::vec3 &pos);
	private:
	};
}