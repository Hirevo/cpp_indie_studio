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
#include <cstdlib>
#include <cstdio>

#ifdef _WIN32
	#include <process.h>
	#define GETPID _getpid
#elif __linux__
	#include <unistd.h>
	#define GETPID getpid
#endif

#ifdef WIN32
	#include <direct.h>
	#include <iostream>

	#define GetCurrentDir _getcwd
#elif __linux__
	#define GetCurrentDir getcwd
#endif

std::string Eo::currPath;
std::string Eo::map = "../map4.json";

int getCurrPath()
{
	char str[FILENAME_MAX];
	if (!GetCurrentDir(str, sizeof(str))) {
		return errno;
	}
	Eo::currPath = std::string(str);
	Eo::currPath += "/";
	return 0;
}

int main() {
	if (getCurrPath())
		return 84;
	srand(GETPID() * time(0));
	Eo::Rc<Eo::Options> options = Eo::initRc<Eo::Options>();
	Eo::Rc<Eo::Device> device = Eo::initRc<Eo::Device>(options);
	Eo::Core core(options, device);
	return 0;
}
