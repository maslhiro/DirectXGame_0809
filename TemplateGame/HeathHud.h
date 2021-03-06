#pragma once
#include "GameObject.h"

class HeathHud : GameObject
{
private:
public:

	HeathHud();
	~HeathHud();

	void loadResource();

	void setHealth(int);

	void render();

	void update(float);

	void handlerInput(float) {};
};

typedef HeathHud* pHeathHud;
