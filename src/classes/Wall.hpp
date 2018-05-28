/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Wall
*/

#pragma once

#include "AMovable.hpp"
#include "AObject.hpp"

namespace Eo {
	class Wall : public AObject {
	public:
		enum WallType { DESTRUCTIBLE, INDESTRUCTIBLE };
		Wall(Eo::Wall::WallType type,
			irr::core::vector3df pos = irr::core::vector3df(
				0, 0, 0));
		~Wall() = default;
		void insertInScene(Eo::IScene *scene) override;
		void removeFromScene(Eo::IScene *scene) override;
		void updateInScene(Eo::IScene *scene) override;

	private:
		WallType _wallType;
	};
}

