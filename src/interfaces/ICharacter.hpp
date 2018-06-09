/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#pragma once

#include "AObject.hpp"
#include <string>

namespace Eo {
	class ICharacter : public virtual IMovable {
	public:
		virtual ~ICharacter() = default;
		virtual Eo::u32 getMaxBombs() const = 0;
		virtual void setMaxBombs(Eo::u32 bombs) = 0;
		virtual Eo::u32 getAvailableBombs() const = 0;
		virtual void setAvailableBombs(Eo::u32 bombs) = 0;
		virtual Eo::u32 getBombRadius() const = 0;
		virtual void setBombRadius(Eo::u32 radius) = 0;
		virtual Eo::f32 getSpeed() const = 0;
		virtual void setSpeed(Eo::f32 speed) = 0;
		virtual void setFlag(Eo::u8 flags) = 0;
		virtual void unsetFlag(Eo::u8 flags) = 0;
		virtual Eo::u8 getFlag() const = 0;
		virtual Eo::u64 getPlayerID() const = 0;

	private:
	};
}
