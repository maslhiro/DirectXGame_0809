#include "Graphic.h"

Graphic::Graphic()
{
	InputHandler::getInstance();
}

Graphic::~Graphic()
{
	InputHandler::getInstance()->release();
}


Graphic::Graphic(HINSTANCE hInstance, int nCmdShow, int isFullScreen)
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
	wc.hIcon = LoadIcon(this->_hInstance, MAKEINTRESOURCE(IDI_ICON));
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = MAIN_WINDOW_TITLE;
	wc.hIconSm = LoadIcon(this->_hInstance, MAKEINTRESOURCE(IDI_ICON));

	RegisterClassEx(&wc);

	DWORD style;
	if (this->_isFullScreen)
		style = WS_EX_TOPMOST | WS_POPUP;
	else
		style = WS_OVERLAPPED | WS_SYSMENU | WS_VISIBLE;

	this->_hWnd = CreateWindow(
		WINDOW_CLASS_NAME,
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
		MessageBox(NULL, L"Error", L"Can't not create a Window", NULL);
		return 0;
	}

	ShowWindow(this->_hWnd, this->_nCmdShow);

	UpdateWindow(this->_hWnd);
	return 1;

}


int Graphic::isFullScreen() {
	return _isFullScreen;
}

HWND Graphic::getWnd()
{
	return this->_hWnd;
}

HINSTANCE Graphic::gethInstance()
{
	return this->_hInstance;
}

HRESULT CALLBACK Graphic::winProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return InputHandler::getInstance()->handler(hWnd, msg, wParam, lParam);
}
