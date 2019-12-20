#pragma once
#include "GameObject.h"
#include "Nahbi.h"
#include "Fazal.h"
#include "Bat.h"
#include "Skeleton.h"
#include "Jafar.h"

class AppleThrow :
	public GameObject
{
private:
	std::vector<pGameObject> _listGameObj;

	float _timeUp;
public:
	AppleThrow();
	AppleThrow(int);

	void setListGameObj(std::vector<pGameObject>);

	void loadResource();

	void render();

	void update(float);

	void handlerInput(float);

	void moveLeft();

	void moveRight();
};

typedef AppleThrow* pAppleThrow;