#pragma once
#include "GameObject.h"

class StoneColumn_3 :
	public GameObject
{
public:
	StoneColumn_3();

	void loadResource();

	void render();

	void update(float);

	void handlerInput(float);
};

