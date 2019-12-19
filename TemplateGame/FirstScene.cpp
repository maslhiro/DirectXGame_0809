#include "FirstScene.h"


FirstScene::FirstScene()
{
	_grid = new FixedGrid();
	_player = new Aladdin();
	_cam = new Camera();
	_camAbove = new Camera();
	_hud = new HeathHud();
	_hudApple = new AppleHud();
	_hudCoin = new CoinHud();
	_hudLife = new LifeHud();
	_hudScore = new ScoreHud();
}


FirstScene::~FirstScene()
{
}

void FirstScene::init()
{
	_map.init();
	_mapAbove.init();
	_map.setPointerPlayer(_player);

	_grid->setPathTxt("Resource/Map/Dungeon/grid.txt");
	_grid->init();

	_map.setGrid(_grid);

	_RPT0(0, "[INFO] Init FIRST SCENE done;\n");
}

void FirstScene::loadResource()
{
	auto _deviceManager = DeviceManager::getInstance();

	_map.loadGameObj("Resource/Map/Dungeon/obj.txt");
	_map.loadTileSet("Resource/Map/Dungeon/tile.txt");
	_map.load("Resource/Map/Dungeon/map.txt");

	_mapAbove.loadTileSet("Resource/Map/Dungeon/tile_above.txt");
	_mapAbove.load("Resource/Map/Dungeon/map_above.txt");

	// set cam o goc duoi ben trai
	_cam->setPositisonWorld((_deviceManager->getWidthWindow() / 2 + 34), _map.getHeight() - 20 - _deviceManager->getHeightWindow() / 2);
	//_cam->setPositisonWorld(_deviceManager->getWidthWindow() / 2, _deviceManager->getHeightWindow() / 2);
	_cam->setSizeWindow(_deviceManager->getWidthWindow(), _deviceManager->getHeightWindow());

	_cam->setSpeedX(300.f);
	_cam->setDistance(10, 40);
	_cam->setSpeedY(400.f);

	_camAbove->setSpeedX(400.f);
	_camAbove->setDistance(10, 40);
	_camAbove->setSpeedY(400.f);

	_camAbove->setPositisonWorld((_deviceManager->getWidthWindow() / 2 + 34), _map.getHeight() - 20 - _deviceManager->getHeightWindow() / 2);
	//_cam->setPositisonWorld(_deviceManager->getWidthWindow() / 2, _deviceManager->getHeightWindow() / 2);
	_camAbove->setSizeWindow(_deviceManager->getWidthWindow(), _deviceManager->getHeightWindow());
	//_camAbove->setSpeedX(250.f);
	//_camAbove->setDistance(10, 40);
	//_camAbove->setSpeedY(400.f);

	//_mapAbove.setCamera(_cam);
	_map.setCamera(_cam);
	_mapAbove.setCamera(_camAbove);

	_player->setCamera(_cam);
	_player->setCameraAbove(_camAbove);
	_player->loadResource();
	_player->setScale(2.0f);
	_player->setSpeed(300.f);
	_player->setGravity(400.f);

	_player->setGrid(_grid);

	_hud->loadResource();
	_hudApple->loadResource();
	_hudCoin->loadResource();
	_hudLife->loadResource();
	_hudScore->loadResource();
}

void FirstScene::update(float dt)
{
	_player->update(dt);

	_cam->update(dt);
	_camAbove->update(dt);

	_map.update(dt);

	_hud->setHealth(_player->getNumBlood());
	_hud->update(dt);

	_hudApple->setNumApple(_player->getNumApple());
	_hudApple->update(dt);

	_hudCoin->setNumCoin(_player->getNumCoin());
	_hudCoin->update(dt);

	_hudLife->setNumLife(_player->getNumLife());
	_hudLife->update(dt);

	_hudScore->setNumScore(_player->getNumScore());
	_hudScore->update(dt);
}

void FirstScene::render()
{
	//auto _drawDebug = DrawDebug::getInstance();
	//auto _device = DeviceManager::getInstance();

	_map.render();
	_map.renderAbove();

	_mapAbove.render();

	_hud->render();
	_hudApple->render();
	_hudCoin->render();
	_hudLife->render();
	_hudScore->render();
}

void FirstScene::handlerInput(float dt)
{
	_player->handlerInput(dt);
}

void FirstScene::release()
{
	_map.release();
}
