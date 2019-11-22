#pragma once
#include "GameObject.h"
class Ground :
	public GameObject
{
public:
	Ground();

	void loadResource();

	void render();

	void update(float);

	void handlerInput(float);
};

