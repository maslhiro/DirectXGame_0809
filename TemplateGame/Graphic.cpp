#include "Graphic.h"

Graphic::Graphic()
{
}

Graphic::~Graphic()
{
}


Graphic::Graphic(HINSTANCE hInstance, int nCmdShow,int isFullScreen )
{

	this->_hInstance = hInstance;
	this->_nCmdShow = nCmdShow;
	this->_isFullScreen = isFullScreen;

}

int Graphic::initWindow()
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = this->_hInstance;

	wc.lpfnWndProc = Graphic::winProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = MAIN_WINDOW_TITLE;
	wc.hIconSm = NULL;

	RegisterClassEx(&wc);

	DWORD style;
	if (this->_isFullScreen)
		style = WS_EX_TOPMOST | WS_POPUP;
	else
		style = WS_OVERLAPPEDWINDOW;
	this->_hWnd = CreateWindow(
		MAIN_WINDOW_TITLE,
		MAIN_WINDOW_TITLE,
		style,
		this->_isFullScreen ? 0 : CW_USEDEFAULT,
		this->_isFullScreen ? 0 : CW_USEDEFAULT,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		NULL,
		NULL,
		this->_hInstance,
		NULL);

	if (this->_hWnd == NULL)
	{
		MessageBox(NULL,L"Can't not create a Window",L"Error", NULL);
		return 0;
	}

	ShowWindow(this->_hWnd, this->_nCmdShow);
	UpdateWindow(this->_hWnd);
	return 1;

}



HRESULT CALLBACK Graphic::winProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
}


int Graphic::isFullScreen() {
	return _isFullScreen;
}

HWND Graphic::getWnd()
{
	return _hWnd;
}

HINSTANCE Graphic::gethInstance()
{
	return this->_hInstance;
}