/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** AMovable
*/

#pragma once

#include "IMovable.hpp"
#include "Types.hpp"

namespace Eo {
	#pragma warning(disable:4250)
	class AMovable : public virtual IMovable {
	public:
		AMovable(vec3 pos = vec3(0, 0, 0));
		virtual ~AMovable() = 0;
		vec3 getPosition() const final;
		void setPosition(const vec3 &pos) final;
		void setPosition(float x, float y, float z) final;
		void setPosition(float v) final;
		void translate(const vec3 &v) final;
		void translate(float v) final;
		void translate(float x, float y, float z) final;
		void translateX(float x) final;
		void translateY(float y) final;
		void translateZ(float z) final;
		bool hasPositionChanged() const final;
		void setPositionChanged(bool changed) final;
		void resetPositionChanged() final;

	protected:
		vec3 _pos;
		bool _hasPositionChanged;

	private:
	};
};
