#include "define.h"
#include "dxaudio.h"
#include <map>

using namespace std;

class Sound
{
public:
	~Sound();
	static Sound* getInstance();
	void loadSound(HWND hWnd);
	void Play(int soundid);
	void PlayNew(int soundid);					// nếu sound đang phát thì chạy đè lên
	void Stop(int soundid);
	void StopAll();
	void PlayLoop(int soundid);
	bool IsPlaying(int soundid);
	void setVolume(int vol);
	void setMute(bool mute);
	bool getMute();
private:
	Sound();
	static Sound* _instance;
	map<int, CSound*> _listSound;
	float _volume;
	bool _mute;
};

typedef Sound* pSound;