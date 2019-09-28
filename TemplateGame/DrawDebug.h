#pragma once
#include "define.h"
#include "DeviceManager.h"

class DrawDebug
{
private:

	static DrawDebug* _instance;
	//DWORD  _colorBound;
	ID3DXLine *_lineDraw;
public:
	DrawDebug();

	static DrawDebug* getInstance();

	static void release();

	void init();

	void drawLine(Vec2, Vec2, DWORD = D3DCOLOR_XRGB(255, 0, 0), float = 2);

	void drawLineHorizontal(float, float, DWORD = D3DCOLOR_XRGB(255, 0, 0), float = 2);

	void drawLineVertical(float, float, DWORD = D3DCOLOR_XRGB(255, 0, 0), float = 2);

};

typedef DrawDebug* pDrawDebug;

