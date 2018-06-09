/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** main function to start the Bomberman
*/

#include <irrlicht.h>
#include "Types.hpp"
#include "Device.hpp"
#include "Options.hpp"
#include "Core.hpp"
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	srand(getpid() * time(0));
	Eo::Rc<Eo::Options> options = Eo::initRc<Eo::Options>();
	Eo::Rc<Eo::Device> device = Eo::initRc<Eo::Device>(options);
	Eo::Core core(options, device);
	return 0;
}
