/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Scene.hpp"


Eo::Scene::Scene(Eo::Core &core)
{
	_sceneManager = core.get_device()->getSceneManager();
}

/*addCubeSceneNode(	f32 		size = 10.0f,
**			ISceneNode * 	parent = 0,
**			s32 		id = -1,
**const core::vector3df & 		position = core::vector3df(0, 0, 0),
**const core::vector3df & 		rotation = core::vector3df(0, 0, 0),
**const core::vector3df & 		scale = core::vector3df(1.0f, 1.0f, 1.0f)
*/
void Eo::Scene::addMapBlock()
{
	irr::scene::IMeshSceneNode* cube =
		sceneManager->addCubeSceneNode(
			10.0f,                             // cote de 10 unites
			0,                                 // parent = racine
			-1,                                // pas d'ID
			irr::core::vector3df(              // le vecteur de position
				0.0f,                          // origine en X
				0.0f,                          // origine en Y
				20.0f));
}
