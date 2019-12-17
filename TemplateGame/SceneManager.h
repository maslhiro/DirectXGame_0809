#pragma once
#include "define.h"
#include "Scene.h"
#include "FirstScene.h"
#include "DyingScene.h"

class SceneManager
{
public:
	SceneManager();

	void load();

	static SceneManager* getInstance();

	void add(eIdAnimation, pScene);
	pScene get(int);

private:
	static SceneManager* _instance;

	std::unordered_map<int, pScene> _listScene;
};

typedef SceneManager* pSceneManager;