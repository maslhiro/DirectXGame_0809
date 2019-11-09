#pragma once
#include "GameObject.h"

class StoneColumn_1 :
	public GameObject
{
public:
	StoneColumn_1();

	void loadResource();

	void render();

	void update(float);

	void handlerInput();
};

