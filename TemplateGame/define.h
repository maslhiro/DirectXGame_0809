#pragma once
#include "resource.h"
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>

#include <sstream>
#include <iostream> 
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <crtdbg.h>

#define WINDOW_CLASS_NAME L"Template Game 0809"
#define MAIN_WINDOW_TITLE L"Template Game"

#define BACKGROUND_COLOR D3DCOLOR_XRGB(255, 0, 0)

#define SCREEN_WIDTH 720	
#define SCREEN_HEIGHT 576 

#define MAX_FRAME_RATE 60

typedef D3DXVECTOR3 Vec3;
typedef D3DXVECTOR2 Vec2;


struct Rect {
	float left;
	float top;
	float right;
	float bottom;
	Rect(float Left, float Top, float Right, float Bottom) {
		left = Left;
		top = Top;
		right = Right;
		bottom = Bottom;
	}
	Rect(float Left, float Top, float width, float height, float scaleX, float scaleY) {
		if (scaleX == 1)
			left = Left;
		else
			left = Left - width * (scaleX - 1.0);

		if (scaleY == 1)
			top = Top;
		else
			top = Top - height * (scaleY - 1.0);

		right = left + width * scaleX;
		bottom = top + height * scaleY;
	}
	Rect(RECT rect, float scaleX, float scaleY) {
		float width = abs(rect.left - rect.right);
		float height = abs(rect.top - rect.bottom);
		if (scaleX == 1)
			left = rect.left;
		else
			left = rect.left - width * (scaleX - 1.0);

		if (scaleY == 1)
			top = rect.top;
		else
			top = rect.top - height * (scaleY - 1.0);

		right = left + width * scaleX;
		bottom = top + height * scaleY;
	}
	Rect() {
		left = 0.0f;
		top = 0.0f;
		right = 0.0f;
		bottom = 0.0f;
	}
	Rect(RECT rect) {
		left = rect.left;
		top = rect.top;
		right = rect.right;
		bottom = rect.bottom;
	}
	RECT getRECT() {
		RECT rect;
		rect.left = (long)left;
		rect.top = (long)top;
		rect.right = (long)right;
		rect.bottom = (long)bottom;
		return rect;
	}
	float getWidth() {
		return abs(right - left);
	}
	float getHeight() {
		return abs(bottom - top);
	}
};