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
			Eo::Rc<Eo::SoundDevice> sound);
		~EndGameMenu();
		bool draw() override;
		enum EventType { OK = 185 };

	private:
		void putBackgroundImage();
	};
}

#endif //BOMBERMAN_ENDGAMEMENU_HPP
