/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** ACharacter
*/

#pragma once

#include "ICharacter.hpp"
#include "AModel.hpp"
#include "Types.hpp"

namespace Eo {
	class ACharacter : public ICharacter, public AModel {
	public:
		ACharacter(vec3 pos = vec3(0, 0, 0));
		ACharacter(const IScene *scene, const std::string &modelPath,
			vec3 pos = vec3(0, 0, 0));
		virtual ~ACharacter() = 0;

	protected:
		Eo::Rc<Eo::animatedMesh> _model;

	private:
	};
};
