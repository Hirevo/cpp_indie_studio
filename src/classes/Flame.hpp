/*
** EPITECH PROJECT, 2018
** indie-studio
** File description:
** Flame
*/

#pragma once

#include "AModel.hpp"
#include <chrono>

#define BURN_TIME (500ms)

namespace Eo {
	class Flame : public AModel {
	public:
		Flame(Eo::vec3 pos = Eo::vec3(0, 0, 0));
		~Flame() = default;
		bool update() override;

	protected:
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock>
			_clock;
	};
};
