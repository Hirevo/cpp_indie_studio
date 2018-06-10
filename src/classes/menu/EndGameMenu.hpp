/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** EndGameMenu.hpp
*/

#ifndef BOMBERMAN_ENDGAMEMENU_HPP
	#define BOMBERMAN_ENDGAMEMENU_HPP

	#include <AScene.hpp>

namespace Eo {
	class EndGameMenu : public AScene {
	public:
		EndGameMenu(Eo::Rc<Eo::Event> event, Eo::Rc<Eo::Device> device,
			Eo::Rc<Eo::SceneHandler> sceneHandler,
			Eo::Rc<Eo::SoundDevice> sound,
			std::vector<std::string> deathOrder);
		~EndGameMenu();
		bool draw() override;
		enum EventType { OK = 1249 };

	private:
		void putBackgroundImage();
		void putOkButton();
		void putTitle();
		std::vector<std::string> _deathOrder;
	};
}

#endif //BOMBERMAN_ENDGAMEMENU_HPP
