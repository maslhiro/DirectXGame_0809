#include "Sound.h"

Sound* Sound::_instance;

Sound::~Sound()
{
}

Sound* Sound::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new Sound();
	}
	return _instance;
}

void Sound::loadSound(HWND hWnd)
{
	// Khởi tạo CSoundManager.
	DirectSound_Init(hWnd);

	CSound* sound = nullptr;

	////Boss
	sound = LoadSound("Resource//Sound//Boss_Tune.wav");
	_listSound[eIdSound::S_JAFAR_PLACE] = sound;

	sound = LoadSound("Resource//Sound//A_Whole_New_World.wav");
	_listSound[eIdSound::S_MENU] = sound;

	sound = LoadSound("Resource//Sound//Menu_Select.wav");
	_listSound[eIdSound::S_MENU_SELECT] = sound;

	sound = LoadSound("Resource//Sound//Arabian_Nights.wav");
	_listSound[eIdSound::S_SUTAN_DUNGEON] = sound;
}

bool Sound::isPlaying(int soundid)
{
	auto sound = _listSound[soundid];
	if (sound != nullptr)
	{
		return sound->IsSoundPlaying();
	}
	return false;
}

void Sound::setVolume(int vol)
{
	_volume = vol;
}

void Sound::setMute(bool mute)
{
	_mute = mute;
}

bool Sound::getMute()
{
	return _mute;
}

void Sound::play(int soundid)
{
	auto sound = _listSound[soundid];
	if (sound != nullptr && _mute == false)
	{
		PlaySound(sound, _volume);
	}
}
void Sound::playNew(int soundid)
{
	auto sound = _listSound[soundid];
	if (sound != nullptr && _mute == false)
	{
		auto newSound = new CSound(*sound);
		PlaySound(newSound);
	}
}
void Sound::playLoop(int soundid)
{
	auto sound = _listSound[soundid];
	if (sound != nullptr)
	{
		sound->Play(0, DSBPLAY_LOOPING);
	}
}
void Sound::stop(int soundid)
{
	auto sound = _listSound[soundid];
	if (sound != nullptr && _mute == false)
	{
		StopSound(sound);
	}
}

void Sound::stopAll()
{
	for (auto sound : _listSound)
	{
		if (sound.second->IsSoundPlaying())
		{
			this->stop(sound.first);
		}
	}
}

Sound::Sound()
{
	_mute = false;
	_volume = 5;
}