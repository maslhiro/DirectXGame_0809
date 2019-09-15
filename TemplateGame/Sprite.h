#pragma once
#include "define.h"
#include "Texture.h"

class Sprite
{
private:
	static Sprite * _instance;

	std::unordered_map<int, RectSprite> _listSprite;

public:

	Sprite();

	void init();

	int add(eIdTexture, const char*);

	RectSprite get(eIdSprite);

	static Sprite * getInstance();
};

typedef Sprite* pSprite;