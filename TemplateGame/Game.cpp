#include "Game.h"

int Game::isExit = 0;

pGraphic Game::_hWindow = NULL;

Animation billy;

Animation billy2;

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
	_texture->add(eIdTexture::BILLY_TEX, L"Resource//Object//Billy.png", D3DCOLOR_XRGB(255, 255, 255));
	//_texture->add(eIdTexture::BILLY_TEX, L"Resource//Object//Billy.png", D3DCOLOR_XRGB(0, 106, 106));
	_texture->add(eIdTexture::SCENE_TEX, L"Resource//Map//map.png", D3DCOLOR_XRGB(255, 255, 255));

	_map.load("Resource/Map/map.tmx");

	_RPT1(0, "[INFO] Map Width %d ;\n", _map.getWidth());

	//_sprite->add(eIdTexture::BILLY_TEX, "Resource//Object//Billy_Animation.txt");

	_animationManager->load();

	//billy = _animationManager->get(eIdAnimation::BILLY_PUNCHING);
	//billy.setPosition(Vec3(300, 300, 0));
	//billy.setIsReverse(true);
	//billy.setDrawingBound(true);
	//billy.setColorBound(D3DCOLOR_XRGB(2, 56, 60));
	//billy.setScale(Vec2(2, 2));

	//billy2 = _animationManager->get(eIdAnimation::BILLY_PUNCHING);
	//billy2.setPosition(Vec3(300, 300, 0));
	//billy2.setDrawingBound(true);
	//billy2.setScale(Vec2(2, 2));

	/*_billy.loadResource();
	_billy.setPosition(300, 300);
	_billy.setScale(2);*/
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
	_map.init();

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

		_map.render();

		//_drawDebug->drawLineHorizontal(300 + 18.5, 600);
		//_drawDebug->drawLineHorizontal(300, 600);
		//_drawDebug->drawLineVertical(300, 500);
		//_billy.render();

		//billy.render(_deviceManager, _texture);
		//billy2.render(_deviceManager, _texture);

		_deviceManager->getSpriteHandler()->End();
		_deviceManager->getDevice()->EndScene();
	}

	// Display back buffer content to the screen
	_deviceManager->present();

	return 1;
}

int Game::update(float dt)
{

	//_billy.handlerInput();
	//_billy.update(dt);

	//billy.update(dt);
	//billy2.update(dt);

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
