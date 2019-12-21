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
	sound = nullptr;
	sound = LoadSound("Resource//Sound//Boss_Tune.wav");
	_listSound[eIdSound::S_JAFAR_PLACE] = sound;

	sound = nullptr;
	sound = LoadSound("Resource//Sound//A_Whole_New_World.wav");
	_listSound[eIdSound::S_MENU] = sound;

	sound = nullptr;
	sound = LoadSound("Resource//Sound//Menu_Select.wav");
	_listSound[eIdSound::S_MENU_SELECT] = sound;

	sound = nullptr;
	sound = LoadSound("Resource//Sound//Arabian_Nights.wav");
	_listSound[eIdSound::S_SUTAN_DUNGEON] = sound;

	sound = nullptr;
	sound = LoadSound("Resource//Sound//Apple_Collect.wav");
	_listSound[eIdSound::S_APPLE_COLLECTION] = sound;

	sound = nullptr;
	sound = LoadSound("Resource//Sound//Coin_Collect.wav");
	_listSound[eIdSound::S_COIN_COLLECTION] = sound;

	sound = nullptr;
	sound = LoadSound("Resource//Sound//Extra_Health.wav");
	_listSound[eIdSound::S_EXTRA_HEALTH] = sound;

	sound = nullptr;
	sound = LoadSound("Resource//Sound//Genie_Head.wav");
	_listSound[eIdSound::S_GENIE_HEAD] = sound;

	sound = nullptr;
	sound = LoadSound("Resource//Sound//Save_Point.wav");
	_listSound[eIdSound::S_SAVE_POINT] = sound;

	sound = nullptr;
	sound = LoadSound("Resource//Sound//Rock.wav");
	_listSound[eIdSound::S_ROCK] = sound;

	sound = nullptr;
	sound = LoadSound("Resource//Sound//Enermy_Explode.wav");
	_listSound[eIdSound::S_ENERMY_EXPLODE] = sound;

	sound = nullptr;
	sound = LoadSound("Resource//Sound//Skeleton.wav");
	_listSound[eIdSound::S_SKELETON_EXPLODE] = sound;

	sound = nullptr;
	sound = LoadSound("Resource//Sound//Aladdin_Hurt.wav");
	_listSound[eIdSound::S_ALADDIN_HURT] = sound;

	sound = nullptr;
	sound = LoadSound("Resource//Sound//Attack.wav");
	_listSound[eIdSound::S_ALADDIN_ATTACK] = sound;

	sound = nullptr;
	sound = LoadSound("Resource//Sound//Aladdin_Push.wav");
	_listSound[eIdSound::S_ALADDIN_PUSH] = sound;

	sound = nullptr;
	sound = LoadSound("Resource//Sound//Apple_Throw.wav");
	_listSound[eIdSound::S_APPLE_THROW] = sound;

	sound = nullptr;
	sound = LoadSound("Resource//Sound//Nahbi_Wait.wav");
	_listSound[eIdSound::S_NAHBI_WAIT] = sound;

	//sound = nullptr;
	//sound = LoadSound("Resource//Sound//Cast_Register.wav");
	//_listSound[eIdSound::S_CASH_REGISTER] = sound;

	//sound = nullptr;
	//sound = LoadSound("Resource//Sound//Bones_Tinkle.wav");
	//_listSound[eIdSound::S_BONE_TINKLE] = sound;

	sound = nullptr;
	sound = LoadSound("Resource//Sound//Boxing_Bell.wav");
	_listSound[eIdSound::S_BOXING_BELL] = sound;

	sound = nullptr;
	sound = LoadSound("Resource//Sound//Jafar_Snake.wav");
	_listSound[eIdSound::S_JAFAR_SNAKE] = sound;
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
	_volume = 2;
}