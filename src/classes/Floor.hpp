/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Floor
*/

#pragma once

#include "AMovable.hpp"
#include "AObject.hpp"

namespace Eo {
	class Floor : public AObject {
	public:
		Floor(size_t size,
			irr::core::vector3df pos = irr::core::vector3df(
				0, 0, 0));
		~Floor() = default;
		void insertFPSInScene(Eo::IScene *scene) override;
		void removeFromScene(Eo::IScene *scene) override;
		void updateInScene(Eo::IScene *scene) override;

	private:
		size_t _size;
	};
}
