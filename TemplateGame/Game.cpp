#include "Game.h"

int Game::isExit = 0;

pGraphic Game::_hWindow = NULL;

Animation _test;
Animation _test01;

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
	_texture->add(eIdTexture::SCENE_DUNGEON_TEX, L"Resource//Map//Map.png", D3DCOLOR_XRGB(255, 255, 255));
	_texture->add(eIdTexture::SCENE_ABOVE_TEX, L"Resource//Map//Map_Above.png", D3DCOLOR_XRGB(163, 73, 164));

	// Bounding box
	_texture->add(eIdTexture::BOX_RED_TEX, L"Resource//Object//Box_Red.png", D3DCOLOR_XRGB(255, 255, 255));
	_texture->add(eIdTexture::BOX_GRAY_TEX, L"Resource//Object//Box_Gray.png", D3DCOLOR_XRGB(255, 255, 255));
	_texture->add(eIdTexture::BOX_GREEN_TEX, L"Resource//Object//Box_Green.png", D3DCOLOR_XRGB(255, 255, 255));

	// Item game
	_texture->add(eIdTexture::ITEM_TEX, L"Resource//Object//Item.png", D3DCOLOR_XRGB(255, 0, 255));
	_texture->add(eIdTexture::ITEM_MAP_TEX, L"Resource//Object//Item_Map.png", D3DCOLOR_XRGB(163, 73, 164));

	// Aladdin
	_texture->add(eIdTexture::ALADIN_TEX, L"Resource//Object//Aladin.png", D3DCOLOR_XRGB(106, 148, 189));
#pragma endregion

#pragma region Load Sprite

	_sprite->add(eIdTexture::ITEM_TEX, "Resource//Object//Item_Sprite.txt");
	_sprite->add(eIdTexture::ITEM_MAP_TEX, "Resource//Object//Item_Map_Sprite.txt");
	_sprite->add(eIdTexture::ALADIN_TEX, "Resource//Object//Aladin_Sprite.txt");

#pragma endregion

	_animationManager->load();

	//_test = _animationManager->get(eIdAnimation::ROCK_VISIBLE);
	//_test.setPosition(Vec3(300, 300, 0));
	//_test.setScale(Vec2(2, 2));
	//_test.setIsLoop(true);
	//_test.setDrawingBound(true);

	//RECT bb = _test.getBounding();
	//_RPT1(0, "[INFO] %d %d %d %d \n", bb.left, bb.top, bb.right, bb.bottom);

	//_test = _animationManager->get(eIdAnimation::ROCK_VISIBLE);
	//_test.setPosition(Vec3(300, 300, 1));
	//_test.setScale(Vec2(2, 2));
	//_test.setDrawingBound(true);

	_firstScene.loadResource();

	_RPT0(0, "[INFO] Load Resource DONE ;\n");

}

Game::Game(HINSTANCE hInstance, int nCmdShow)
{
	_hWindow = new Graphic(hInstance, nCmdShow, 0);
	_gameTime = GameTime::getInstance();
	_deviceManager = DeviceManager::getInstance();
	_drawDebug = DrawDebug::getInstance();
	_texture = Texture::getInstance();
	_sprite = Sprite::getInstance();
	_animationManager = AnimationManager::getInstance();

}

int Game::init()
{
	_gameTime->init();
	_hWindow->initWindow();
	_deviceManager->init(_hWindow);
	_drawDebug->init();
	_texture->init();
	_firstScene.init();
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

		//_test01.render(_deviceManager, _texture);

		//_test.render(_deviceManager, _texture);

		_firstScene.render();

		_deviceManager->getSpriteHandler()->End();
		_deviceManager->getDevice()->EndScene();
	}

	// Display back buffer content to the screen
	_deviceManager->present();

	return 1;
}

int Game::update(float dt)
{
	//_test.update(dt);
	//_test.update(dt);
	_firstScene.handlerInput(dt);

	_firstScene.update(dt);


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

	_firstScene.release();
}

Game::~Game()
{
}
