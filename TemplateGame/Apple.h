#pragma once
#include "GameObject.h"

class Apple :
	public GameObject
{
private:

public:
	Apple();
	Apple(int);

	void loadResource();

	void render();

	void update(float);

	void handlerInput(float);
};

