/*
** EPITECH PROJECT, 2018
** indie_studio
** File description:
** IModel
*/

#pragma once

#include "Types.hpp"
#include <string>

namespace Eo {
	class IModel {
	public:
		virtual ~IModel() = default;
		virtual void loadModel(const Eo::Rc<Eo::IScene> scene,
			const std::string &modelPath,
			const std::string &texPath) = 0;
		virtual Eo::animatedMesh *getMesh() const = 0;
		virtual void setMesh(Eo::animatedMesh *model) = 0;
		virtual Eo::animatedNode *getAnimatedNode() const = 0;
		virtual void animate(Eo::animType animation) const = 0;

	protected:
	private:
	};
};
