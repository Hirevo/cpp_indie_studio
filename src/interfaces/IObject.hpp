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
			NONE,
			CHARACTER,
			CAMERA,
			FLOOR,
			FLAME,
			WALL,
			DEST_WALL,
			BOMB,
			BOOSTER_NONE,
			BOOSTER_SPEED,
			BOOSTER_SUPERBOMB,
			BOOSTER_NBBOMB,
			BOOSTER_WALLPASS
		};
		virtual ~IObject() = default;
		virtual Eo::IObject::Type getType() const = 0;
		virtual Eo::node *getSceneNode() const = 0;
		virtual void setSceneNode(Eo::node *node) = 0;
		virtual void insertInScene(const Eo::Rc<Eo::IScene> scene) = 0;
		virtual void removeFromScene() = 0;
		virtual void updateInScene() = 0;
		virtual bool update() = 0;
		virtual void setHasNode(bool b) = 0;
		virtual void setPlacedInScene(bool b) = 0;

	private:
	};
}

#endif
