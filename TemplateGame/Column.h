#pragma once
#include "GameObject.h"
class Column :
	public GameObject
{
public:
	Column();

	void loadResource();

	void render();

	void update(float);

	void handlerInput(float);
};

