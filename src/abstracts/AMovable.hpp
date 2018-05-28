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
		irr::core::vector3df getPosition() const override;
		void setPosition(const irr::core::vector3df &pos) override;
		void setPosition(float x, float y, float z) override;
		void setPosition(float v) override;
		void translate(const irr::core::vector3df &v) override;
		void translate(float v) override;
		void translate(float x, float y, float z) override;
		void translateX(float x) override;
		void translateY(float y) override;
		void translateZ(float z) override;
		bool hasPositionChanged() const override;
		void setPositionChanged(bool changed) override;
		void resetPositionChanged() override;

	protected:
		irr::core::vector3df _pos;
		bool _hasPositionChanged;

	private:
	};
};
