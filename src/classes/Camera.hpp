/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#ifndef BOMBERMAN_CAMERA_HPP
#define BOMBERMAN_CAMERA_HPP

#include "AMovable.hpp"
#include "AObject.hpp"
#include "IScene.hpp"
#include "irrlicht.h"
#include <SKeyMap.h>

namespace Eo {
	class Camera : public AObject {
	public:
		Camera(vec3 pos = vec3(0, 0, 0));
		~Camera() = default;
		void insertInScene(const Eo::IScene *scene) override;
		void removeFromScene(const Eo::IScene *scene) override;
		void updateInScene(const Eo::IScene *scene) override;
		irr::scene::ICameraSceneNode *getCameraHandle() const;

	private:
		irr::SKeyMap _keyMap[5];
		irr::scene::ICameraSceneNode *_camera;
	};
}

#endif
