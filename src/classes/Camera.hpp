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
#pragma warning(disable : 4250)
	class Camera : public AObject {
	public:
		enum cameraType { NONE, FPS, STATIC };
		Camera(int mapSize, Eo::vec3 pos = Eo::vec3(0, 0, 0));
		~Camera();
		void insertFPSInScene(Eo::Rc<Eo::IScene> scene);
		void insertStaticInScene(Eo::Rc<Eo::IScene> scene);
		void insertInScene(const Eo::Rc<Eo::IScene> scene) override;
		void removeFromScene() override;
		void updateInScene() override;
		cameraType getCamType() const;
		irr::scene::ICameraSceneNode *getCameraHandle() const;

	private:
		irr::SKeyMap _keyMap[5];
		irr::scene::ICameraSceneNode *_camera;
		cameraType _camType = NONE;
		int mapSize;
	};
}
#endif
