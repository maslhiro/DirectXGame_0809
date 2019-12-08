#pragma once
#include "GameObject.h"

class Nahbi :
	public GameObject
{
private:

public:
	Nahbi();
	Nahbi(int);

	void loadResource();

	void render();

	void update(float);

	void handlerInput(float);
};

