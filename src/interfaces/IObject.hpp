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
	class IObject : public virtual IMovable {
	public:
		enum Type {
			CHARACTER,
			CAMERA,
			FLOOR,
			WALL,
			BOMB
		};
		virtual ~IObject() = default;
		virtual Eo::IObject::Type getType() const = 0;
		virtual irr::scene::ISceneNode *getSceneNode() const = 0;
		virtual void setSceneNode(irr::scene::ISceneNode *node) = 0;
		virtual void insertInScene(const Eo::IScene *scene) = 0;
		virtual void removeFromScene(const Eo::IScene *scene) = 0;
		virtual void updateInScene(const Eo::IScene *scene) = 0;
		virtual void deleteNode(const Eo::IScene *scene) = 0;

	private:
	};
}

#endif
