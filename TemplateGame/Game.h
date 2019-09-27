#pragma once
#include "define.h"

#include "DeviceManager.h"
#include "Graphic.h"
#include "GameTime.h"
#include "GameObject.h"
#include "Texture.h"
#include "Sprite.h"
#include "DrawDebug.h"
#include "AnimationManager.h"

#include "Billy.h"

class Game {
private:
	static int isExit;

	pDeviceManager _deviceManager;
	pDrawDebug _drawDebug;
	pGameTime _gameTime;

	pTexture _texture;
	pSprite _sprite;
	pAnimationManager _animationManager;

	Billy _billy;

public:
	static pGraphic _hWindow;
	static pGraphic getWindow();

	pGameTime getGameTime();

	Game();
	Game(HINSTANCE, int);
	~Game();

	int init();
	void loadResource();

	int run();
	int render();
	int update(float);

	void release();
	static void exit();

};

typedef Game* pGame;