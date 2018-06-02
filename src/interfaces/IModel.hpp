/*
** EPITECH PROJECT, 2018
** indie_studio
** File description:
** IModel
*/

#pragma once

#include <string>

namespace Eo {
	class IModel {
	public:
		virtual ~IModel() = default;
		virtual void loadModel(const IScene *scene, const std::string &path) = 0;
		virtual irr::scene::IAnimatedMesh *getMesh() const = 0;
		virtual void setMesh(irr::scene::IAnimatedMesh *model) = 0;

	protected:
	private:
	};
};
