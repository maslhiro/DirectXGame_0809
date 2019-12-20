#pragma once
#include "dxaudio.h"
#include <unordered_map>

enum eIdSound {
	S_JAFAR_PLACE = 0,
	S_MENU,
	S_SUTAN_DUNGEON,
	S_MENU_SELECT
};

class Sound
{
public:
	~Sound();

	static Sound* getInstance();

	void loadSound(HWND hWnd);

	void play(int soundid);

	void playNew(int soundid);					// nếu sound đang phát thì chạy đè lên

	void stop(int soundid);

	void stopAll();

	void playLoop(int soundid);

	bool isPlaying(int soundid);

	void setVolume(int vol);

	void setMute(bool mute);

	bool getMute();

private:
	Sound();

	static Sound* _instance;

	std::unordered_map<int, CSound*> _listSound;

	float _volume;

	bool _mute;
};

typedef Sound* pSound;