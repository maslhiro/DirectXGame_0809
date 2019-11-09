#pragma once
#include "GameObject.h"

class StoneColumn_4 :
	public GameObject
{
public:
	StoneColumn_4();

	void loadResource();

	void render();

	void update(float);

	void handlerInput();
};

