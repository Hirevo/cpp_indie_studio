/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Debug.hpp"

Eo::Debug::Debug(Eo::Device &device, Eo::SceneHandler &sceneHandler)
	: _device(device),
	  _sceneHandler(sceneHandler)
{
}

Eo::Debug::~Debug()
{
}

void Eo::Debug::dumpDebug(IScene *scene, Eo::Game *game)
{
	dumpCameraPosTitleWindow(scene->getSceneManager());
	dumpCameraPos(scene->getSceneManager());
	toogleFpsCamera(scene, game);
}

void Eo::Debug::dumpCameraPos(irr::scene::ISceneManager *scene)
{
	if (_cameraPos) {
		irr::core::vector3df posCam;
		wchar_t titre[150];
		auto camera = scene->getActiveCamera();
		if (camera != nullptr) {
			posCam = camera->getPosition();
			swprintf(titre, 150, L"GET THE CAMERA >> FPS : %d"
					     "(mode debug) |  PosCam :  X :"
					     "%f Y : %f Z : %f",
				_device.getDriver()->getFPS(), posCam.X,
				posCam.Y, posCam.Z);
			scene->getGUIEnvironment()->addStaticText(titre,
				irr::core::rect<irr::s32>(100,20,400,60), true,
				        true, nullptr, -1, true);
		}
	}
}

void Eo::Debug::dumpCameraPosTitleWindow(irr::scene::ISceneManager *scene)
{
	if (_cameraPosTitleWindow) {
		irr::core::vector3df posCam;
		wchar_t titre[150];
		auto camera = scene->getActiveCamera();
		if (camera != nullptr) {
			posCam = camera->getPosition();
			swprintf(titre, 150, L"GET THE CAMERA >> FPS : %d"
					     "(mode debug) |  PosCam :  X :"
					     "%f Y : %f Z : %f",
				_device.getDriver()->getFPS(), posCam.X,
				posCam.Y, posCam.Z);
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

void Eo::Debug::clearDebugList(irr::scene::ISceneManager *scene)
{
	scene->getGUIEnvironment()->clear();
}

void Eo::Debug::toogleFpsCamera(IScene *scene, Eo::Game *game)
{
	if (game->get_camera().getCamType() != Eo::Camera::FPS) {
		game->get_camera().removeFromScene(scene);
		game->get_camera().insertFPSInScene(scene);
		std::cout << "loool\n";
	}
//	scene->setActiveCamera()
}
