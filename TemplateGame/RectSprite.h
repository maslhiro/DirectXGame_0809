#pragma once
#include <Windows.h>
#include <d3dx9.h>
#include <crtdbg.h>

class RectSprite
{
private:
	int idTexture;
public:

	int left, right, top, bottom;

	~RectSprite();
	RectSprite();

	void release();

	float getHeight();
	float getWidth();

	RectSprite(int, int, int, int);
	RectSprite(RECT);

	RECT getRECT();
	int getIdTexture();
	void setIdTexture(int);

};