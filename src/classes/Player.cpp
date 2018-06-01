//
// EPITECH PROJECT, 2018
// IndieStudio
// File description:
// Player
//

#include "Player.hpp"

Eo::Player::Player(Eo::Device &device, std::string const &modelPath, 
	std::string const &texturePath, vec3 pos)
{
	auto sceneManager = device.getDevice()->getSceneManager();
	auto driver = device.getDriver();

	this->_modele = (irr::scene::IAnimatedMeshMD2*)sceneManager->getMesh(modelPath.c_str());
	this->_nmodele = sceneManager->addAnimatedMeshSceneNode(this->_modele);
 
	this->_nmodele->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	this->_nmodele->setFrameLoop(0, 0);
	this->_nmodele->setMaterialTexture(0, driver->getTexture(texturePath.c_str()));

	this->_nmodele->setPosition(pos);
}

Eo::Player::~Player()
{
}

irr::core::vector3df Eo::Player::getPosition()
{
	return this->_nmodele->getPosition();
}

void Eo::Player::movePlayer(irr::core::vector3df &newPos)
{
	this->_nmodele->setPosition(newPos);
}

void Eo::Player::animatePlayer(irr::scene::EMD2_ANIMATION_TYPE animation)
{
	this->_nmodele->setMD2Animation(animation);
}