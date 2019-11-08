#pragma once
#include "GameObject.h"
class Aladin :
	public GameObject
{
private:

	pInputHandler _input;
	std::unordered_map<int, bool> _keys;

public:
	Aladin();

	void loadResource();

	void render();

	void update(float);

	void handlerInput();
};
