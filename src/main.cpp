/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** main fucntion to start the bomberman
*/

#include <irrlicht.h>

int main(void) {

	irr::IrrlichtDevice* device = irr::createDevice(irr::video::EDT_OPENGL,
		irr::core::dimension2d<irr::u32>(640,480), 32);
	irr::video::IVideoDriver* driver = device->getVideoDriver();
	irr::scene::ISceneManager* sceneManager = device->getSceneManager();


	/* MODELE */

	irr::scene::IAnimatedMeshSceneNode* sphere =        // cree un scene node nomme sphere
		sceneManager->addAnimatedMeshSceneNode (          // via le scene manager
			sceneManager->getMesh ("/opt/irrlicht-1.8.4/media/earth.x"),              // en chargeant le mesh "earth.x"
			0, -1,                                          // pas de parent, pas d'ID
			irr::core::vector3df(0.0f, 0.0f, 25.0f),        // position de la sphere
			irr::core::vector3df(0.0f, 0.0f, 0.0f),         // rotation
			irr::core::vector3df(15.0f, 15.0f, 15.0f));     // echelle

	irr::scene::IAnimatedMeshSceneNode* sydney =        // cree un scene node nomme sydney
		sceneManager->addAnimatedMeshSceneNode (          // via le scene manager
			sceneManager->getMesh ("sydney.md2"));          // en chargeant le mesh "sydney.md2"


	/* OVERRIDE MATERIAL */

	driver->getOverrideMaterial().EnableFlags =         // indique que le flag EMF_WIREFRAME
		irr::video::EMF_WIREFRAME;                        // va etre outrepasse
	driver->getOverrideMaterial().Material.setFlag(     // active le flag EMF_WIREFRAME
		irr::video::EMF_WIREFRAME, true);                 // de l'override material
	driver->getOverrideMaterial().EnablePasses =        // indique le type de node affectes
		irr::scene::ESNRP_SOLID;                          // par l'override material


	/* CAMERA */

	sceneManager->addCameraSceneNode(0,                 // cree une camera fixe
		irr::core::vector3df(40.0f, 10.0f, 15.0f),        // position de la cam
		irr::core::vector3df(0.0f, 9.0f, 15.0f));         // cible de la cam


	/* RENDU */

	while (device->run()) {                        // la boucle de rendu
		driver->beginScene(true, true,               // demarre le rendu
			irr::video::SColor(0,255,255,255));        // couleur blanche
		sceneManager->drawAll ();                    // calcule le rendu
		driver->endScene ();                         // affiche le rendu
	}

	device->drop ();                               // libere la memoire
	return 0;
}
