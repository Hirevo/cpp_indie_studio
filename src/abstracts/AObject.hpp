/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** AObject
*/

#pragma once

#include "interfaces/IObject.hpp"

namespace Eo {
	class AObject : public IObject {
	public:
		AObject(Eo::IObject::Type type = WALL,
			irr::scene::IMeshSceneNode *node = 0);
		~AObject() = default;
		Eo::IObject::Type getType() const override;
		irr::scene::IMeshSceneNode *getSceneNode() const override;
		void setSceneNode(irr::scene::IMeshSceneNode *node) override;
		void insertInScene(Eo::IScene *scene) override;
		void removeFromScene(Eo::IScene *scene) override;
		void updateInScene(Eo::IScene *scene) override;

	protected:
		Eo::IObject::Type _type;
		irr::scene::IMeshSceneNode *_node;
		bool _placedInScene;

	private:
	};
};
