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
	#pragma warning(disable:4250)
	class AObject : public IObject, public AMovable {
	public:
		AObject(Eo::IObject::Type type,
			irr::scene::ISceneNode *node = nullptr,
			vec3 pos = vec3(0, 0, 0));
		virtual ~AObject() = 0;
		Eo::IObject::Type getType() const override;
		irr::scene::ISceneNode *getSceneNode() const override;
		void setSceneNode(irr::scene::ISceneNode *node) override;
		void insertInScene(const Eo::IScene *scene) override;
		void removeFromScene(const Eo::IScene *scene) override;
		void deleteNode(const Eo::IScene *scene) override;
		void updateInScene(const Eo::IScene *scene) override;

	protected:
		Eo::IObject::Type _type;
		irr::scene::ISceneNode *_node;
		bool _hasNode;
		bool _placedInScene;

	private:
	};
};
