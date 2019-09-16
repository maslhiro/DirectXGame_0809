#include "Animation.h"

Animation::Animation()
{
}

Animation::Animation(float timePerFrame)
{
	this->_timePerFrame = timePerFrame;
	this->_currentFrame = 0;
}

Animation::~Animation()
{
}

void Animation::setTimePerFrame(float timePerFrame)
{
	this->_timePerFrame = timePerFrame;
}

void Animation::init(float timePerFrame, std::vector<int> listSpriteId)
{
	this->_timePerFrame = timePerFrame;
	this->_currentFrame = 0;
	this->_listSpriteId = listSpriteId;
}

void Animation::addSprite(eIdSprite id) {
	_listSpriteId.push_back(id);
	_RPT1(0, "[INFO] Add Sprite [%f] to Animation Done \n", id);
}

int Animation::getSprite(int index)
{
	return this->_listSpriteId[index];
}

void Animation::release() {
	this->_timePerFrame = NULL;

	/*this->_listSpriteId.clear();
	this->_listSpriteId.shrink_to_fit();*/
}

std::vector<int> Animation::getListSprite() {
	return this->_listSpriteId;
}

int Animation::render(pDeviceManager device, pTexture texture, pSprite sprite) {

	if (_timePerFrame <= 0) return 0;

	int eIdSprite = _listSpriteId[_currentFrame];

	RectSprite rect = sprite->get(eIdSprite);
	RECT r = rect.getRECT();

	device->getSpriteHandler()->Draw(
		texture->get(rect.getIdTexture()),
		&r,
		NULL,
		new Vec3(100, 100, 0),
		D3DCOLOR_XRGB(255, 255, 255));

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