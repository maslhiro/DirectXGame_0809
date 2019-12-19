#include "BossScene.h"


BossScene::BossScene()
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


BossScene::~BossScene()
{
}

void BossScene::init()
{
	_map.init();
	_mapAbove.init();
	_map.setPointerPlayer(_player);

	_grid->setPathTxt("Resource/Map/Boss/grid.txt");
	_grid->init();

	_map.setGrid(_grid);

	_rebornTime = 0.f;

	_RPT0(0, "[INFO] Init BOSS SCENE done;\n");
}

void BossScene::loadResource()
{
	auto _deviceManager = DeviceManager::getInstance();

	_map.loadGameObj("Resource/Map/Boss/obj.txt");
	_map.loadTileSet("Resource/Map/Boss/tile.txt");
	_map.load("Resource/Map/Boss/map.txt");

	_mapAbove.loadTileSet("Resource/Map/Boss/tile_above.txt");
	_mapAbove.load("Resource/Map/Boss/map_above.txt");

	// set cam o goc duoi ben trai
	_cam->setPositisonWorld((_deviceManager->getWidthWindow() / 2 + 34), _map.getHeight() - 20 - _deviceManager->getHeightWindow() / 2);
	_cam->setSizeWindow(_deviceManager->getWidthWindow(), _deviceManager->getHeightWindow());
	_cam->setSpeedX(300.f);
	_cam->setDistance(10, 40);
	_cam->setSpeedY(400.f);

	_camAbove->setSpeedX(300.f);
	_camAbove->setDistance(10, 30);
	_camAbove->setSpeedY(400.f);

	_camAbove->setPositisonWorld((_deviceManager->getWidthWindow() / 2 + 100), _mapAbove.getHeight() - _deviceManager->getHeightWindow() / 2);
	_camAbove->setSizeWindow(_deviceManager->getWidthWindow(), _deviceManager->getHeightWindow());

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

void BossScene::update(float dt)
{
	_rebornTime += dt;

	if (_rebornTime > 10.f)
	{
		_rebornTime = 0.f;
		//_RPT0(0, "[RE BORN]\n");
		RECT _view = _cam->getBounding();

		auto listObj = _grid->getListGameObjContain(_view);
		for (size_t i = 0; i < listObj.size(); i++)
		{
			if (listObj[i]->getIdType() != eIdObject::APPLE) continue;
			//_RPT1(0, "[RE BORN] Id %d \n", listObj[i]->getId());
			listObj[i]->setIsTerminated(false);
		}
	}

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

void BossScene::render()
{
	//auto _drawDebug = DrawDebug::getInstance();
	//auto _device = DeviceManager::getInstance();
	_mapAbove.render();

	_map.render();
	_map.renderAbove();

	_hud->render();
	_hudApple->render();
	_hudCoin->render();
	_hudLife->render();
	_hudScore->render();
}

void BossScene::handlerInput(float dt)
{
	_player->handlerInput(dt);
}

void BossScene::release()
{
	_map.release();
}
