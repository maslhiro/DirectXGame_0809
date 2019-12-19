#pragma once
#include "Scene.h"
#include "Apple.h"
#include "GameMap.h"
#include "Aladdin.h"
#include "HeathHud.h"
#include "AppleHud.h"
#include "CoinHud.h"
#include "LifeHud.h"
#include "ScoreHud.h"
#include "SceneManager.h"

class DungeonScene :
	public Scene
{
private:

	GameMap _map;

	GameMap _mapAbove;

	pCamera _cam;

	pCamera _camAbove;

	pFixedGrid _grid;
	pAladdin _player;

	pInputHandler _input;
	pSceneManager _sceneManager;

	pHeathHud _hud;
	pAppleHud _hudApple;
	pCoinHud _hudCoin;
	pLifeHud _hudLife;
	pScoreHud _hudScore;

public:
	DungeonScene();
	~DungeonScene();

	void init();
	void loadResource();
	void update(float);
	void render();

	void handlerInput(float);
	void release();
};

