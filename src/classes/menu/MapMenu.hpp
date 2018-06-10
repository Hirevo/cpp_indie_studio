/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** MapMenu.hpp
*/

#ifndef BOMBERMAN_MAPMENU_HPP
#define BOMBERMAN_MAPMENU_HPP

#include <map>
#include <vector>
#include <AScene.hpp>

namespace Eo {
	class MapMenu : public Eo::AScene {
	public:
		MapMenu(Eo::Rc<Eo::Event> event, Eo::Rc<Eo::Device> device, Eo::Rc<Eo::SceneHandler> sceneHandler, Eo::Rc<Eo::SoundDevice> sound);
		~MapMenu();
		bool draw() override;

		enum ButtonType {
			Return = 120,
			Load
		};
	private:
		std::vector<std::string> _loadMap;
		std::map<std::string, std::string> _path;
		void putLoadButton();
		void putBackgroundImage();
		void putReturnButton();
		void putTitle();
	};
}

#endif /* !BOMBERMAN_MAPMENU_HPP */
