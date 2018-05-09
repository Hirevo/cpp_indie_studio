/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** main fucntion to start the bomberman
*/

#include <irrlicht.h>


int main(void) {

	irr::IrrlichtDevice* device = irr::createDevice(    // creation du device
		irr::video::EDT_OPENGL,                           // API = OpenGL
		irr::core::dimension2d<irr::u32>(640,480),        // taille fenetre 640x480p
		32);                                              // 32 bits par pixel
	irr::video::IVideoDriver* driver =                  // creation du driver video
		device->getVideoDriver ();
	irr::scene::ISceneManager* sceneManager =           // creation du scene manager
		device->getSceneManager ();
	device->getCursorControl ()-> setVisible (false);   // rend le curseur invisible


	/* MODELE */

	irr::scene::IAnimatedMeshSceneNode *sydney =        // cree un scene node nomme sydney
		sceneManager->addAnimatedMeshSceneNode (          // via le scene manager
			sceneManager->getMesh ("sydney.md2"));          // en chargeant le mesh "sydney.md2"

	sydney->setMaterialFlag(
		irr::video::EMF_LIGHTING, false);
	sydney->setMaterialTexture(
		0, driver->getTexture("sydney.bmp"));

	sydney->setMD2Animation(irr::scene::EMAT_STAND);    // joue l'animation STAND en boucle


	/* CAMERA */

	irr::SKeyMap keyMap[5];                             // re-assigne les commandes
	keyMap[0].Action = irr::EKA_MOVE_FORWARD;           // avancer
	keyMap[0].KeyCode = irr::KEY_KEY_W;                 // w
	keyMap[1].Action = irr::EKA_MOVE_BACKWARD;          // reculer
	keyMap[1].KeyCode = irr::KEY_KEY_S;                 // s
	keyMap[2].Action = irr::EKA_STRAFE_LEFT;            // a gauche
	keyMap[2].KeyCode = irr::KEY_KEY_A;                 // a
	keyMap[3].Action = irr::EKA_STRAFE_RIGHT;           // a droite
	keyMap[3].KeyCode = irr::KEY_KEY_D;                 // d
	keyMap[4].Action = irr::EKA_JUMP_UP;                // saut
	keyMap[4].KeyCode = irr::KEY_SPACE;                 // barre espace

	sceneManager->addCameraSceneNodeFPS(                // ajout de la camera FPS
		0, 100.0f, 0.1f, -1, keyMap, 5);


	/* RENDU */

	while (device->run()) {                             // la boucle de rendu
		driver->beginScene(true, true,                    // demarre le rendu
			irr::video::SColor(0,255,255,255));
		sceneManager->drawAll ();                         // calcule le rendu
		driver->endScene ();                              // affiche le rendu
	}

	device->drop ();                                    // libere la memoire
	return 0;
}
