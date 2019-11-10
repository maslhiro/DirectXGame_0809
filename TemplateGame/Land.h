#pragma once
#include "GameObject.h"
class Land :
	public GameObject
{
public:
	Land();

	void loadResource();

	void render();

	void update(float);

	void handlerInput(float);
};

