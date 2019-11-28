#include "FirstScene.h"


FirstScene::FirstScene()
{
	_grid = new FixedGrid();
	_player = new Aladin();
	_camera = new Camera();
}


FirstScene::~FirstScene()
{
}

void FirstScene::init()
{
	_map2.init();
	_map2.setIdTextureMapAbove(eIdTexture::SCENE_ABOVE_TEX);
	_map2.setPointerPlayer(_player);

	_grid->setPathTxt("Resource//Map//grid.txt");
	_grid->init();
	_map2.setGrid(_grid);

	_RPT0(0, "[INFO] Init FIRST SCENE done;\n");
}

void FirstScene::loadResource()
{
	auto _deviceManager = DeviceManager::getInstance();
	_map2.loadTileSet("Resource/Map/tile.txt");
	_map2.load("Resource/Map/map.txt");

	// set cam o goc duoi ben trai
	_camera->setPositisonWorld(_deviceManager->getWidthWindow() / 2, _map2.getHeight() - 4 - _deviceManager->getHeightWindow() / 2);
	//_camera->setPositisonWorld(_deviceManager->getWidthWindow() / 2, _deviceManager->getHeightWindow() / 2);
	_camera->setSizeWindow(_deviceManager->getWidthWindow(), _deviceManager->getHeightWindow());
	_camera->setSpeed(130.f);

	_map2.setCamera(_camera);

	_player->setCamera(_camera);
	_player->loadResource();
	_player->setScale(2.0f);
	_player->setSpeed(140.f);
	_player->setGravity(190.f);

	_player->setGrid(_grid);

}

void FirstScene::update(float dt)
{
	//_player->update(dt);

	//_camera->update(dt);

	_map2.update(dt);

}

void FirstScene::render()
{
	//auto _drawDebug = DrawDebug::getInstance();
	//auto _device = DeviceManager::getInstance();

	_map2.render();
	//_map2.renderAbove();

	//_drawDebug->drawLineHorizontal(_device->getHeightWindow() / 2, 500);
	//_drawDebug->drawLineVertical(_device->getWidthWindow() / 2, 500);

}

void FirstScene::handlerInput(float dt)
{
	//_player->handlerInput(dt);
}

void FirstScene::release()
{
	_map2.release();
}
