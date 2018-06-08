/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Wall
*/

#pragma once

#include "AMovable.hpp"
#include "AObject.hpp"
#include <unordered_map>

namespace Eo {
	class Wall : public AObject {
	public:
		enum WallType {
			DESTRUCTIBLE = Eo::IObject::Type::DEST_WALL,
			INDESTRUCTIBLE = Eo::IObject::Type::WALL
		};
		Wall(Eo::Wall::WallType type, vec3 pos = vec3(0, 0, 0));
		~Wall();
		void insertInScene(const Eo::Rc<Eo::IScene> scene) override;
		void updateInScene() override;

	private:
		WallType _wallType;
		static const std::unordered_map<WallType, std::string>
			_textures;
	};
}
