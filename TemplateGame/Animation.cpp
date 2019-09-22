﻿#include "Animation.h"

Animation::Animation()
{
	this->_timePerFrame = 0;
	this->_currentFrame = 0;
	this->_sprite = Sprite::getInstance();
	this->_position = Vec3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0);
	this->_scale = Vec2(1, 1);
	this->_drawingBound = false;
	this->_colorBound = D3DCOLOR_XRGB(255, 0, 0);

	D3DXCreateLine(DeviceManager::getInstance()->getDevice(), &lineDraw);

}

Animation::~Animation()
{
}

void Animation::setTimePerFrame(float timePerFrame)
{
	this->_timePerFrame = timePerFrame;
}

void Animation::setPosition(Vec3 pos)
{
	this->_position = pos;
}

void Animation::setScale(Vec2 scale)
{
	this->_scale = scale;
}

void Animation::setDrawingBound(bool draw)
{
	this->_drawingBound = draw;
}

void Animation::setColorBound(DWORD  color)
{
	this->_colorBound = color;
}

void Animation::init(float timePerFrame)
{
	this->_currentFrame = 0;
	this->_timePerFrame = timePerFrame;
	this->_sprite = Sprite::getInstance();
	this->_position = Vec3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0);
	this->_scale = Vec2(1, 1);
	this->_drawingBound = false;
}

void Animation::addSprite(eIdSprite id) {

	_listSpriteId.push_back(id);

	RectSprite currentRect = _sprite->get(id);
	Vec3 _origin = Vec3(currentRect.getWidth() / 2, currentRect.getHeight() / 2, 0);

	_listOrigin.push_back(_origin);

	// Check co phai sprite dau tien ko ?
	// Neu dung thi fixPosVec = (0,0,0)
	if (_listSpriteId.size() > 1) {

		// Check sprite hien tai voi sprite dau tien
		RectSprite firstRect = _sprite->get(_listSpriteId[0]);

		int heigthFirst = (int)firstRect.getHeight();
		int heigthCurrent = (int)currentRect.getHeight();

		if (heigthFirst != heigthCurrent) {
			float posY = (float)(heigthFirst - heigthCurrent);
			_fixPosVec.push_back(Vec3(0, posY, 0));
		}
		else
		{
			// 2 sprite = nhau nen tam ve ko doi
			_fixPosVec.push_back(Vec3(0, 0, 0));
		}
	}
	else {
		// Neu la spirte dau Vec = (0,0,0 )
		_fixPosVec.push_back(Vec3(0, 0, 0));
	}

	_RPT1(0, "[INFO] Add Sprite [%d] Done \n", id);
}

int Animation::getSprite(int index)
{
	return this->_listSpriteId[index];
}

void Animation::release() {
	this->_timePerFrame = NULL;
	this->lineDraw->Release();
	/*this->_listSpriteId.clear();
	this->_listSpriteId.shrink_to_fit();*/
}

std::vector<int> Animation::getListSprite() {
	return this->_listSpriteId;
}

int Animation::render(pDeviceManager device, pTexture texture) {

	if (_timePerFrame <= 0) return 0;

	int eIdSprite = _listSpriteId[_currentFrame];

	RectSprite rect = _sprite->get(eIdSprite);
	RECT r = rect.getRECT();

	// Fix pos
	Vec3 _newPos = _position;
	_newPos += _fixPosVec[_currentFrame];

	//Scale Sprite
	D3DXMATRIX matFinal;
	D3DXMATRIX matTransformed;
	D3DXMATRIX matOld;
	Vec2 _pos2D = Vec2(_newPos.x, _newPos.y);

	// get matrix texture
	device->getSpriteHandler()->GetTransform(&matOld);

	D3DXMatrixTransformation2D(
		&matTransformed,						// ma tran ket qua sau transform
		&_pos2D,								// goc toa do / diem neo
		0.0f,
		&_scale,								// ti le scale
		&_pos2D,								// goc toa do / diem neo
		0,										// góc xoay theo radian
		0										// vi trí
	);

	matFinal = matTransformed * matOld;

	//set matrix transformed
	device->getSpriteHandler()->SetTransform(&matFinal);


	// ve bound
	if (_drawingBound) {

		float top = _newPos.y - rect.getHeight() / 2 * _scale.y - 1;
		float bottom = _newPos.y + (LONG)rect.getHeight() / 2 * (LONG)_scale.y + 1;
		float left = _newPos.x - (LONG)rect.getWidth() / 2 * (LONG)_scale.x - 1;
		float right = _newPos.x + (LONG)rect.getWidth() / 2 * (LONG)_scale.x + 1;

		D3DXVECTOR2 line[] = {
			D3DXVECTOR2(left,top),
			D3DXVECTOR2(right,top),
			D3DXVECTOR2(right,bottom),
			D3DXVECTOR2(left,bottom),
			D3DXVECTOR2(left,top)
		};

		lineDraw->SetWidth(BBOX_WIDTH);
		lineDraw->Begin();
		lineDraw->Draw(line, 5, _colorBound);
		lineDraw->End();

	}

	// Ve sprite hien tai
	device->getSpriteHandler()->Draw(
		texture->get(rect.getIdTexture()),
		&r,
		&_listOrigin[_currentFrame],
		&_newPos,
		D3DCOLOR_XRGB(255, 255, 255));


	// Set lại old matrix texture
	device->getSpriteHandler()->SetTransform(&matOld);



	return 1;
}

int Animation::update(float dt)
{
	if (_totalTime >= _timePerFrame)
	{
		_totalTime = 0;

		// Kiem tra phai frame cuoi ko ?
		// Neu dung chuyen ve frame dau
		if (_currentFrame == _listSpriteId.size() - 1)
		{
			_currentFrame = 0;
		}
		else
		{
			_currentFrame += 1;
		}

	}
	else {
		_totalTime += dt;
	}

	return 1;
}