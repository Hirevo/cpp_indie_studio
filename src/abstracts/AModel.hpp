/*
** EPITECH PROJECT, 2018
** indie_studio
** File description:
** AModel
*/

#pragma once

#include "AObject.hpp"
#include "IModel.hpp"
#include "Types.hpp"
#include <string>

namespace Eo {
	class AModel : public IModel, public AObject {
	public:
		AModel(IObject::Type type, Eo::vec3 pos = Eo::vec3(0, 0, 0));
		virtual ~AModel() = 0;
		void insertInScene(const Eo::IScene *scene) override;
		void removeFromScene(const Eo::IScene *scene) override;
		void updateInScene(const Eo::IScene *scene) override;
		void deleteNode(const Eo::IScene *scene) override;
		void loadModel(const Eo::IScene *scene,
			const std::string &modelPath,
			const std::string &texPath) override;
		Eo::animatedMesh *getMesh() const override;
		void setMesh(Eo::animatedMesh *model) override;
		Eo::animatedNode *getAnimatedNode() const override;
		void animate(Eo::animType animation) const override;

	protected:
		Eo::animatedMesh *_mesh;
		Eo::animatedNode *_animatedNode;
		bool _hasMesh;

	private:
	};
};