#pragma once
#include "define.h"

#include "DeviceManager.h"
#include "Graphic.h"
#include "GameTime.h"

class Game {
private :
	static int isExit;
	pDeviceManager _deviceManager;
	pGameTime _gameTime;

public:
	static pGraphic _hWindow;
	static pGraphic getWindow();

	Game();
	Game(HINSTANCE, int);
	~Game();

	int init();
	void loadResource();
	int run();
	void render();
	void release();
	static void exit();

	pGameTime getGameTime();

};

typedef Game* pGame;