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
	this->_wcName = MAIN_WINDOW_TITLE;
	this->_isFullScreen = isFullScreen;

	this->_width = SCREEN_WIDTH;
	this->_height = SCREEN_HEIGHT;
	this->_fps = MAX_FRAME_RATE;
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
	wc.lpszClassName = this->_wcName;
	wc.hIconSm = NULL;

	RegisterClassEx(&wc);

	DWORD style;
	if (this->_isFullScreen)
		style = WS_EX_TOPMOST | WS_POPUP;
	else
		style = WS_OVERLAPPEDWINDOW;
	this->_hWnd = CreateWindow(
		this->_wcName,
		this->_wcName,
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
	//UpdateWindow(this->_hWnd);
	//return 1;

	// this struct holds Windows event messages
	MSG msg;

	// wait for the next message in the queue, store the result in 'msg'
	while (GetMessage(&msg, NULL, 0, 0))
	{
		// translate keystroke messages into the right format
		TranslateMessage(&msg);

		// send the message to the WindowProc function
		DispatchMessage(&msg);
	}

	// return this part of the WM_QUIT message to Windows
	return msg.wParam;
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

int Graphic::getWidth() {
	return _width;
}

int Graphic::getHeight() {
	return _height;
}

int Graphic::getFrameRate() {
	return _fps;
}

HWND Graphic::getWnd()
{
	return _hWnd;
}

HINSTANCE Graphic::gethInstance()
{
	return this->_hInstance;
}