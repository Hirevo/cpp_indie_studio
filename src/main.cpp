/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** main fucntion to start the bomberman
*/

#include <irrlicht/irrlicht.h>

int main() {
	irr::IrrlichtDevice *device = irr::createDevice(     // create device
		irr::video::EDT_OPENGL,                      // API is OpenGL
		irr::core::dimension2d<irr::u32>(800,600),   // window size 800x600
		32, false, true, false, 0);

	irr::video::IVideoDriver* driver =
		device->getVideoDriver();                    // create driver
	irr::scene::ISceneManager *sceneManager =
		device->getSceneManager ();                  // create scene manager

	sceneManager->addCameraSceneNode (0,                 // fix camera for no move
		irr::core::vector3df (0,0,0),
		irr::core::vector3df (5,0,0));

	while (device->run()) {
		driver->beginScene(                          // start render
			true,                                // clear back-buffer
			true,                                // clear z-buffer
			irr::video::SColor(255,255,255,255));// white background
		sceneManager->drawAll ();                    // calculate render
		driver->endScene ();                         // print render
	}

	device->drop ();                                     // free memory
	return 0;
}
