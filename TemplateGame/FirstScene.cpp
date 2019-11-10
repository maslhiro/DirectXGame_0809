#include "FirstScene.h"



FirstScene::FirstScene()
{
	_grid = new FixedGrid();
}


FirstScene::~FirstScene()
{
}

void FirstScene::init()
{
	_map2.init();
	//_map.init();
	_grid->setPathTxt("Resource//Map//grid.txt");
	_grid->init();
	_map2.setGrid(_grid);
	//_apple = new Apple();
	_camera = new Camera();

	_RPT0(0, "[INFO] Init FIRST SCENE done;\n");
}

void FirstScene::loadResource()
{
	auto _deviceManager = DeviceManager::getInstance();
	_map2.load("Resource//Map//map.txt");
	//_map.load("Resource/Map/map.tmx");

	//_apple->loadResource();
	//_apple->setPositionWorld(10, 10);

	// set cam o goc duoi ben trai
	_camera->setPositisonWorld(_deviceManager->getWidthWindow() / 2, _map2.getHeight() - 4 - _deviceManager->getHeightWindow() / 2);
	_camera->setSizeWindow(_deviceManager->getWidthWindow(), _deviceManager->getHeightWindow());

	//_map.setCamera(_camera);
	_map2.setCamera(_camera);
	_player.setPos(300, 300);
	//_player.setPos((int)_map.getPosWorld_PLAYER().x,
	//	_deviceManager->getHeightWindow() - _map.getHeight() + (int)_map.getPosWorld_PLAYER().y);
	//_player.setPosWorld(_map.getPosWorld_PLAYER());
	_player.setCamera(_camera);
}

void FirstScene::update(float dt)
{
	this->handlerInput(dt);

	//_map2.update(dt);
}

void FirstScene::render()
{
	auto _drawDebug = DrawDebug::getInstance();
	auto _device = DeviceManager::getInstance();

	//_map.render(_player.getBounding());

	_map2.render();
	_player.render();
	_map2.renderAbove();
	//_apple->render();

	//_drawDebug->drawLineHorizontal(_device->getHeightWindow() / 2, 500);
	//_drawDebug->drawLineVertical(_device->getWidthWindow() / 2, 500);

}

void FirstScene::handlerInput(float dt)
{
	_player.handlerInput(dt);
}

void FirstScene::release()
{
	//_map.release();
	_map2.release();
}
