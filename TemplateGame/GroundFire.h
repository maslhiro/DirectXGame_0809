#pragma once
#include "GameObject.h"
class GroundFire :
	public GameObject
{
private:
	Vec3 posPlayer;
public:
	GroundFire();

	void loadResource();

	void setPosPlayer(Vec3);

	void render();

	void update(float);

	void handlerInput(float);
};

