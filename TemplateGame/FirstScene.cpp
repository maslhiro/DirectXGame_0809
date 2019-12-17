#include "FirstScene.h"


FirstScene::FirstScene()
{
	_grid = new FixedGrid();
	_player = new Aladdin();
	_cam = new Camera();
	_hud = new HeathHud();
	_hudApple = new AppleHud();
	_hudCoin = new CoinHud();
}


FirstScene::~FirstScene()
{
}

void FirstScene::init()
{
	_map.init();
	_mapAbove.init();
	_map.setPointerPlayer(_player);

	_grid->setPathTxt("Resource/Map/grid.txt");
	_grid->init();

	_map.setGrid(_grid);

	_RPT0(0, "[INFO] Init FIRST SCENE done;\n");
}

void FirstScene::loadResource()
{
	auto _deviceManager = DeviceManager::getInstance();

	_map.loadGameObj("Resource/Map/obj.txt");
	_map.loadTileSet("Resource/Map/tile.txt");
	_map.load("Resource/Map/map.txt");

	//_mapAbove.loadTileSet("Resource/Map/tile_above.txt");
	//_mapAbove.load("Resource/Map/map_above.txt");

	// set cam o goc duoi ben trai
	_cam->setPositisonWorld((_deviceManager->getWidthWindow() / 2 + 34), _map.getHeight() - 20 - _deviceManager->getHeightWindow() / 2);
	//_cam->setPositisonWorld(_deviceManager->getWidthWindow() / 2, _deviceManager->getHeightWindow() / 2);
	_cam->setSizeWindow(_deviceManager->getWidthWindow(), _deviceManager->getHeightWindow());
	_cam->setSpeedX(300.f);

	_cam->setSpeedY(400.f);

	//_mapAbove.setCamera(_cam);
	_map.setCamera(_cam);
	//_mapAbove.setCamera(_cam);

	_player->setCamera(_cam);
	_player->loadResource();
	_player->setScale(2.0f);
	_player->setSpeed(300.f);
	_player->setGravity(400.f);

	_player->setGrid(_grid);

	_hud->loadResource();
	_hudApple->loadResource();
	_hudCoin->loadResource();
}

void FirstScene::update(float dt)
{
	_player->update(dt);

	_cam->update(dt);

	_map.update(dt);

	_hud->setHealth(_player->getNumBlood());
	_hud->update(dt);

	_hudApple->setNumApple(_player->getNumApple());
	_hudApple->update(dt);

	//_hudCoin->setNumApple(_player->getNumApple());
	_hudCoin->update(dt);
}

void FirstScene::render()
{
	//auto _drawDebug = DrawDebug::getInstance();
	//auto _device = DeviceManager::getInstance();

	_map.render();
	_map.renderAbove();

	_hud->render();
	_hudApple->render();
	_hudCoin->render();
}

void FirstScene::handlerInput(float dt)
{
	_player->handlerInput(dt);
}

void FirstScene::release()
{
	_map.release();
}
