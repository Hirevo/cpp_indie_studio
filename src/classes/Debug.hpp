/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#ifndef BOMBERMAN_DEBUG_HPP
#define BOMBERMAN_DEBUG_HPP

#include "Scene.hpp"
#include "Device.hpp"

namespace Eo {
	class Debug {
	public:
		Debug(Eo::Device &device, Eo::Scene &scene);
		virtual ~Debug();
	private:
		Eo::Device _device;
		Eo::Scene _scene;
		bool _cameraPosTitleWindow = true;
		void dumpCameraPosTitleWindow();
	public:
		void dumpDebug();
		bool isCameraPosTitleWindow() const;
		void setCameraPosTitleWindow(bool _cameraPosTitleWindow);
	};
}

#endif
