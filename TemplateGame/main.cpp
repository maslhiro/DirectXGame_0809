#include "define.h"
#include "Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	pGame _game = new Game(hInstance, nCmdShow);
	_game->init();
	_game->loadResource();
	_game->run();
	_game->release();
	delete _game;
	return 0;
}