#pragma once
#include "define.h"

class InputHandler
{
public:
	InputHandler();
	~InputHandler();

	static HRESULT CALLBACK winProc(HWND, UINT, WPARAM, LPARAM);
	static InputHandler* getInstance();
	static InputHandler* _instance;

	static std::unordered_map<int, bool> _keys;

	void release();
	void	init();


};

typedef InputHandler *pInputHandler;