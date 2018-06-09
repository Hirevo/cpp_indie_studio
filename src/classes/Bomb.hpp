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
		Bomb(Eo::Rc<Eo::Game> scene, Eo::Rc<Eo::ICharacter> player,
			const Eo::vec2i &mapPos, const Eo::vec3 &pos, Eo::Rc<Eo::SoundDevice> sound);
		~Bomb();
		bool update() override;

	private:
		enum BombSize {
			SMALL,
			MEDIUM,
			LARGE
		};
		using ExplodeHandler = std::function<void(void)>;
		void propagateExplosion(
			Eo::vec2i pos, Eo::vec2i sizes, Eo::vec2i dir);
		void prepareExplosion(
			const Eo::vec2i &mapPos, Eo::Rc<Eo::Game> scene);
		BombSize getBombSize() const;
		ExplodeHandler _explode;
		std::chrono::time_point<std::chrono::high_resolution_clock>
			_clock;
		Eo::Rc<Eo::Game> _scene;
		Eo::Rc<Eo::Map> _map;
		Eo::Rc<Eo::ICharacter> _player;
		Eo::Rc<Eo::SoundDevice> _sound;
		static const std::unordered_map<BombSize, Eo::SoundDevice::SoundPath> _soundPath;
	};
}
