#pragma once
#include "GameObject.h"

class Apple :
	public GameObject
{
public:
	Apple();

	void loadResource();

	void render();

	void update(float);

	void handlerInput();
};

