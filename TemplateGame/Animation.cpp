#include "Animation.h"

int reverse = 1;

Animation::Animation()
{
	this->_timePerFrame = 0;
	this->_currentFrame = 0;
	this->_loopCount = 0;

	this->_isLoop = true;
	this->_isFlip = false;
	this->_isReverse = false;
	this->_isAnimated = true;
	this->_drawingBound = false;

	this->_typeFixPos = 1;
	this->_indexStart = 0;

	this->_sprite = Sprite::getInstance();
	this->_position = Vec3(0, 0, 0);
	this->_scale = Vec2(1, 1);
	this->_colorBound = D3DCOLOR_XRGB(255, 0, 0);

	D3DXCreateLine(DeviceManager::getInstance()->getDevice(), &_lineDraw);

}

Animation::~Animation()
{
}

void Animation::setIsLoop(bool isLoop)
{
	this->_isLoop = isLoop;
}

void Animation::setIsFlip(bool isFlip)
{
	this->_isFlip = isFlip;
}

void Animation::setIsAnimated(bool isAni)
{
	this->_isAnimated = isAni;
}

void Animation::setTypeFixPos(int val)
{
	this->_typeFixPos = val;
}

void Animation::setIndexStart(int index)
{
	this->_indexStart = index;
}

void Animation::setIsReverse(bool isReverse)
{
	this->_isReverse = isReverse;
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

void Animation::setScale(float x, float y)
{
	this->setScale(Vec2(x, y));
}

void Animation::setDrawingBound(bool draw)
{
	this->_drawingBound = draw;
}

void Animation::setColorBound(DWORD  color)
{
	this->_colorBound = color;
}

int Animation::getLoopCount() {
	return _loopCount;
}

void Animation::addSprite(eIdSprite id) {

	RectSprite currentRect = _sprite->get(id);

	Vec3 _origin = Vec3(currentRect.getWidth() / 2, currentRect.getHeight() / 2, 0);
	_listOrigin.push_back(_origin);
	//_RPT1(0, "[INFO] Origin Sprite [%d] || x : %f || y : %f \n", id, _origin.x, _origin.y);

	// Check co phai sprite dau tien ko ?
	if (_listSpriteId.size() >= 1) {

		// canh bottom cac frame trung nhau
		float fixHeight = this->fixPosHeight(currentRect);
		float fixWidth = this->fixPosWidth(currentRect);

		_fixPosVec.push_back(Vec3(fixWidth, fixHeight, 0));
		//_RPT1(0, "[INFO] Fix Pos Sprite [%d] || height : %f || width : %f \n", id, fixHeight, fixWidth);

	}
	else {
		// Neu la spirte dau Vec = (0,0,0 )
		_fixPosVec.push_back(Vec3(0, 0, 0));
	}

	// cuoi cung moi add sprite vao frame
	_listSpriteId.push_back(id);
	_RPT1(0, "[INFO] Add Sprite [%d] Done \n", id);
}

int Animation::getSprite(int index)
{
	return this->_listSpriteId[index];
}

void Animation::release() {
	this->_timePerFrame = NULL;
	delete this->_lineDraw;
	_lineDraw = nullptr;
}

std::vector<int> Animation::getListSprite() {
	return this->_listSpriteId;
}

int Animation::render(pDeviceManager device, pTexture texture) {

	if (_timePerFrame <= 0) return 0;

	int eIdSprite = _listSpriteId[_currentFrame];

	RectSprite rect = _sprite->get(eIdSprite);
	RECT r = rect.getRECT();

	//Scale Sprite
	D3DXMATRIX matFinal;
	D3DXMATRIX matTransformed;
	D3DXMATRIX matOld;

	Vec2 scale = this->_scale;

	// Lật ngước sprite lại 
	if (_isFlip) scale = Vec2(_scale.x*-1, _scale.y);
	// Fix pos
	Vec3 _newPos = _position;
	Vec3 _fixPos = _fixPosVec[_currentFrame];

	if (_isFlip)
	{
		// Thuong chi co player va entity fix pos left bottom nen khi lat 
		// chi xet TH nay

		// Dao nay hoi thieu ngu? nen v =_=

		switch (this->_typeFixPos)
		{
		case 1:
		{
			// LEFT BOTTOM	
			// nếu lật sprite lại thì fix pos theo góc bottom right
			// Khi lat sprite lai thi left bottom => right top 
			// nhung ma hinh can right bottom => -fixPos.y 
			_newPos -= Vec3(_fixPos.x*_scale.x, -_fixPos.y*_scale.y, 0);
			break;
		}

		case 2:
		{
			// LEFT TOP
			//_newPos += Vec3(_fixPos.x*_scale.x, -_fixPos.y*_scale.y, 0);
			break;
		}
		case 3:
		{
			// center 
			break;
		}
		default:
			break;
		}
	}
	else
	{
		////fix pos theo goc bottom left
		//_RPT1(0, "[INFO] TYPE FIX POS %d \n", _typeFixPos);
		switch (this->_typeFixPos)
		{
		case 1:
		{
			// LEFT BOTTOM
			_newPos += Vec3(_fixPos.x*_scale.x, _fixPos.y*_scale.y, 0);
			break;
		}

		case 2:
		{
			// LEFT TOP
			_newPos += Vec3(_fixPos.x*_scale.x, -_fixPos.y*_scale.y, 0);
			break;
		}
		case 3:
		{
			// center 
			// Khoi can xet newPos vi pos hien tai la trung tam roi 
			break;
		}
		default:
			break;
		}


	}
	//_RPT1(0, "[INFO] FIX POS %d :x %f y %f \n", _currentFrame, _newPos.x, _newPos.y);

	Vec2 _pos2D = Vec2(_newPos.x, _newPos.y);

	// get matrix texture
	device->getSpriteHandler()->GetTransform(&matOld);

	D3DXMatrixTransformation2D(
		&matTransformed,						// ma tran ket qua sau transform
		&_pos2D,								// goc toa do / diem neo
		0.0f,
		&scale,									// ti le scale
		&_pos2D,								// goc toa do / diem neo
		0,										// góc xoay theo radian
		0										// vi trí
	);

	//_RPT1(0, "[INFO] FIX POS AFTER SCALE %d :x %f y %f \n", _currentFrame, _pos2D.x, _pos2D.y);


	matFinal = matTransformed * matOld;

	//set matrix transformed
	device->getSpriteHandler()->SetTransform(&matFinal);


	// ve bound
	if (_drawingBound) {

		float top = _newPos.y - rect.getHeight() / 2 * _scale.y - 1;
		float bottom = _newPos.y + rect.getHeight() / 2 * _scale.y + 1;
		float left = _newPos.x - rect.getWidth() / 2 * _scale.x - 1;
		float right = _newPos.x + rect.getWidth() / 2 * _scale.x + 1;

		Vec2 line[] = {
			Vec2(left,top),
			Vec2(right,top),
			Vec2(right,bottom),
			Vec2(left,bottom),
			Vec2(left,top)
		};

		_lineDraw->SetWidth(BBOX_WIDTH);
		_lineDraw->Begin();
		_lineDraw->Draw(line, 5, _colorBound);
		_lineDraw->End();

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

		// Kiem tra co animated co cho phep ve sprite tiep ko ? 
		if (!_isAnimated) return 0;

		if (!_isReverse) {
			// Lap binh thuong frame cuoi => frame dau
			// Kiem tra phai frame cuoi ko ?
			// Neu dung chuyen ve frame dau
			if (_currentFrame == _listSpriteId.size() - 1)
			{
				// quay nguoc frame neu den frame cuoi
				_currentFrame = _indexStart;

				_loopCount += 1;
			}
			else
			{
				if (!_isLoop) {
					if (_loopCount == 1) _currentFrame = _indexStart;
					else _currentFrame += 1;
				}
				// TH cho phep lap ani
				else _currentFrame += 1;

			}
		}
		else {
			if (_currentFrame == _listSpriteId.size() - 1)
			{
				reverse = -1;
				_currentFrame -= 1;

				_loopCount += 1;
			}
			else
			{
				if (!_isLoop) {
					if (_loopCount == 1) _currentFrame = _indexStart;
					else _currentFrame += 1;
				}

				// TH cho phep lap ani
				else if (reverse < 0 && _currentFrame == _indexStart) {
					reverse = 1;
					_currentFrame += 1;
				}
				else _currentFrame += 1 * reverse;

			}
		}

	}
	else {
		_totalTime += dt;
	}

	return 1;
}

float Animation::getHeight() {
	if (_listSpriteId.size() > 0) {
		return _sprite->get(_listSpriteId[0]).getHeight();
	}
	return 0;
}

RECT Animation::getBouding()
{
	if (_listSpriteId.size() > 0) {
		return _sprite->get(_listSpriteId[_currentFrame]).getRECT();
	}
	return RECT();
}

float Animation::getWidth() {
	if (_listSpriteId.size() > 0) {
		return _sprite->get(_listSpriteId[0]).getWidth();
	}
	return 0;
}

float Animation::fixPosHeight(RectSprite _nextRect)
{
	// get sprite dau tien cua frame
	RectSprite firstRect = _sprite->get(_listSpriteId[0]);

	float heigthFirst = firstRect.getHeight();
	float heigthCurrent = _nextRect.getHeight();

	return ((heigthFirst - heigthCurrent) / 2);
}

float Animation::fixPosWidth(RectSprite _nextRect)
{
	// get sprite dau tien cua frame
	RectSprite firstRect = _sprite->get(_listSpriteId[0]);

	float widthFirst = firstRect.getWidth();
	float widthCurrent = _nextRect.getWidth();

	return ((widthCurrent - widthFirst) / 2);

}