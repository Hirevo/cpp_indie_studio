/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** IMovable
*/

#pragma once

#include "irrlicht.h"

namespace Eo {
	class IMovable {
	public:
		virtual ~IMovable() = default;
		virtual irr::core::vector3df getPosition() const = 0;
		virtual void setPosition(const irr::core::vector3df &pos) = 0;
		virtual void setPosition(float x, float y, float z) = 0;
		virtual void setPosition(float v) = 0;
		virtual void translate(const irr::core::vector3df &v) = 0;
		virtual void translate(float v) = 0;
		virtual void translate(float x, float y, float z) = 0;
		virtual void translateX(float x) = 0;
		virtual void translateY(float y) = 0;
		virtual void translateZ(float z) = 0;
		virtual bool hasPositionChanged() const = 0;
		virtual void setPositionChanged(bool changed) = 0;
		virtual void resetPositionChanged() = 0;

	protected:
	private:
	};
};
