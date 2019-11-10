#pragma once
#include "GameObject.h"

class StoneColumn_2 :
	public GameObject
{
public:
	StoneColumn_2();

	void loadResource();

	void render();

	void update(float);

	void handlerInput(float);
};

