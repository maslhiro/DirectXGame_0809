#pragma once
#include "Scene.h"
#include "Animation.h"
#include "AnimationManager.h"
#include "SceneManager.h"
#include "Sound.h"

class MenuScene :
	public Scene
{
private:
	std::unordered_map<int, Animation> _listAni;
	pTexture _texture;
	pDeviceManager _device;
	pAnimationManager _aniManager;
	pSceneManager _sceneManager;

	pSound _sound;

	std::unordered_map<int, Animation> _listChar;

	std::vector<Animation> _curChar01;
	std::vector<Animation> _curChar02;

	int _index;

public:
	MenuScene();
	~MenuScene();

	void init();
	void loadResource();
	void update(float);
	void render();

	void handlerInput(float);
	void reset();
	void replaySound();
	void release();
};

typedef MenuScene* pMenuScene;