#include "Scene.h"



Scene::Scene()
{
	_sound = Sound::getInstance();
}


Scene::~Scene()
{
}

bool Scene::isInit()
{
	return _isInit;
}
