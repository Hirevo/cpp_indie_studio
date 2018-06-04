/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** types
*/

#pragma once

#include <functional>
#include <irrlicht.h>

namespace Eo {
	class Device;
	class Options;
	class SceneHandler;
	using vec3 = irr::core::vector3df;
	using event = irr::SEvent;
	using eventType = irr::gui::EGUI_EVENT_TYPE;
	using eventHandler = std::function<void(
		Eo::Device &, Eo::Options &, Eo::SceneHandler &)>;
	using keyCode = irr::EKEY_CODE;
	using keyHandler = std::function<void(bool &, const irr::SEvent &)>;
	using animType = irr::scene::EMD2_ANIMATION_TYPE;
	using node = irr::scene::ISceneNode;
	using cameraNode = irr::scene::ICameraSceneNode;
	using animatedNode = irr::scene::IAnimatedMeshSceneNode;
	using animatedMesh = irr::scene::IAnimatedMesh;
};
