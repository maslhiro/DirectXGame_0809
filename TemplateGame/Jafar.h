#pragma once
#include "GameObject.h"

class Jafar :
	public GameObject
{
private:
	Vec3 posPlayer;

	int _numBlood;
public:
	Jafar();
	Jafar(int);

	void setPosPlayer(Vec3);

	void loadResource();

	void getDamaged(int);

	int getState();

	void render();

	void update(float);

	void handlerInput(float);
};

typedef Jafar* pJafar;

