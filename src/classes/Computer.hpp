/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#pragma once

#include "AModel.hpp"
#include "ACharacter.hpp"
#include "Map.hpp"
#include "SoundDevice.hpp"
#include <vector>
#include <utility>
#include <random>

namespace Eo {
	class Computer : public AModel, public ACharacter {
	public:
		Computer(Eo::Rc<Eo::SoundDevice> sound,
			Eo::Rc<Eo::IScene> game, const Eo::vec3 &pos,
			Eo::u32 playerID);

		~Computer();
		Eo::vec3 getDirection() const;
		Eo::i32 getCounter() const;
		void searchDirection(Eo::Rc<Eo::Map> map);
		void updatePosition(Eo::Rc<Eo::Map> map);
		bool checkPoseBomb(Eo::Rc<Eo::Map> map);
		Eo::IObject::Type
		getObjectType(Eo::vec3 pos, Eo::Rc<Eo::Map> map);
		bool isValidDirection(Eo::vec3 pos, Eo::Rc<Eo::Map> map);
		void draw(Eo::Rc<Eo::IScene> game) override;
		void die() override;
		bool isDead() override;

	private:
		std::string _path;
		Eo::vec3 _dir;
		Eo::i32 _counter;
		Eo::Rc<Eo::SoundDevice> _sound;
	};
}