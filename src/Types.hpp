/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** types
*/

#pragma once

#include <functional>
#include <irrlicht.h>
#include <memory>
#include <utility>
#include <string>

namespace Eo {
	class Device;
	class Options;
	class SceneHandler;
	template <typename T>
	using Rc = std::shared_ptr<T>;
	template <typename T>
	using Un = std::unique_ptr<T>;
	using vec3 = irr::core::vector3df;
	using vec2 = irr::core::vector2df;
	using vec3i = irr::core::vector3di;
	using vec2i = irr::core::vector2di;
	using color = irr::video::SColor;
	using event = irr::SEvent;
	using eventType = irr::gui::EGUI_EVENT_TYPE;
	using eventHandler = std::function<void(bool &, const Eo::event &)>;
	using keyCode = irr::EKEY_CODE;
	using keyHandler = std::function<void(bool &, const Eo::event &)>;
	using task = std::function<void(void)>;
	using animType = irr::scene::E_BONE_ANIMATION_MODE;
	using node = irr::scene::ISceneNode;
	using cameraNode = irr::scene::ICameraSceneNode;
	using animatedNode = irr::scene::IAnimatedMeshSceneNode;
	using animatedMesh = irr::scene::IAnimatedMesh;
	using u8 = std::uint8_t;
	using u16 = std::uint16_t;
	using u32 = std::uint32_t;
	using u64 = std::uint64_t;
	using i8 = std::int8_t;
	using i16 = std::int16_t;
	using i32 = std::int32_t;
	using i64 = std::int64_t;
	using f32 = float;
	using f64 = double;
	extern std::string currPath;
	template<typename T, typename... Args>
	Eo::Rc<T> initRc(Args&&... args) {
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
	template<typename T, typename... Args>
	Eo::Rc<T> initUn(Args&&... args) {
		return std::make_unique<T>(std::forward<Args>(args)...);
	}
	enum ButtonType {
		Return = 120
	};
};
