#pragma once
#include "GameObject.h"

class Spike :
	public GameObject
{
private:
	float _waitTime;
public:
	Spike();
	Spike(int);

	void loadResource();

	void render();

	void update(float);

	void handlerInput(float);
};

