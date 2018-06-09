/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#pragma once

#include "AModel.hpp"
#include "ACharacter.hpp"

namespace Eo {
	class Computer : public AModel, public ACharacter {
	public:
		Computer(Eo::Rc<Eo::IScene> game, const Eo::vec3 &pos,
			Eo::u32 playerID);

	private:
	};
}