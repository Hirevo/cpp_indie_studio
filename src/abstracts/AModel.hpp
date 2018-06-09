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
	#pragma warning(disable:4250)
	class AModel : public IModel, public AObject {
	public:
		AModel(IObject::Type type, Eo::vec3 pos = Eo::vec3(0, 0, 0));
		virtual ~AModel() = 0;
		void insertInScene(const Eo::Rc<Eo::IScene> scene) override;
		void updateInScene() override;
		void loadModel(const Eo::Rc<Eo::IScene> scene,
			const std::string &modelPath,
			const std::string &texPath) override;
		void loadModel(const Eo::Rc<Eo::IScene> scene,
			const std::string &modelPath) override;
		Eo::animatedMesh *getMesh() const override;
		void setMesh(Eo::animatedMesh *model) override;
		Eo::animatedNode *getAnimatedNode() const override;
		void animate(Eo::animType animation) const override;
		const vec3 &getScale() const;
		void setScale(const vec3 &_scale);

	protected:
		Eo::animatedMesh *_mesh;
		Eo::animatedNode *_animatedNode;
		bool _hasMesh;
		Eo::vec3 _scale = vec3(0.15f);
	public:
	};
};
