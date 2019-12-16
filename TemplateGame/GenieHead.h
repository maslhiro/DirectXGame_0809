#pragma once
#include "GameObject.h"

class GenieHead :
	public GameObject
{
private:
	float _moveTime;
public:
	GenieHead();
	GenieHead(int);

	void loadResource();

	void render();

	void update(float);

	void handlerInput(float);
};

