#pragma once
#include "GameObject.h"

class ExtraHealth :
	public GameObject
{
private:

public:
	ExtraHealth();
	ExtraHealth(int);

	void loadResource();

	void render();

	void update(float);

	void handlerInput(float);
};

