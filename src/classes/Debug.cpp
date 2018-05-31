/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Debug.hpp"

Eo::Debug::Debug(Eo::Device &device, Eo::IScene *scene)
	: _device(device), _scene(scene)
{
}

Eo::Debug::~Debug()
{
}

void Eo::Debug::dumpDebug()
{
	dumpCameraPosTitleWindow();
}

void Eo::Debug::dumpCameraPosTitleWindow()
{
	if (_cameraPosTitleWindow) {
		irr::core::vector3df posCam;
		wchar_t titre[150];
		auto camera = _scene->getSceneManager()->getActiveCamera();
		if (camera != nullptr) {
			posCam = camera->getPosition();
			swprintf(titre, 150, L"GET THE CAMERA >> FPS : %d"
					     "(mode debug) |  PosCam :  X :"
					     "%f Y : %f Z : %f",
				_device.getDriver()->getFPS(), posCam.X,
				posCam.Y,
				posCam.Z);
		}
		_device.getDevice()->setWindowCaption(titre);
	}
}

bool Eo::Debug::isCameraPosTitleWindow() const
{
	return _cameraPosTitleWindow;
}

void Eo::Debug::setCameraPosTitleWindow(bool _cameraPosTitleWindow)
{
	Debug::_cameraPosTitleWindow = _cameraPosTitleWindow;
}
