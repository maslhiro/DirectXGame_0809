#pragma once
#include "GameObject.h"

class AppleHud : GameObject
{
private:
	int _numApple;
	Animation _cha01, _cha02;
public:

	AppleHud();
	~AppleHud();

	void loadResource();

	void setNumApple(int);

	void render();

	void update(float);

	void handlerInput(float) {};
};

typedef AppleHud* pAppleHud;
