#pragma once
#include "define.h"
#include "Sprite.h"
#include "Texture.h"

class Animation
{
private:

	float _timePerFrame;

	float _totalTime;
	int _currentFrame;

	std::vector<int> _listSpriteId;

public:
	Animation();
	Animation(float);
	~Animation();

	void setTimePerFrame(float);

	void init(float, std::vector<int>);

	void release();

	int getSprite(int);
	void addSprite(eIdSprite);
	int render(pDeviceManager, pTexture, pSprite);
	int update(float);

	std::vector<int> getListSprite();
};

typedef Animation* pAnimation;

