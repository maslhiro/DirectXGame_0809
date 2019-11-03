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
	_camera->setPositisonWorld(_deviceManager->getWidthWindow() / 2.0, _map.getHeight() - 4 - _deviceManager->getHeightWindow() / 2.0);
	_camera->setSizeWindow(_deviceManager->getWidthWindow(), _deviceManager->getHeightWindow());

	_map.setCamera(_camera);

	_player.setPos(_map.getPosWorld_PLAYER().x,
		_deviceManager->getHeightWindow() - _map.getHeight() + _map.getPosWorld_PLAYER().y);
	_player.setPosWorld(_map.getPosWorld_PLAYER());
	_player.setCamera(_camera);
}

void FirstScene::update(float dt)
{
	this->handlerInput(dt);

	_map.update(dt);
}

void FirstScene::render()
{
	auto _drawDebug = DrawDebug::getInstance();
	auto _device = DeviceManager::getInstance();

	_map.render();

	_player.render();

	//_drawDebug->drawLineHorizontal(_device->getHeightWindow() / 2, 500);
	//_drawDebug->drawLineVertical(_device->getWidthWindow() / 2, 500);

}

void FirstScene::handlerInput(float dt)
{
	_player.handlerInput(dt);
}

void FirstScene::release()
{
	_map.release();
}
