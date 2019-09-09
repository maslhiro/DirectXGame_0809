#pragma once
#include "define.h"

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
protected:

	HINSTANCE		_hInstance;
	HWND			_hWnd;
	int _nCmdShow;

	int				_isFullScreen;

	static HRESULT CALLBACK winProc(HWND, UINT, WPARAM, LPARAM);
private:

};

typedef Graphic* pGraphic;


