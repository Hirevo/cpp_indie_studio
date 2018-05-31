/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** AObject
*/

#pragma once

#include "AMovable.hpp"
#include "IObject.hpp"

namespace Eo {
	class AObject : public IObject, public AMovable {
	public:
		AObject(Eo::IObject::Type type,
			irr::scene::ISceneNode *node = nullptr,
			vec3 pos = vec3(0, 0, 0));
		virtual ~AObject() = 0;
		Eo::IObject::Type getType() const override;
		irr::scene::ISceneNode *getSceneNode() const override;
		void setSceneNode(irr::scene::ISceneNode *node) override;

	protected:
		Eo::IObject::Type _type;
		irr::scene::ISceneNode *_node;
		bool _hasNode;
		bool _placedInScene;

	private:
	};
};
