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
	//_texture->add(eIdTexture::TANK, L"Resource//Object//Tank_Soldier.png", D3DCOLOR_XRGB(16, 216, 128));
	_texture->add(eIdTexture::TANK, L"Resource//Object//Tank_Soldier.png", D3DCOLOR_XRGB(255, 255, 255));
	_sprite->add(eIdTexture::TANK, "Resource//Object//Tank_Animation.txt");
}

Game::Game(HINSTANCE hInstance, int nCmdShow)
{
	_hWindow = new Graphic(hInstance, nCmdShow, 0);
	_gameTime = GameTime::getInstance();
	_deviceManager = DeviceManager::getInstance();
	_texture = Texture::getInstance();
	_sprite = Sprite::getInstance();

}

int Game::init()
{
	_gameTime->init();
	_hWindow->initWindow();
	_deviceManager->init(_hWindow);
	_texture->init(_deviceManager);

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

		RECT r1 = _sprite->get(eIdSprite::TANK_EXPLODING_01).getRECT();
		RECT r2 = _sprite->get(eIdSprite::TANK_EXPLODING_02).getRECT();
		RECT r3 = _sprite->get(eIdSprite::TANK_EXPLODING_03).getRECT();

		_deviceManager->getSpriteHandler()->Draw(
			_texture->get(_sprite->get(eIdSprite::TANK_EXPLODING_01).getIdTexture()),
			&r1, NULL,
			new Vec3(100, 100, 0),
			D3DCOLOR_XRGB(255, 255, 255));

		_deviceManager->getSpriteHandler()->Draw(
			_texture->get(_sprite->get(eIdSprite::TANK_EXPLODING_02).getIdTexture()),
			&r2, NULL,
			new Vec3(200, 100, 0),
			D3DCOLOR_XRGB(255, 255, 255));

		_deviceManager->getSpriteHandler()->Draw(
			_texture->get(_sprite->get(eIdSprite::TANK_EXPLODING_03).getIdTexture()),
			&r3, NULL,
			new Vec3(300, 100, 0),
			D3DCOLOR_XRGB(255, 255, 255));

		_deviceManager->getSpriteHandler()->End();
		_deviceManager->getDevice()->EndScene();
	}

	// Display back buffer content to the screen
	_deviceManager->present();

	return 1;
}

int Game::update(float) {

	//_tank->update();
	return 1;
}

void Game::exit()
{
	isExit = 1;
}

void Game::release()
{
	if (_deviceManager != nullptr) _deviceManager->release();
	if (_texture != nullptr) _texture->release();
	if (_gameTime != nullptr) _gameTime->release();
}

Game::~Game()
{
}
