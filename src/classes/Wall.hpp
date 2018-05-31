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
		Wall(Eo::Wall::WallType type, vec3 pos = vec3(0, 0, 0));
		~Wall() = default;
		void insertInScene(const Eo::IScene *scene) override;
		void removeFromScene(const Eo::IScene *scene) override;
		void updateInScene(const Eo::IScene *scene) override;

	private:
		WallType _wallType;
	};
}
