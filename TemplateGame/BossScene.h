#pragma once
#include "Scene.h"
#include "GameMap.h"
#include "Aladdin.h"
#include "HeathHud.h"
#include "AppleHud.h"
#include "CoinHud.h"
#include "LifeHud.h"
#include "ScoreHud.h"
#include "SceneManager.h"

class BossScene :
	public Scene
{
private:

	GameMap _map;

	GameMap _mapAbove;

	pCamera _cam;

	pCamera _camAbove;

	pFixedGrid _grid;

	pAladdin _player;

	pJafar _boss;

	pSceneManager _sceneManager;

	float _rebornTime;

	pHeathHud _hud;
	pAppleHud _hudApple;
	pCoinHud _hudCoin;
	pLifeHud _hudLife;
	pScoreHud _hudScore;

public:
	BossScene();
	~BossScene();

	void init();
	void loadResource();
	void update(float);
	void render();

	void handlerInput(float);
	void release();
};

