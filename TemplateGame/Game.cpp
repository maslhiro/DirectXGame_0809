#include "Game.h"

int Game::isExit = 0;

pGraphic Game::_hWindow = NULL;

pGraphic Game::getWindow()
{
	return _hWindow;
}

pGameTime Game::getGameTime() {
	return _gameTime->getInstance();
}

Game::Game()
{

}

void Game::loadResource()
{
#pragma region Load Texture
	// Map
	_texture->add(eIdTexture::SCENE_DUNGEON_TEX, L"Resource//Map//Dungeon//map.png", D3DCOLOR_XRGB(255, 255, 255));
	_texture->add(eIdTexture::SCENE_BOSS_TEX, L"Resource//Map//Boss//map.png", D3DCOLOR_XRGB(255, 255, 255));
	_texture->add(eIdTexture::SCENE_ABOVE_DUNG_TEX, L"Resource//Map//Dungeon//map_above.png", D3DCOLOR_XRGB(163, 73, 164));
	_texture->add(eIdTexture::SCENE_ABOVE_BOSS_TEX, L"Resource//Map//Boss//map_above.png", D3DCOLOR_XRGB(255, 255, 255));
	_texture->add(eIdTexture::MENU_TEX, L"Resource//Map//Menu//menu.png", D3DCOLOR_XRGB(255, 255, 255));


	// Bounding box
	_texture->add(eIdTexture::BOX_RED_TEX, L"Resource//Object//Box_Red.png", D3DCOLOR_XRGB(255, 255, 255));
	_texture->add(eIdTexture::BOX_GRAY_TEX, L"Resource//Object//Box_Gray.png", D3DCOLOR_XRGB(255, 255, 255));
	_texture->add(eIdTexture::BOX_GREEN_TEX, L"Resource//Object//Box_Green.png", D3DCOLOR_XRGB(255, 255, 255));

	// Item game
	_texture->add(eIdTexture::ITEM_TEX, L"Resource//Object//Item.png", D3DCOLOR_XRGB(255, 0, 255));
	_texture->add(eIdTexture::ITEM_MAP_TEX, L"Resource//Object//Item_Map.png", D3DCOLOR_XRGB(163, 73, 164));
	_texture->add(eIdTexture::BAT_TEX, L"Resource//Object//Bat.png", D3DCOLOR_XRGB(255, 0, 255));
	_texture->add(eIdTexture::SKELETON_TEX, L"Resource//Object//Skeleton.png", D3DCOLOR_XRGB(255, 255, 255));
	_texture->add(eIdTexture::GUARDS_TEX, L"Resource//Object//Guards.png", D3DCOLOR_XRGB(120, 193, 152));
	_texture->add(eIdTexture::PEDDLER_TEX, L"Resource//Object//Peddler.png", D3DCOLOR_XRGB(255, 0, 255));
	_texture->add(eIdTexture::JAFAR_TEX, L"Resource//Object//Jafar.png", D3DCOLOR_XRGB(186, 254, 202));

	// Aladdin
	_texture->add(eIdTexture::ALADDIN_TEX, L"Resource//Object//Aladdin.png", D3DCOLOR_XRGB(106, 148, 189));
#pragma endregion

#pragma region Load Sprite

	_sprite->add(eIdTexture::ITEM_TEX, "Resource//Object//Item_Sprite.txt");
	_sprite->add(eIdTexture::ITEM_MAP_TEX, "Resource//Object//Item_Map_Sprite.txt");
	_sprite->add(eIdTexture::ALADDIN_TEX, "Resource//Object//Aladdin_Sprite.txt");
	_sprite->add(eIdTexture::BAT_TEX, "Resource//Object//Bat_Sprite.txt");
	_sprite->add(eIdTexture::SKELETON_TEX, "Resource//Object//Skeleton_Sprite.txt");
	_sprite->add(eIdTexture::GUARDS_TEX, "Resource//Object//Guards_Sprite.txt");
	_sprite->add(eIdTexture::PEDDLER_TEX, "Resource//Object//Peddler_Sprite.txt");
	_sprite->add(eIdTexture::JAFAR_TEX, "Resource//Object//Jafar_Sprite.txt");

#pragma endregion

	_animationManager->load();
	//_sceneManager->load();
	pScene _first = new DungeonScene();
	//_first->init();
	//_first->loadResource();
	_sceneManager->add(eIdScene::SE_DUNGEON, _first);

	pScene _boss = new BossScene();
	//_boss->init();
	//_boss->loadResource();
	_sceneManager->add(eIdScene::SE_JAFAR, _boss);

	pScene _menu = new MenuScene();
	//_menu->init();
	//_menu->loadResource();
	_sceneManager->add(eIdScene::SE_MENU, _menu);

	pScene _dying = new DyingScene();
	//_dying->init();
	//_dying->loadResource();
	_sceneManager->add(eIdScene::SE_DYING, _dying);

	pScene _complete = new CompleteScene();
	//_complete->init();
	//_complete->loadResource();
	_sceneManager->add(eIdScene::SE_COMPLETE, _complete);

	//_sceneManager->navigateScene(eIdScene::SE_MENU);
	_sceneManager->navigateScene(eIdScene::SE_MENU);

	_RPT0(0, "[INFO] Load Resource DONE ;\n");

}

