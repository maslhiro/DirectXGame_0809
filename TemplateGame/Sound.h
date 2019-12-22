#pragma once
#include "dxaudio.h"
#include <DxErr.h>
#include <map>

enum eIdSound {
	S_JAFAR_PLACE = 0,
	S_MENU,
	S_SUTAN_DUNGEON,
	S_MENU_SELECT,
	S_APPLE_COLLECTION,
	S_COIN_COLLECTION,
	S_EXTRA_HEALTH,
	S_GENIE_HEAD,
	S_SAVE_POINT,
	S_ROCK,
	S_ENERMY_EXPLODE,
	S_APPLE_THROW,
	S_APPLE_EXPODE,
	S_APPLE_EXPODE_,
	S_SKELETON_EXPLODE,
	S_ALADDIN_HURT,
	S_ALADDIN_ATTACK,
	S_ALADDIN_PUSH,
	S_NAHBI_WAIT,
	S_BOXING_BELL,
	S_CASH_REGISTER,
	S_BONE_TINKLE,
	S_JAFAR_SNAKE,
	S_LEVEL_COMPLETE,
	S_PEDDLER_SHOP
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

	std::map<int, CSound*> _listSound;

	float _volume;

	bool _mute;
};

typedef Sound* pSound;