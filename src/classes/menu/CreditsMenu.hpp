/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** CreditsMenu.hpp
*/

#ifndef BOMBERMAN_CREDITSMENU_HPP
	#define BOMBERMAN_CREDITSMENU_HPP

	#include <AScene.hpp>

namespace Eo {
	class CreditsMenu : public Eo::AScene {
	public:
		CreditsMenu(Eo::Rc<Eo::Event> event, Eo::Rc<Eo::Device> device, Eo::Rc<Eo::SceneHandler> sceneHandler, Eo::Rc<Eo::SoundDevice> sound);
		~CreditsMenu();
		bool draw() override;

		enum ButtonType {
			Return = 120
		};
	private:
		void putBackgroundImage();
		void putReturnButton();
		void addEvents(Eo::Rc<Eo::Event> event);
	};
}


#endif //BOMBERMAN_CREDITSMENU_HPP
