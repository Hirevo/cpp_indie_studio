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
		enum SoundType {
			EFFECT,
			MUSIC
		};
		enum FileLine {
			GVOLUME,
			EVOLUME,
			MVOLUME,
			GISMUTE,
			EISMUTE,
			MISMUTE
		};
		SoundDevice();
		void deleteSoundDevice();
		~SoundDevice();
		void play(const Eo::SoundDevice::SoundPath, bool loop = false);
		void playMusic(const std::string &path, bool loop = false);
		void playEffects(const std::string &path, bool loop = false);
		// Get Sound volume from 0 to 1.
		float getGeneralVolume() const;
		// Set Sound Volume from 0 to 1.
		void setGeneralVolume(const float volume);
		float getMusicVolume() const;
		void setMusicVolume(const float volume);
		float getEffectsVolume() const;
		void setEffectsVolume(const float volume);
		void mute();
		void muteEffects();
		void muteMusic();
		void unMute();
		void unMuteEffects();
		void unMuteMusic();
		void stop();
		void stopMusic();
		void stopEffects();
		bool generalIsMute() const;
		bool musicIsMute() const;
		bool effectsIsMute() const;
		static const std::unordered_map<SoundPath, std::string> _soundPath;
		static const std::unordered_map<SoundPath, SoundType> _soundType;
	private:
		irrklang::ISoundEngine *_music;
		irrklang::ISoundEngine *_effects;
		float _gVolume;
		float _eVolume;
		float _mVolume;
		bool _gIsMute;
		bool _eIsMute;
		bool _mIsMute;
	};
}


