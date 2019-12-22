#pragma once
#include "GameObject.h"

class Bat :
	public GameObject
{
private:
	Vec3 posPlayer;
	float _flyTime;

	Vec3 _finalPos;
	Vec3 _initPos;
	bool _isFly;

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