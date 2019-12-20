#include "Scene.h"

Scene::Scene()
{
	_input = InputHandler::getInstance();
}


Scene::~Scene()
{
}

bool Scene::isInit()
{
	return _isInit;
}
