#pragma once
#include "define.h"
#include "Sprite.h"
#include "Texture.h"

class Animation
{
private:

	pSprite _sprite;

	float _timePerFrame;
	float _totalTime;

	// index frame hien tai va framcuoi
	int _currentFrame;

	// Vi tri vẽ sprite lên màn hình
	Vec3 _position;

	std::vector<int> _listSpriteId;
	// Fix pos cho từng frame , khi add 1 sprite mới sẽ tự fix pos frame đó với 
	std::vector<Vec3> _fixPosVec;

public:
	Animation();
	Animation(float);
	~Animation();

	void setTimePerFrame(float);

	void setPosition(Vec3);

	void init(float);

	void release();

	int getSprite(int);
	void addSprite(eIdSprite);
	int render(pDeviceManager, pTexture);
	int update(float);

	std::vector<int> getListSprite();
};

typedef Animation* pAnimation;

