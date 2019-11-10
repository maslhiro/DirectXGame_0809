#pragma once
#include "GameObject.h"
class WreckingBall :
	public GameObject
{
public:
	WreckingBall();

	void loadResource();

	void render();

	void update(float);

	void handlerInput(float);

};

