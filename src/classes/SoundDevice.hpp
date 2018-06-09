//
// EPITECH Project, 2018
// bomberman
// File description:
// SoundDevice.hpp
//

#pragma once

#include <irrKlang.h>
#include <string>
#include <unordered_map>

namespace Eo {
	class SoundDevice {
	public:
		enum SoundPath {
			NONE,
			MENUBGM,
			GAMEBGM,
			PAUSE,
			CONFIRM,
			RESET,
			SELECT,
			BOMBS,
			BOMBM,
			BOMBL,
			PLAY,
			SETBOMB,
			DEATH,
			GETITEM,
			HURRY
		};
		SoundDevice();
		~SoundDevice();
		void play(const std::string &path, bool loop = false);
		// Get Sound volume from 0 to 1.
		float getVolume() const;
		// Set Sound Volume from 0 to 1.
		void setVolume(const float volume);
		void stop();
		static const std::unordered_map<SoundPath, std::string> _soundPath;
	private:
		irrklang::ISoundEngine *_device;
	};
}


