#pragma once
#include "GameObject.h"

class Bat :
	public GameObject
{
private:

public:
	Bat();
	Bat(int);

	void loadResource();

	void render();

	void update(float);

	void handlerInput(float);
};