Game::Game(HINSTANCE hInstance, int nCmdShow)
{
	_hWindow = new Graphic(hInstance, nCmdShow, 0);
	_sound = Sound::getInstance();
	_gameTime = GameTime::getInstance();
	_deviceManager = DeviceManager::getInstance();
	_drawDebug = DrawDebug::getInstance();
	_texture = Texture::getInstance();
	_sprite = Sprite::getInstance();
	_animationManager = AnimationManager::getInstance();
	_sceneManager = SceneManager::getInstance();
}

int Game::init()
{
	_gameTime->init();
	_hWindow->initWindow();
	_sound->loadSound(_hWindow->getWnd());
	_deviceManager->init(_hWindow);
	_drawDebug->init();
	_texture->init();

	_RPT0(0, "[INFO] Init Game done;\n");
	return 1;
}

int Game::run()
{
	MSG msg;

	float tickPerFrame = 1.0f / MAX_FRAME_RATE, delta = 0;

	float fps = 0;

	std::ostringstream _osFPS;
	_osFPS << "FPS : ";

	while (!isExit)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) isExit = 1;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		_gameTime->updateGameTime();

		delta += _gameTime->getElapsedGameTime();

		if (delta >= tickPerFrame)
		{
			fps = 1.0f / delta;

			_osFPS << fps;

			//_RPT1(0, "[INFO] Elapsed Time : %f \n", delta);
			//_RPT1(0, "[INFO] Total Time : %f \n", _gameTime->getTotalGameTime());		
			//_RPT1(0, "[INFO] FPS : %f \n", fps);
			SetWindowTextA(_hWindow->getWnd(), _osFPS.str().c_str());

			this->update(delta);

			this->render();

			delta = 0;
			_osFPS.str("");
			_osFPS.clear();
			_osFPS << "FPS : ";
		}
		else
		{
			Sleep(int(tickPerFrame - delta));

		}
	}

	return 1;
}

int Game::render()
{
	// kiểm tra nếu cửa sổ lost focus thì game không cập nhật
	if (GetActiveWindow() != _hWindow->getWnd())
		return 0;

	if (_deviceManager->getDevice()->BeginScene())
	{
		// Clear back buffer with a color
		_deviceManager->clearScreen();

		_deviceManager->getSpriteHandler()->Begin(D3DXSPRITE_ALPHABLEND);

		_sceneManager->getCurrentScene()->render();

		_deviceManager->getSpriteHandler()->End();
		_deviceManager->getDevice()->EndScene();
	}

	// Display back buffer content to the screen
	_deviceManager->present();

	return 1;
}

int Game::update(float dt)
{

	_sceneManager->getCurrentScene()->handlerInput(dt);

	_sceneManager->getCurrentScene()->update(dt);


	return 1;
}

void Game::exit()
{
	isExit = 1;
}

void Game::release()
{
	if (_deviceManager != nullptr) _deviceManager->release();
	if (_gameTime != nullptr) _gameTime->release();
	if (_texture != nullptr) _texture->release();
	if (_gameTime != nullptr) _gameTime->release();
	if (_drawDebug != nullptr) _drawDebug->release();
}

Game::~Game()
{
}
