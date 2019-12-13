#pragma once
#include "resource.h"
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>

#include <unordered_map>
#include <sstream>
#include <fstream>
#include <iostream> 
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <crtdbg.h>
#include <algorithm>

#include "RectSprite.h"
#include "EnumID.h"

#define WINDOW_CLASS_NAME L"mashiro"
#define MAIN_WINDOW_TITLE L"mashiro"

#define BACKGROUND_COLOR D3DCOLOR_XRGB(255, 255, 255)

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 540

#define MAX_FRAME_RATE 90

#define TILE_SIZE 128

#define UNIT_WIDTH 250
#define UNIT_HEIGHT 250

// Khoang cach camera
#define DISTANCE_X 10
#define DISTANCE_Y 30

#define ALTITUDE_JUMP 130.f

#define BBOX_WIDTH 5

#define KEY_A 0x41
#define KEY_D 0x44
#define KEY_S 0x53
#define KEY_W 0x57

// attack
#define KEY_H 0x48
// jump
#define KEY_J 0x4A
// throw
#define KEY_K 0x4B

// Chuyen tu stand => wait
#define WAIT_TIME_ALADDIN 500.f

// Thoi gian dung  
#define WAIT_TIME_SPIKE 3.f
#define WAIT_TIME_ROCK 7.f

typedef D3DXVECTOR3 Vec3;
typedef D3DXVECTOR2 Vec2;

typedef LPDIRECT3DDEVICE9 DirectDevice;
typedef LPD3DXSPRITE DirectSprite;
typedef LPDIRECT3DSURFACE9 DirectSurface;
typedef LPDIRECT3DTEXTURE9 DirectTexture;