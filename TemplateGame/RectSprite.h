#pragma once
#include <Windows.h>
class RectSprite
{
private:
	int idTexture;
public:

	int left, right, top, bottom;

	~RectSprite();
	RectSprite();

	void release();

	RectSprite(int, int, int, int);
	RectSprite(RECT);

	RECT getRECT();
	int getIdTexture();
	void setIdTexture(int);
};