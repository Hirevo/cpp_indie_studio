/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#pragma once

#include "IObject.hpp"
#include "IScene.hpp"

namespace Eo {
	class ICharacter : public virtual IMovable {
	public:
		virtual ~ICharacter() = default;
		virtual Eo::u32 getMaxBombs() const = 0;
		virtual void setMaxBombs(Eo::u32 bombs) = 0;
		virtual bool isWallPass() const = 0;
		virtual void setWallPass(bool _wallPass) = 0;
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
		virtual void draw(Eo::Rc<Eo::IScene> game) = 0;

	private:
	};
}
