#pragma once
#include "define.h"
#include "Animation.h"
#include "Texture.h"

class AnimationManager
{
public:
	AnimationManager();

	void load();

	static AnimationManager* getInstance();

	void add(eIdAnimation, Animation);
	Animation get(int);

private:
	static AnimationManager* _instance;

	std::unordered_map<int, Animation> _listAnimation;
};

typedef AnimationManager* pAnimationManager;

