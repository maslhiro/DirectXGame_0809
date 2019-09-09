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
	int getWidth();
	int getHeight();
	int getFrameRate();
	HWND getWnd();
	HINSTANCE gethInstance();
protected:

	HINSTANCE		_hInstance;
	HWND			_hWnd;
	int _nCmdShow;

	LPCWSTR			_wcName;
	int				_isFullScreen;

	int				_width;
	int				_height;
	int				_fps;

	static HRESULT CALLBACK winProc(HWND, UINT, WPARAM, LPARAM);
private:

};

typedef Graphic* pGraphic;


