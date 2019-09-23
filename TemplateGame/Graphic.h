#pragma once
#include "define.h"
#include "InputHandler.h"

class Graphic
{
public:
	Graphic();
	Graphic(HINSTANCE, int, int);
	~Graphic();
	int initWindow();

	int isFullScreen();

	HWND getWnd();
	HINSTANCE gethInstance();

	static HRESULT CALLBACK winProc(HWND, UINT, WPARAM, LPARAM);
protected:

	HINSTANCE		_hInstance;
	HWND			_hWnd;
	int _nCmdShow, _isFullScreen;

	pInputHandler _input;

};

typedef Graphic* pGraphic;


