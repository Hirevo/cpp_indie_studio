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
		Flame(Eo::Rc<Eo::IScene> scene,
			Eo::vec3 pos = Eo::vec3(0, 0, 0));
		~Flame() = default;
		bool update() override;
		void insertInScene(const Eo::Rc<Eo::IScene> scene) override;

	protected:
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock>
			_clock;
	};
};
