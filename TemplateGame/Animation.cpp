#include "Animation.h"

Animation::Animation()
{
	this->_timePerFrame = 0;
	this->_currentFrame = 0;
	this->_sprite = Sprite::getInstance();
	this->_position = Vec3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0);
}

Animation::Animation(float timePerFrame)
{
	this->_timePerFrame = timePerFrame;
	this->_currentFrame = 0;
	this->_sprite = Sprite::getInstance();
	this->_position = Vec3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0);
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


void Animation::init(float timePerFrame)
{
	this->_currentFrame = 0;
	this->_timePerFrame = timePerFrame;
	this->_sprite = Sprite::getInstance();
	this->_position = Vec3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0);
}

void Animation::addSprite(eIdSprite id) {

	_listSpriteId.push_back(id);

	// Check co phai sprite dau tien ko ?
	// Neu dung thi fixPosVec = (0,0,0)
	if (_listSpriteId.size() > 1) {

		// Check sprite hien tai voi sprite dau tien
		RectSprite firstRect = _sprite->get(_listSpriteId[0]);
		RectSprite currentRect = _sprite->get(id);

		// Check height cua sprite co thay doi ko ?
		// Tra ve Vector3(0,0,0) nếu ko cần fix
		// Nguoc lại se tra ve Vector3(0,Y,0) , Y de + pos hien tai

		int heigthFirst = firstRect.getHeight();
		int heigthCurrent = currentRect.getHeight();

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

int Animation::render(pDeviceManager device, pTexture texture) {

	if (_timePerFrame <= 0) return 0;

	int eIdSprite = _listSpriteId[_currentFrame];

	RectSprite rect = _sprite->get(eIdSprite);
	RECT r = rect.getRECT();

	Vec3 _newPos = _position;
	_newPos += _fixPosVec[_currentFrame];

	device->getSpriteHandler()->Draw(
		texture->get(rect.getIdTexture()),
		&r,
		NULL,
		&_newPos,
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