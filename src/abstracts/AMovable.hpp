/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** AMovable
*/

#pragma once

#include "interfaces/IMovable.hpp"

namespace Eo {
	class AMovable : public virtual IMovable {
	public:
		AMovable(irr::core::vector3df pos = irr::core::vector3df(
				0, 0, 0));
		~AMovable() = default;
		irr::core::vector3df getPosition() const final;
		void setPosition(const irr::core::vector3df &pos) final;
		void setPosition(float x, float y, float z) final;
		void setPosition(float v) final;
		void translate(const irr::core::vector3df &v) final;
		void translate(float v) final;
		void translate(float x, float y, float z) final;
		void translateX(float x) final;
		void translateY(float y) final;
		void translateZ(float z) final;
		bool hasPositionChanged() const final;
		void setPositionChanged(bool changed) final;
		void resetPositionChanged() final;

	protected:
		irr::core::vector3df _pos;
		bool _hasPositionChanged;

	private:
	};
};
