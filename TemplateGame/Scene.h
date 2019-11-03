#pragma once
#include "define.h"
#include "Scene.h"
#include "DeviceManager.h"
#include "DrawDebug.h"
#include "GameMap.h"

class Scene
{
public:
	Scene();
	virtual ~Scene();

	void virtual init() = 0;
	void virtual loadResource() = 0;
	void virtual handlerInput(float) = 0;
	void virtual update(float) = 0;
	void virtual render() = 0;
	void virtual release() = 0;

	bool isInit();
protected:
	bool _isInit;
};

