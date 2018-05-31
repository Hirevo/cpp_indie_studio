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
		Camera(irr::core::vector3df pos = irr::core::vector3df(0, 0, 0));
		~Camera() = default;
		void insertFPSInScene(Eo::IScene *scene) override;
		void insertStaticInScene(Eo::IScene *scene) override;
		void removeFromScene(Eo::IScene *scene) override;
		void updateInScene(Eo::IScene *scene) override;
		irr::scene::ICameraSceneNode *getCameraHandle() const;

	private:
		irr::SKeyMap _keyMap[5];
		irr::scene::ICameraSceneNode *_camera;
	};
}

#endif
