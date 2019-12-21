#pragma once
#include "GameObject.h"
#include "Sound.h"

class Rock :
	public GameObject
{
private:
	float _waitTime;
public:
	Rock();
	Rock(int);

	void loadResource();

	void render();

	void update(float);

	void handlerInput(float);
};

