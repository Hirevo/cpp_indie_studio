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
#include <iostream>

#ifdef _WIN32
	#include <process.h>
	#define GETPID _getpid
#elif __linux__
	#include <stdio.h>
	#include <unistd.h>
	#include <unistd.h>
	#define GETPID getpid
#endif

#ifdef WIN32
	#include <direct.h>
	#include <Windows.h>
	

	#define GetCurrentDir _getcwd
#elif __linux__
	#define GetCurrentDir getcwd
#endif
#include <filesystem>

std::string Eo::currPath;
std::string Eo::map = "assets/maps/map4.json";

int getCurrPath()
{
#ifdef __linux__
	char buffer[BUFSIZ];
	readlink("/proc/self/exe", buffer, BUFSIZ);
	Eo::currPath = std::string(buffer);
	std::filesystem::path p = Eo::currPath;
	Eo::currPath = std::string(p.parent_path().c_str());
#elif _WIN32
	LPWSTR buffer[2048];
	GetModuleFileName(NULL, buffer, 2048);
	Eo::currPath = std::string(buffer);
	std::filesystem::path p = Eo::currPath;
	Eo::currPath = std::string(p.parent_path().c_str());
#endif
	if (Eo::currPath.at(Eo::currPath.size() - 1) != '/')
		Eo::currPath += "/";
	return 0;
}

int main(int ac, char **av) {
	static_cast<void>(ac);
	std::cout << av[0] << std::endl;
	if (getCurrPath())
		return 84;
	srand(GETPID() * time(0));
	Eo::Rc<Eo::Options> options = Eo::initRc<Eo::Options>();
	Eo::Rc<Eo::Device> device = Eo::initRc<Eo::Device>(options);
	Eo::Core core(options, device);
	return 0;
}
