#include "SceneManager.h"

SceneManager* SceneManager::_instance = nullptr;

SceneManager::SceneManager()
{
}

void SceneManager::load()
{
	pScene _first = new FirstScene();
	_first->init();
	_first->loadResource();

	_listScene[0] = _first;

}

pSceneManager SceneManager::getInstance() {
	if (_instance == nullptr) {
		_instance = new SceneManager();
	}
	return _instance;
}

void SceneManager::add(eIdAnimation id, pScene scene)
{
	this->_listScene[id] = scene;
}

pScene SceneManager::get(int id)
{
	return this->_listScene[id];
}
