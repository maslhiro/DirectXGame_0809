#pragma once
#include "define.h"

class InputHandler
{
public:
	InputHandler();
	~InputHandler();

	int handler(HWND, UINT, WPARAM, LPARAM);
	static InputHandler* getInstance();
	static InputHandler* _instance;

	std::unordered_map<int, bool> _keys;

	std::unordered_map<int, bool> getMapKey();

	void release();

};

typedef InputHandler *pInputHandler;