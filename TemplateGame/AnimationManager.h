#pragma once
#include "define.h"
#include "Animation.h"
#include "Texture.h"

class AnimationManager
{
public:
	AnimationManager();

	void init();
	static AnimationManager* getInstance();

	void add(eIdAnimation, Animation);
	Animation get(int);

	int draw(int);

private:
	static AnimationManager* _instance;

	pTexture _texture;
	pSprite _sprite;
	pDeviceManager _device;


	std::unordered_map<int, Animation> _listAnimation;
};

typedef AnimationManager* pAnimationManager;

