//
// EPITECH PROJECT, 2018
// IndieStudio
// File description:
// Player
//

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Core.hpp"
#include "irrlicht.h"
#include "Device.hpp"

namespace Eo {
	class Player {
	public:
		Player(Eo::Device &device, std::string const &modelPath, 
			std::string const &texturePath, 
			vec3 pos = vec3(0, 0, 0));
		~Player();
		irr::core::vector3df getPosition();
		void movePlayer(irr::core::vector3df &newPos);
		void animatePlayer(irr::scene::EMD2_ANIMATION_TYPE animation);

	private:
		irr::scene::IAnimatedMeshMD2* _modele;
		irr::scene::IAnimatedMeshSceneNode* _nmodele;
	};
}

#endif