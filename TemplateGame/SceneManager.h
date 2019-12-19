#pragma once
#include "define.h"
#include "Scene.h"

class SceneManager
{
public:
	SceneManager();

	static SceneManager* getInstance();

	void navigateScene(int);

	void add(int, pScene);

	pScene getCurrentScene();


private:
	static SceneManager* _instance;
	int _indexScene;
	std::unordered_map<int, pScene> _listScene;
};

typedef SceneManager* pSceneManager;