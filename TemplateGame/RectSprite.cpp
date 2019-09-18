#include "RectSprite.h"

RectSprite::RectSprite()
{
	this->left = 0;
	this->right = 0;
	this->top = 0;
	this->bottom = 0;
}

RectSprite::~RectSprite()
{
}

RectSprite::RectSprite(int left, int top, int right, int bottom)
{
	this->left = left;
	this->right = right;
	this->top = top;
	this->bottom = bottom;
}

RectSprite::RectSprite(RECT rect) {
	this->left = rect.left;
	this->top = rect.top;
	this->right = rect.right;
	this->bottom = rect.bottom;
}

RECT RectSprite::getRECT() {
	RECT rect;
	rect.left = left;
	rect.top = top;
	rect.right = right;
	rect.bottom = bottom;
	return rect;
}

int RectSprite::getIdTexture() {
	return this->idTexture;
}

void RectSprite::setIdTexture(int id) {
	this->idTexture = id;
}

void RectSprite::release() {
	this->left = 0;
	this->right = 0;
	this->top = 0;
	this->bottom = 0;
	this->idTexture = 0;
}

D3DXVECTOR3 RectSprite::fixPosRECT(RectSprite nextRect)
{
	D3DXVECTOR3  _newPos = D3DXVECTOR3(0, 0, 0);

	int heightCurrent = this->top - this->bottom;
	int heightNext = nextRect.top - nextRect.bottom;

	_RPT1(0, "[INFO] RECT SPIRTE current height : %d \n", heightCurrent);
	_RPT1(0, "[INFO] RECT SPRITE height height : %d \n", heightNext);
	float _posY = (float)abs(heightCurrent - heightNext);

	if (_posY != 0)
	{
		_newPos = D3DXVECTOR3(0, _posY, 0);
	}

	return _newPos;
}

int RectSprite::getHeight()
{
	return bottom - top;
}