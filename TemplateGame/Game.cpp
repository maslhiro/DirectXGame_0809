#include "Game.h"

int Game::isExit = 0;
pGraphic Game::_hWindow = NULL;

pGraphic Game::getWindow()
{
	return _hWindow;
}

Game::Game()
{
}

Game::Game(HINSTANCE hInstance, int nCmdShow)
{
	_hWindow = new Graphic(hInstance, nCmdShow, 0);
	_deviceManager = new DeviceManager();
}

int Game::init()
{
	_hWindow->initWindow();
	_deviceManager->init(_hWindow);
	return 1;
}

/*
	Utility function to wrap LPD3DXSPRITE::Draw
*/
int Game::run()
{
	MSG msg;
	int done = 0;
	DWORD frameStart = GetTickCount();
	DWORD tickPerFrame = 1000 / MAX_FRAME_RATE;

	while (!isExit)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) done = 1;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		DWORD now = GetTickCount();

		// dt: the time between (beginning of last frame) and now
		// this frame: the frame we are about to render
		DWORD dt = now - frameStart;

		if (dt >= tickPerFrame)
		{
			frameStart = now;
			this->render();
		}
		else
			Sleep(tickPerFrame - dt);
	}

	return 1;
}

void Game::render()
{
	
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
	if(_deviceManager!=nullptr) _deviceManager->release();
}

Game::~Game()
{
}
