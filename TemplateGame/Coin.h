#pragma once
#include "GameObject.h"

class Coin :
	public GameObject
{
private:

public:
	Coin();
	Coin(int);

	void loadResource();

	void render();

	void update(float);

	void handlerInput(float);
};

