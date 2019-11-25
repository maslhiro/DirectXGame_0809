#include "GameObject.h"

RECT GameObject::getBoundingBox()
{
	if (_isStaticObj == false) {
		if (_listAnimation.size() > 0) {

			_curAnimation.setPosition(_posWorld);
			RECT bounding = _curAnimation.getBounding();

			//_RPT1(0, "[INFO] %d %d %d %d \n", bb.left, bb.top, bb.right, bb.bottom);
			return bounding;
		}
		else return RECT();
	}
	else {
		// TH : gameobj static : LAND, ROPE , ...
		return _boundingWorld;
	}
}

RECT GameObject::getCurrentBoudingBox()
{
	if (_isStaticObj == false) {
		if (_listAnimation.size() > 0) {

			_curAnimation.setPosition(_posWorld);
			return _curAnimation.getCurrentBounding();
		}
		else return RECT();
	}
	else {
		// TH : gameobj static : LAND, ROPE , ...
		return _boundingWorld;
	}
}

GameObject::GameObject()
{
	this->_device = DeviceManager::getInstance();
	this->_texture = Texture::getInstance();

	_isStaticObj = false;
	_boundingWorld = RECT();

	_isFlip = false;
	_isAnimated = true;

	_posWorld = Vec3(0, 0, 0);
	_scale = Vec2(1, 1);

	_state = eIdState::NONE;
	_speed = 0.0f;
	_dx = _dy = 0.0f;

	_id = 0;
}

GameObject::GameObject(int id)
{
	this->_device = DeviceManager::getInstance();
	this->_texture = Texture::getInstance();

	_isStaticObj = false;
	_boundingWorld = RECT();

	_isFlip = false;
	_isAnimated = true;

	_posWorld = Vec3(0, 0, 0);
	_scale = Vec2(1, 1);

	_state = eIdState::NONE;

	_speed = 0.0f;
	_dx = _dy = 0.0f;

	_id = id;
}

bool GameObject::checkCollision(RECT r)
{
	RECT _cur = getCurrentBoudingBox();
	return !(
		_cur.left > r.right ||
		_cur.right < r.left ||
		_cur.top > r.bottom ||
		_cur.bottom < r.top);
}

// dt dx dy
float GameObject::checkCollision_SweptAABB(RECT _rectOther, float dt, float dx, float dy, int &direction)
{
	int dxEntry, dxExit;
	int dyEntry, dyExit;

	RECT _rectObj = getCurrentBoudingBox();

	if (dx > 0.0f)
	{
		dxEntry = _rectOther.left - _rectObj.right;
		dxExit = _rectOther.right - _rectObj.left;
	}
	else
	{
		dxEntry = _rectObj.left - _rectOther.right;
		dxExit = _rectObj.right - _rectOther.left;
	}


	if (dy > 0.0f)
	{
		dyEntry = _rectOther.top - _rectObj.bottom;
		dyExit = _rectOther.bottom - _rectObj.top;
	}
	else
	{
		dyEntry = _rectObj.top - _rectOther.bottom;
		dyExit = _rectObj.bottom - _rectOther.top;
	}


	float txEntry, txExit;
	float tyEntry, tyExit;

	//// tim thoi gian va cham
	if (dx == 0.0f)
	{
		// đang đứng yên thì bằng vô cực (chia cho  0)
		txEntry = -std::numeric_limits<float>::infinity();
		txExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		txEntry = dxEntry / abs(dx);
		txExit = dxExit / abs(dx);
	}

	if (dy == 0.0f)
	{
		tyEntry = -std::numeric_limits<float>::infinity();
		tyExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		tyEntry = dyEntry / abs(dy);
		tyExit = dyExit / abs(dy);
	}

	/*_RPT0(0, "===================\n");
	_RPT1(0, "[SWEPT AABB] Vx : %f Vy %f \n", dx, dy);
	_RPT1(0, "[SWEPT AABB] DELTA TIME : %f \n", dt);
	_RPT1(0, "[SWEPT AABB] CURRENT FRAME : %d \n", _curAnimation.getCurrentFrame());
	_RPT1(0, "[SWEPT AABB] TX Entry : %f TX Exit %f \n", txEntry, txExit);
	_RPT1(0, "[SWEPT AABB] TY Entry : %f TY Exit %f \n", tyEntry, tyExit);
	_RPT1(0, "[SWEPT AABB] CUR : %d %d %d %d \n", _rectObj.left, _rectObj.top, _rectObj.right, _rectObj.bottom);
	_RPT1(0, "[SWEPT AABB] OTHER : %d %d %d %d \n", _rectOther.left, _rectOther.top, _rectOther.right, _rectOther.bottom);*/


	// thời gian va chạm là thời gian lớn nhất của 2 trục (2 trục phải cùng tiếp xúc thì mới va chạm)
	float entryTime = max(txEntry, tyEntry);
	// thời gian hết va chạm là thời gian của 2 trục, (1 cái ra khỏi là object hết va chạm)
	float exitTime = min(txExit, tyExit);

	// kiểm tra xem có thể va chạm không
	if (entryTime > exitTime || (txEntry < 0.f && tyEntry < 0.f) || txEntry > dt || tyEntry > dt)
	{
		return dt;
	}

	//Kiem tra xem time theo chieu x hay y se dung obj truoc
	if (txEntry > tyEntry)
	{
		// va cham theo truc x
		if (dxEntry > 0.0f)
		{
			if (dx != 0.0f)	direction = eDirection::RIGHT;
		}
		// dx co the am neu object  va cham voi other
		else
		{
			if (dx != 0.0f)	direction = eDirection::LEFT;
		}
	}
	else
	{
		if (dyEntry > 0.0f)
		{
			if (dy != 0.0f)	direction = eDirection::TOP;
		}
		else
		{
			if (dy != 0.0f)	direction = eDirection::BOTTOM;
		}
	}

	//_RPT1(0, "[INFO] ENTRY TIME : %f \n", entryTime);

	return entryTime;
}

