#pragma once
#include "define.h"

#include "DeviceManager.h"
#include "Graphic.h"
#include "GameTime.h"
#include "GameObject.h"
#include "Texture.h"
#include "Sound.h"
#include "Sprite.h"
#include "DrawDebug.h"
#include "AnimationManager.h"
#include "SceneManager.h"

#include "DungeonScene.h"
#include "DyingScene.h"
#include "BossScene.h"
#include "MenuScene.h"

class Game {
private:
	static int isExit;

	pDeviceManager _deviceManager;
	pDrawDebug _drawDebug;
	pGameTime _gameTime;
	pSound _sound;

	pTexture _texture;
	pSprite _sprite;
	pAnimationManager _animationManager;
	pSceneManager _sceneManager;

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