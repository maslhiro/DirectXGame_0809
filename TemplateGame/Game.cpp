#include "Game.h"

int Game::isExit = 0;
pGraphic Game::_hWindow = NULL;

Animation tankAnimation;

Animation tankAnimation2;

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

	_animationManager->loadAnimation();

	tankAnimation = _animationManager->get(eIdAnimation::TANK_RUNNING);
	tankAnimation.setPosition(Vec3(100, 100, 0));
	tankAnimation.setScale(Vec2(-1, 1));

	tankAnimation2 = _animationManager->get(eIdAnimation::TANK_RUNNING);
	tankAnimation2.setPosition(Vec3(300, 300, 0));
	tankAnimation2.setScale(Vec2(2, 2));
}

Game::Game(HINSTANCE hInstance, int nCmdShow)
{
	_hWindow = new Graphic(hInstance, nCmdShow, 0);
	_gameTime = GameTime::getInstance();
	_deviceManager = DeviceManager::getInstance();
	_texture = Texture::getInstance();
	_sprite = Sprite::getInstance();
	_animationManager = AnimationManager::getInstance();

}

int Game::init()
{
	_gameTime->init();
	_hWindow->initWindow();
	_deviceManager->init(_hWindow);
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

		tankAnimation.render(_deviceManager, _texture);
		tankAnimation2.render(_deviceManager, _texture);

		_deviceManager->getSpriteHandler()->End();
		_deviceManager->getDevice()->EndScene();
	}

	// Display back buffer content to the screen
	_deviceManager->present();

	return 1;
}

int Game::update(float dt) {

	tankAnimation.update(dt);
	tankAnimation2.update(dt);
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

}

Game::~Game()
{
}
