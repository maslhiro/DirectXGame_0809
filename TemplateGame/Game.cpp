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

Game::Game(HINSTANCE hInstance, int nCmdShow)
{
	_hWindow = new Graphic(hInstance, nCmdShow, 0);
	_gameTime = GameTime::getInstance();
	_deviceManager = DeviceManager::getInstance();

}

int Game::init()
{
	_hWindow->initWindow();
	_deviceManager->init(_hWindow);
	_gameTime->init();

	_RPT0(0, "[INFO] Init Game done;\n");
	return 1;
}

int Game::run()
{
	MSG msg;

	float tickPerFrame = 1.0f / MAX_FRAME_RATE, delta = 0;

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
			_RPT1(0, "[INFO] Elapsed Time : %f \n", delta);
			_RPT1(0, "[INFO] Total Time : %f \n", _gameTime->getTotalGameTime());
			_RPT1(0, "[INFO] FPS : %f \n", 1.0f / delta);
			delta = 0;
			this->render();
		}
		else
		{
			Sleep(tickPerFrame - delta);

		}
	}

	return 1;
}

void Game::render()
{

	if (_deviceManager->getDevice()->BeginScene())
	{
		// Clear back buffer with a color
		_deviceManager->clearScreen();

		_deviceManager->getSpriteHandler()->Begin(D3DXSPRITE_ALPHABLEND);

		_deviceManager->getSpriteHandler()->End();
		_deviceManager->getDevice()->EndScene();
	}

	// Display back buffer content to the screen
	_deviceManager->present();
}

void Game::loadResource()
{
}

void Game::exit()
{
	isExit = 1;
}

void Game::release()
{
	if (_deviceManager != nullptr) _deviceManager->release();
}

Game::~Game()
{
}
