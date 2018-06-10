/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Wall
*/

#pragma once

#include "AMovable.hpp"
#include "AModel.hpp"
#include <unordered_map>

namespace Eo {
	class Wall : public AModel {
	public:
		enum WallType {
			DESTRUCTIBLE = Eo::IObject::Type::DEST_WALL,
			INDESTRUCTIBLE = Eo::IObject::Type::WALL,
			BOUNDS = Eo::IObject::Type::WALL
				+ Eo::IObject::Type::DEST_WALL
		};
		Wall(Eo::Wall::WallType type, vec3 pos = vec3(0, 0, 0));
		~Wall();
		void insertInScene(const Eo::Rc<Eo::IScene> scene) override;
		void updateInScene() override;

	private:
		WallType _wallType;
		std::unordered_map<WallType, std::string>
			_textures;
		std::unordered_map<WallType, std::string>
			_models;
	};
}
