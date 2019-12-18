#include "SceneManager.h"

SceneManager* SceneManager::_instance = nullptr;

SceneManager::SceneManager()
{
	_indexScene = 1;
}

//void SceneManager::load()
//{
//	pScene _first = new FirstScene();
//	_first->init();
//	_first->loadResource();
//
//	_listScene[0] = _first;
//
//	pScene _dying = new DyingScene();
//	_dying->init();
//	_dying->loadResource();
//
//	_listScene[1] = _dying;
//}

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
