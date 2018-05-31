/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#ifndef BOMBERMAN_DEBUG_HPP
#define BOMBERMAN_DEBUG_HPP

#include "Game.hpp"
#include "Device.hpp"

namespace Eo {
	class Debug {
	public:
		Debug(Eo::Device &device, Eo::IScene *scene);
		virtual ~Debug();
	private:
		Eo::Device _device;
		Eo::IScene *_scene;
		bool _cameraPosTitleWindow = true;
		bool _cameraPos = true;
		void dumpCameraPosTitleWindow();
		void dumpCameraPos();
	public:
		void dumpDebug();
		bool isCameraPosTitleWindow() const;
		void setCameraPosTitleWindow(bool _cameraPosTitleWindow);
	};
}

#endif
