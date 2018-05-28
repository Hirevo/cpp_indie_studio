/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#ifndef BOMBERMAN_AWALL_HPP
#define BOMBERMAN_AWALL_HPP

#include "AMovable.hpp"
#include "AObject.hpp"

namespace Eo {
	class AWall : public AObject, public AMovable {
	public:
		enum WallType { DESTRUCTIBLE, INDESTRUCTIBLE };
		AWall(Eo::AWall::WallType type,
			irr::core::vector3df pos = irr::core::vector3df(
				0, 0, 0));
		~AWall() = default;
		void insertInScene(Eo::IScene *scene) override;
		void removeFromScene(Eo::IScene *scene) override;
		void updateInScene(Eo::IScene *scene) override;

	private:
		WallType _wallType;
	};
}

#endif
