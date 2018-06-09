/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** ACharacter
*/

#pragma once

#include "ICharacter.hpp"
#include "Types.hpp"

namespace Eo {
	class ACharacter : public ICharacter {
	public:
		ACharacter(Eo::u32 playerID);
		virtual ~ACharacter() = 0;
		Eo::u32 getMaxBombs() const override;
		void setMaxBombs(Eo::u32 bombs) override;
		Eo::u32 getAvailableBombs() const override;
		void setAvailableBombs(Eo::u32 bombs) override;
		Eo::u32 getBombRadius() const override;
		void setBombRadius(Eo::u32 radius) override;
		Eo::f32 getSpeed() const override;
		void setSpeed(Eo::f32 speed) override;
		void setFlag(Eo::u8 flags) override;
		void unsetFlag(Eo::u8 flags) override;
		Eo::u8 getFlag() const override;
		Eo::u64 getPlayerID() const override;

	protected:
		Eo::u32 _availableBombs = 1;
		Eo::u32 _maxBombs = 3;
		Eo::u32 _bombRadius = 2;
		Eo::f32 _speed = 0.03f;
		Eo::u8 _flags = 0;
		Eo::u64 _playerID;

	private:
	};
};
