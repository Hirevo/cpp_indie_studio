/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#ifndef BOMBERMAN_IOBJECT_HPP
#define BOMBERMAN_IOBJECT_HPP

#include "irrlicht.h"
#include "IMovable.hpp"
#include "IScene.hpp"

namespace Eo {
	class IObject {
	public:
		enum Type {
			WALL,
			BOMB
		};
		virtual ~IObject() = default;
		virtual Eo::IObject::Type getType() const = 0;
		virtual irr::scene::IMeshSceneNode *getSceneNode() = 0;
		virtual void setSceneNode(irr::scene::IMeshSceneNode *node) = 0;
		virtual void insertInScene(Eo::IScene *scene) = 0;
		virtual void removeFromScene(Eo::IScene *scene) = 0;
		virtual void updateInScene(Eo::IScene *scene) = 0;

	private:
	};
}

#endif
