#pragma once
#include "Scene.h"
#include "Animation.h"
#include "AnimationManager.h"
#include "SceneManager.h"

class DyingScene :
	public Scene
{
private:
	std::unordered_map<int, Animation> _listAni;
	pTexture _texture;
	pDeviceManager _device;
	pAnimationManager _aniManager;
	pSceneManager _sceneManager;

public:
	DyingScene();
	~DyingScene();

	void init();
	void loadResource();
	void update(float);
	void render();

	void handlerInput(float);
	void release();
};

typedef DyingScene* pDyingScene;