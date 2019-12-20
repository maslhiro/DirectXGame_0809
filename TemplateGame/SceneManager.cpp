#include "SceneManager.h"

SceneManager* SceneManager::_instance = nullptr;

SceneManager::SceneManager()
{
	_indexScene = -1;
}

pSceneManager SceneManager::getInstance() {
	if (_instance == nullptr) {
		_instance = new SceneManager();
	}
	return _instance;
}

void SceneManager::navigateScene(int val)
{
	if (val != _indexScene)
	{
		_indexScene = val;
		_listScene[val]->loadResource();
	}
}

void SceneManager::add(int id, pScene scene)
{
	this->_listScene[id] = scene;
}

pScene SceneManager::getCurrentScene()
{
	return this->_listScene[_indexScene];
}