#pragma once
#include "define.h"

#include "DeviceManager.h"
#include "Graphic.h"
#include "GameTime.h"
#include "GameObject.h"

class Game {
private:
	static int isExit;
	pDeviceManager _deviceManager;
	pGameTime _gameTime;
	pTank _tank;

public:
	static pGraphic _hWindow;
	static pGraphic getWindow();

	Game();
	Game(HINSTANCE, int);
	~Game();

	int init();
	void loadResource();
	int run();
	int render();
	void release();
	static void exit();

	pGameTime getGameTime();

};

typedef Game* pGame;