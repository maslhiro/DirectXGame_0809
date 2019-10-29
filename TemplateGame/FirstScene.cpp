#include "FirstScene.h"



FirstScene::FirstScene()
{
}


FirstScene::~FirstScene()
{
}

void FirstScene::init()
{
	_map.init();

	_camera = new Camera();

	_RPT0(0, "[INFO] Init FIRST SCENE done;\n");
}

void FirstScene::loadResource()
{
	auto _deviceManager = DeviceManager::getInstance();

	_map.load("Resource/Map/map.tmx");

	// set cam o goc duoi ben trai
	_camera->setPositisonWorld(_deviceManager->getWidthWindow() / 2, _map.getHeight() - 4 - _deviceManager->getHeightWindow() / 2);
	_camera->setSizeWindow(_deviceManager->getWidthWindow(), _deviceManager->getHeightWindow());

	_map.setCamera(_camera);
}

void FirstScene::update(float dt)
{
	_map.update(dt);
}

void FirstScene::render()
{
	_map.render();
}

void FirstScene::updateInput(float)
{
}

void FirstScene::release()
{
	_map.release();
}
