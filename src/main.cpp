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
#include <ctime>
#ifdef _WIN32
	#include <process.h>
	#define GETPID _getpid
#elif __linux__
	#include <unistd.h>
	#define GETPID getpid
#endif
#include <cstdlib>

int main() {
	srand(GETPID() * time(0));
	Eo::Rc<Eo::Options> options = Eo::initRc<Eo::Options>();
	Eo::Rc<Eo::Device> device = Eo::initRc<Eo::Device>(options);
	Eo::Core core(options, device);
	return 0;
}
