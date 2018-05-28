/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Debug.hpp"

Eo::Debug::Debug(Eo::Device &device, Eo::Scene &scene)
	: _device(device),
	  _scene(scene)
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
		wchar_t titre[100];
		posCam = _scene.get_sceneManager()->getActiveCamera()->getPosition();
		swprintf(titre, 100, L"FPS : %d (mode debug) |  PosCam :  "
				     "X : %f Y : %f Z : %f",
			_device.get_driver()->getFPS(), posCam.X, posCam.Y,
			posCam.Z);
		_device.get_device()->setWindowCaption(titre);
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
