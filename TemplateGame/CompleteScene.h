#pragma once
#include "Scene.h"
#include "Animation.h"
#include "AnimationManager.h"
#include "SceneManager.h"
#include "Sound.h"

class CompleteScene :
	public Scene
{
private:
	std::unordered_map<int, Animation> _listAni;
	pTexture _texture;
	pDeviceManager _device;
	pAnimationManager _aniManager;
	pSceneManager _sceneManager;

	Vec3 _pos;
	float _dx;

public:
	CompleteScene();
	~CompleteScene();

	void init();
	void loadResource();
	void update(float);
	void render();

	void handlerInput(float);
	void reset();
	void replaySound();
	void release();
};

typedef CompleteScene* pCompleteScene;