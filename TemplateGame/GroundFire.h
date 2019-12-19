#pragma once
#include "GameObject.h"
class GroundFire :
	public GameObject
{
private:

	Vec3 posPlayer;
	Vec3 posFire;

	float _waitTime;
	bool _stop;
public:
	GroundFire();

	void loadResource();

	void setPosPlayer(Vec3);

	void render();

	void stopFire();

	void update(float);

	void handlerInput(float);

	bool checkCollisionFire(RECT);
};

typedef GroundFire* pGroundFire;