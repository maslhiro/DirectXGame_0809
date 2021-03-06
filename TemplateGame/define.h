﻿#pragma once
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
#include <ctime>

#include "RectSprite.h"
#include "EnumID.h"

#define WINDOW_CLASS_NAME L"mashiro"
#define MAIN_WINDOW_TITLE L"mashiro"

#define BACKGROUND_COLOR D3DCOLOR_XRGB(0, 0, 0)

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 540

#define MAX_FRAME_RATE 90

#define TILE_SIZE 128

#define UNIT_WIDTH 256
#define UNIT_HEIGHT 256

// Khoang cach camera
#define DISTANCE_X 15
#define DISTANCE_Y 40

#define ALTITUDE_JUMP 140.f

#define BBOX_WIDTH 5

#define KEY_A 0x41
#define KEY_D 0x44
#define KEY_S 0x53
#define KEY_W 0x57

#define KEY_ESC 0x1B

// attack
#define KEY_H 0x48
// jump
#define KEY_J 0x4A
// throw
#define KEY_K 0x4B
// buy
#define KEY_F 0x46

// Chuyen tu stand => wait
#define WAIT_TIME_ALADDIN 5.f

#define FLASH_TIME_ALADDIN 0.8f

#define NUM_APPLE_DEFAULT 10

#define NUM_COIN_DEFAULT 15

#define NUM_LIFE_DEFAULT 3

// Thoi gian dung  
#define WAIT_TIME_SPIKE 0.5f
#define WAIT_TIME_ROCK 5.f
#define WAIT_TIME_NAHBI 5.f

// Khoang cach de enermy di chuyen den khi aladdin den gan
// Doi voi cac enermy di chuyen dc
#define ATTACK_DISTANCE 200
#define MOVE_DISTANCE 250

#define BLOOD_ALADDIN 80
#define BLOOD_NAHBI 20
#define BLOOD_FAZAL 20
#define BLOOD_JAFAR 200

#define ATTACK_DAMAGE_ALADDIN 10
#define THROW_DAMAGE_ALADDIN 10
#define DAMAGE_ENERMY 5

#define SCORE_GENIE_HEAD 150
#define SCORE_COIN 50

typedef D3DXVECTOR3 Vec3;
typedef D3DXVECTOR2 Vec2;

typedef LPDIRECT3DDEVICE9 DirectDevice;
typedef LPD3DXSPRITE DirectSprite;
typedef LPDIRECT3DSURFACE9 DirectSurface;
typedef LPDIRECT3DTEXTURE9 DirectTexture;