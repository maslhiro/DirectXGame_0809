#pragma once
#include "GameObject.h"

class Bat :
	public GameObject
{
private:
	Vec3 posPlayer;
	float _backwardTime;

	int _isFly;

public:
	Bat();
	Bat(int);

	void loadResource();

	void setPosPlayer(Vec3);

	void getDamaged(int);

	void render();

	void update(float);

	void handlerInput(float);
};

typedef Bat* pBat;