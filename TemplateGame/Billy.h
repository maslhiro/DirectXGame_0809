#pragma once
#include "GameObject.h"
class Billy :
	public GameObject
{

private:

	pInputHandler _input;
	std::unordered_map<int, bool> _keys;

public:
	Billy();

	void loadResource();

	void render();

	void update(float);

	void handlerInput();

	void fixPosAnimation(int);
};