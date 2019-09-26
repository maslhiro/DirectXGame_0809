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

float RectSprite::getHeight()
{
	return (float)abs(bottom - top);
}

float RectSprite::getWidth()
{
	return (float)abs(right - left);
}