#pragma once
#include "GameObject.h"
class Rope :
	public GameObject
{
public:
	Rope();

	void loadResource();

	void render();

	void update(float);

	void handlerInput(float);
};

