/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#ifndef BOMBERMAN_RECEIVER_HPP
#define BOMBERMAN_RECEIVER_HPP

#include <irrlicht.h>

class CEventReceiver : public irr::IEventReceiver
{

public :

	//Le constructeur.
	CEventReceiver(irr::scene::IAnimatedMeshSceneNode* Nmodele);
	//Capte automatiquement les events.
	bool OnEvent(const irr::SEvent& event);
	//Met a jour la position du mesh.
	void majPosMesh();


private :

	//Le modele qu'on va controler.
	irr::scene::IAnimatedMeshSceneNode* m_Nmodele;
	//Indique si on est deja en mouvement ou pas.
	bool m_isMoving;

};

#endif
