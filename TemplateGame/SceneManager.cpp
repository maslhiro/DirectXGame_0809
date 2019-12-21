#include "SceneManager.h"

SceneManager* SceneManager::_instance = nullptr;

SceneManager::SceneManager()
{
	_indexScene = -1;
	_preIndexScene = -1;
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
		_preIndexScene = _indexScene;
		_indexScene = val;

		_indexScene = val;
		_listScene[val]->init();
		_listScene[val]->loadResource();
	}
}

void SceneManager::backScreen()
{
	if (_preIndexScene != -1)
	{
		_indexScene = _preIndexScene;
		_listScene[_indexScene]->replaySound();
		_listScene[_indexScene]->reset();
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