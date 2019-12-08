#pragma once
#include "GameObject.h"

class AppleThrow :
	public GameObject
{
private:
	std::vector<pGameObject> _listGameObj;
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