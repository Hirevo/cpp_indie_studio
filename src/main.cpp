/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** main fucntion to start the bomberman
*/

#ifdef _MSC_VER
#pragma comment(lib, "Irrlicht.lib")
#endif

#include <irrlicht.h>
#include "receiver.hpp"

int main() {

	//On rend invisible le curseur.
	device->getCursorControl ()-> setVisible (false);

	//Sydney
	irr::scene::IAnimatedMeshMD2* modele;
	modele = (irr::scene::IAnimatedMeshMD2*)sceneManager->getMesh("sydney.md2");
	irr::scene::IAnimatedMeshSceneNode* Nmodele =
		sceneManager->addAnimatedMeshSceneNode(modele);

	//On modifie les proprietes de Sydney
	Nmodele->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	Nmodele->setFrameLoop(0, 0);
	Nmodele->setMaterialTexture( 0, driver->getTexture("sydney.bmp") );

	//La camera
	irr::scene::ICameraSceneNode *camera;
	camera = sceneManager->addCameraSceneNodeFPS (0,100.0f,300.0f);

	//On cree le capteur d'event et on l'associe au device.
	CEventReceiver receiver(Nmodele);
	device->setEventReceiver(&receiver);

	irr::scene::IMeshSceneNode* cube =         // pointeur vers le node
		sceneManager->addCubeSceneNode(        // la creation du cube
			10.0f,                             // cote de 10 unites
			0,                                 // parent = racine
			-1,                                // pas d'ID
			irr::core::vector3df(              // le vecteur de position
				0.0f,                          // origine en X
				0.0f,                          // origine en Y
				20.0f));                       // +20 unites en Z

	cube->setMaterialFlag(irr::video::EMF_WIREFRAME, true);


	/* CAMERA */

	irr::SKeyMap keyMap[5];                    // re-assigne les commandes
	keyMap[0].Action = irr::EKA_MOVE_FORWARD;  // avancer
	keyMap[0].KeyCode = irr::KEY_KEY_Z;        // w
	keyMap[1].Action = irr::EKA_MOVE_BACKWARD; // reculer
	keyMap[1].KeyCode = irr::KEY_KEY_S;        // s
	keyMap[2].Action = irr::EKA_STRAFE_LEFT;   // a gauche
	keyMap[2].KeyCode = irr::KEY_KEY_Q;        // a
	keyMap[3].Action = irr::EKA_STRAFE_RIGHT;  // a droite
	keyMap[3].KeyCode = irr::KEY_KEY_D;        // d
	keyMap[4].Action = irr::EKA_JUMP_UP;       // saut
	keyMap[4].KeyCode = irr::KEY_SPACE;        // barre espace

	sceneManager->addCameraSceneNodeFPS(       // ajout de la camera FPS
		0,                                     // pas de noeud parent
		100.0f,                                // vitesse de rotation
		0.1f,                                  // vitesse de deplacement
		-1,                                    // pas de numero d'ID
		keyMap,                                // on change la keymap
		5);                                    // avec une taille de 5


	/* RENDU */

	irr::video::SColor color(                  // contient la couleur blanc
		255,                                   // composante A alpha (transparence)
		255,                                   // composante R rouge
		255,                                   // composante G verte
		255);                                  // composante B bleue

	while (device->run()) {                    // la boucle de rendu
		driver->beginScene(true, true, color); // demarre le rendu
		sceneManager->drawAll ();              // calcule le rendu
		driver->endScene ();                   // affiche le rendu
	}

	device->drop ();
	return 0;
}
