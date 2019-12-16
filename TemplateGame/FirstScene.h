#pragma once
#include "Scene.h"
#include "Apple.h"
#include "GameMap.h"
#include "Aladdin.h"
#include "HeathHud.h"
#include "AppleHud.h"

class FirstScene :
	public Scene
{
private:

	GameMap _map;

	GameMap _mapAbove;

	pCamera _cam;

	pFixedGrid _grid;
	pAladdin _player;

	pHeathHud _hud;
	pAppleHud _hudApple;

public:
	FirstScene();
	~FirstScene();

	void init();
	void loadResource();
	void update(float);
	void render();

	void handlerInput(float);
	void release();
};