void GameObject::fixPosAnimation(int nextState)
{
	float fixBottom = this->fixPosHeight(nextState);
	float fixLeft = this->fixPosWidth(nextState);

	if (_isFlip) {
		// Tuong tu trong animation
		this->setPositionWorld(_posWorld.x - fixLeft * _scale.x, _posWorld.y + fixBottom * _scale.y);
	}
	else this->setPositionWorld(_posWorld.x + fixLeft * _scale.x, _posWorld.y + fixBottom * _scale.y);
}

float GameObject::fixPosHeight(int nextState)
{
	if (_listAnimation.size() > 1) {
		float _nextHeight = _listAnimation[nextState].getHeight();
		float _curtHeight = _curAnimation.getHeight();

		return (_curtHeight - _nextHeight) / 2;
	}
	return 0;
}

float GameObject::fixPosWidth(int nextState)
{
	if (_listAnimation.size() > 1) {
		float _nextWidth = _listAnimation[nextState].getWidth();
		float _curtWidth = _curAnimation.getWidth();

		return (_nextWidth - _curtWidth) / 2;
	}
	return 0;
}


GameObject::~GameObject()
{

}

int GameObject::getId()
{
	//_RPT1(0, "[GET ID] %d \n", _id);
	return this->_id;
}

void GameObject::setId(int id)
{
	this->_id = id;

	//_RPT1(0, "[SET ID] %d \n", _id);
}

void GameObject::setIsStaticObj(bool val)
{
	this->_isStaticObj = val;
}

bool GameObject::getIsStaticObj()
{
	return this->_isStaticObj;
}

void GameObject::setRectWorld(RECT rec)
{
	this->_boundingWorld = rec;
}

int GameObject::getIdType()
{
	return this->_idType;
}

void GameObject::setIdType(int id)
{
	this->_idType = id;
}

void GameObject::setPositionWorld(Vec3 pos)
{
	this->_posWorld = pos;
}

void GameObject::setPositionWorld(Vec2 pos)
{
	this->_posWorld = Vec3(pos.x, pos.y, 0);
}

void GameObject::setPositionWorld(int x, int y)
{
	this->setPositionWorld(Vec3((float)x, (float)y, 0));
}

Vec3 GameObject::getPosWorld()
{
	return _posWorld;
}

void GameObject::setScale(Vec2 pos)
{
	this->_scale = Vec2(pos.x, pos.y);
}

void GameObject::setScale(float x, float y)
{
	this->setScale(Vec2(x, y));
}

void GameObject::setIsFlip(bool isFlip)
{
	this->_isFlip = isFlip;
}

void GameObject::setIsAnimated(bool isAni)
{
	this->_isAnimated = isAni;
}

void GameObject::setIsTerminated(bool val)
{
	_isTerminated = val;
}

void GameObject::setScale(float scale)
{
	this->setScale(Vec2(scale, scale));
}

void GameObject::setSpeed(float speed)
{
	this->_speed = speed;
	this->_dx = speed;
}

void GameObject::setGravity(float val)
{
	this->_gravity = val;
	this->_dy = -val;
}

void GameObject::setDx(float val)
{
	this->_dx = val;
}

void GameObject::setDy(float val)
{
	this->_dy = val;
}

void GameObject::setState(int state)
{
	this->_state = state;
	_curAnimation = _listAnimation[state];
}

int GameObject::getState()
{
	return _state;
}

int GameObject::getCurrentFrame()
{
	return _curAnimation.getCurrentFrame();
}
