/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** main fucntion to start the bomberman
*/

#include <irrlicht.h>
#include "receiver.hpp"

int main(void)
{

	//Device, driver et graphe de scene.
	irr::IrrlichtDevice* device = irr::createDevice(irr::video::EDT_OPENGL,
		irr::core::dimension2d<irr::u32>(800,800),32,false,false,false);
	irr::video::IVideoDriver* driver = device->getVideoDriver ();
	irr::scene::ISceneManager *sceneManager = device->getSceneManager ();

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

	//La boucle de rendu
	while (device->run())
	{
		driver->beginScene(true, true, irr::video::SColor(0,200,200,200));
		//Met a jour la position du mesh
		receiver.majPosMesh();
		sceneManager->drawAll ();
		driver->endScene ();
	}

	device->drop ();
	return 0;
}
