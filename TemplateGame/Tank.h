#pragma once
#include "define.h"
#include "GameObject.h"
#include "InputHandler.h"

class Tank : public GameObject
{
private:

	pInputHandler _input;
	std::unordered_map<int, bool> _keys;

public:
	Tank();

	void loadResource();

	void render();

	void update(float);

	void handlerInput(float);

	void fixPosAnimation(int);
};

