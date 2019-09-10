#pragma once

#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <crtdbg.h>

#define WINDOW_CLASS_NAME L"Template Game 0809"
#define MAIN_WINDOW_TITLE L"Template Game"

#define BACKGROUND_COLOR D3DCOLOR_XRGB(255, 0, 0)

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define MAX_FRAME_RATE 60