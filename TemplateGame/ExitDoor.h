#pragma once
#include "GameObject.h"

class ExitDoor :
	public GameObject
{
public:
	ExitDoor();

	void loadResource();

	void render();

	void update(float);

	void handlerInput(float);
};

