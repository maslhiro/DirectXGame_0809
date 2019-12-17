#pragma once
#include "GameObject.h"

class Peddler :
	public GameObject
{
private:
	Vec3 posPlayer;

	int _numBlood;
public:
	Peddler();
	Peddler(int);

	void setPosPlayer(Vec3);

	void loadResource();

	int getState();

	void render();

	void fixPosBottom(int);

	void update(float);

	void handlerInput(float);
};

typedef Peddler* pPeddler;