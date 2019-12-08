#pragma once
#include "GameObject.h"

class Skeleton :
	public GameObject
{
private:

public:
	Skeleton();
	Skeleton(int);

	void loadResource();

	void render();

	void update(float);

	void handlerInput(float);
};

