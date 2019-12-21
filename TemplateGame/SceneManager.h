#pragma once
#include "define.h"
#include "Scene.h"

class SceneManager
{
public:
	SceneManager();

	static SceneManager* getInstance();

	// Khoi tao man hinh moi khi chuyen qua
	void navigateScene(int);

	// Giu nguyen man hinh ban dau chi render lai
	void backScreen();

	void add(int, pScene);

	pScene getCurrentScene();


private:
	static SceneManager* _instance;
	int _indexScene, _preIndexScene;
	std::unordered_map<int, pScene> _listScene;
};

typedef SceneManager* pSceneManager;