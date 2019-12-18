#pragma once
#include "GameObject.h"

class SavePoint :
	public GameObject
{
private:

public:
	SavePoint();
	SavePoint(int);

	void loadResource();

	void render();

	void update(float);

	void handlerInput(float);
};

