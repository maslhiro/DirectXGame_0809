#include "InputHandler.h"

InputHandler* InputHandler::_instance = nullptr;

InputHandler::InputHandler()
{
}

InputHandler::~InputHandler()
{
}

pInputHandler InputHandler::getInstance()
{
	if (_instance == nullptr) {
		_instance = new InputHandler();
	}
	return _instance;
}

void InputHandler::release()
{
	delete _instance;
	_instance = nullptr;
}

void InputHandler::init()
{

}

HRESULT CALLBACK InputHandler::winProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		_RPT1(0, "PARAM KEY DOWN : %d \n", wParam);
		//_keys[(int)wParam] = true;
		break;
	case WM_KEYUP:
		_RPT1(0, "PARAM KEY UP : %d \n", wParam);
		//_keys[(int)wParam] = false;
		break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	return 0;
}

