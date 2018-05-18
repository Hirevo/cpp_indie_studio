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
