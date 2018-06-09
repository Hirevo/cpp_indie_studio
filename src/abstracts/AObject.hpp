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
#pragma warning(disable : 4250)
	class AObject : public IObject, public AMovable {
	public:
		AObject(Eo::IObject::Type type, Eo::node *node = nullptr,
			vec3 pos = vec3(0, 0, 0));
		virtual ~AObject() = 0;
		Eo::IObject::Type getType() const override;
		Eo::node *getSceneNode() const override;
		void setSceneNode(Eo::node *node) override;
		void insertInScene(const Eo::Rc<Eo::IScene> scene) override;
		void removeFromScene() override;
		void updateInScene() override;
		bool update() override;
		void setHasNode(bool b) override;
		void setPlacedInScene(bool b) override;

	protected:
		Eo::IObject::Type _type;
		Eo::node *_node;
		bool _hasNode;
		bool _placedInScene;

	private:
	};
};
