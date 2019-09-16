﻿#pragma once
#include "resource.h"
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>

#include <unordered_map>
#include <sstream>
#include <iostream> 
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <crtdbg.h>

#include "RectSprite.h"
#include "EnumID.h"

#define WINDOW_CLASS_NAME L"Template Game"
#define MAIN_WINDOW_TITLE L"Template Game"

#define BACKGROUND_COLOR D3DCOLOR_XRGB(255, 255, 255)

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 540

#define MAX_FRAME_RATE 60

typedef D3DXVECTOR3 Vec3;
typedef D3DXVECTOR2 Vec2;

typedef LPDIRECT3DDEVICE9 DirectDevice;
typedef LPD3DXSPRITE DirectSprite;
typedef LPDIRECT3DSURFACE9 DirectSurface;
typedef LPDIRECT3DTEXTURE9 DirectTexture;
