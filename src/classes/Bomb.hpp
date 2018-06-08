/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#pragma once

#include "AModel.hpp"
#include "Game.hpp"
#include <chrono>

#define EXPLODE_DELAY (2000ms)

namespace Eo {
	class Bomb : public AModel {
	public:
		Bomb(Eo::Rc<Eo::Game> scene, const Eo::vec2i &mapPos,
			const Eo::vec3 &pos);
		~Bomb();
		bool update() override;
		void explode(Eo::Game *game);

	private:
		using ExplodeHandler = std::function<void(void)>;
		void propagateExplosion(
			Eo::vec2i pos, Eo::vec2i sizes, Eo::vec2i dir);
		void prepareExplosion(
			const Eo::vec2i &mapPos, Eo::Rc<Eo::Game> scene);
		ExplodeHandler _explode;
		std::chrono::time_point<std::chrono::high_resolution_clock>
			_clock;
		Eo::Rc<Eo::Game> _scene;
		Eo::Rc<Eo::Map> _map;
	};
}
