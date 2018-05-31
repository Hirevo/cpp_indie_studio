/*
** EPITECH PROJECT, 2018
** indie_studio
** File description:
** AModel
*/

#pragma once

#include "AObject.hpp"
#include "IModel.hpp"
#include <string>

namespace Eo {
	class AModel : public IModel, public AObject {
	public:
		AModel(IObject::Type type, vec3 pos = vec3(0, 0, 0));
		AModel(IObject::Type type, const IScene *scene,
			const std::string &modelPath,
			vec3 pos = vec3(0, 0, 0));
		virtual ~AModel() = 0;
		void insertInScene(const Eo::IScene *scene) override;
		void removeFromScene(const Eo::IScene *scene) override;
		void updateInScene(const Eo::IScene *scene) override;
		void loadModel(const Eo::IScene *scene,
			const std::string &path) override;
		irr::scene::IAnimatedMesh *getMesh() const override;
		void setMesh(irr::scene::IAnimatedMesh *model) override;

	protected:
		irr::scene::IAnimatedMesh *_mesh;
		bool _hasMesh;

	private:
	};
};
