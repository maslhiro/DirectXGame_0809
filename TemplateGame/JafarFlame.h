#pragma once
#include "GameObject.h"

class JafarFlame :
	public GameObject
{
private:
	float _distance;
	float _waitTime;
public:
	JafarFlame();
	JafarFlame(int);

	void loadResource();

	void setDirection(bool);

	void render();

	void update(float);

	void handlerInput(float);
};

typedef JafarFlame* pJafarFlame;