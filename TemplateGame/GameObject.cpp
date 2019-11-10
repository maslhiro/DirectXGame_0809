#include "GameObject.h"

RECT GameObject::getBoudingBox()
{
	if (_isStaticObj == false) {
		if (_listAnimation.size() > 0) {
			float width_Ani = _listAnimation[_state].getWidth() * _scale.x / 2.0;
			float height_Ani = _listAnimation[_state].getHeight() * _scale.y / 2.0;
			// ướm vào posWorld mới ra BOUDING :( DM

			RECT bouding;
			bouding.left = _posWorld.x - (int)ceil(width_Ani);
			bouding.right = _posWorld.x - (int)ceil(width_Ani);
			bouding.top = _posWorld.y - (int)ceil(height_Ani);
			bouding.bottom = _posWorld.y + (int)ceil(height_Ani);


			return bouding;
		}
		else return RECT();
	}
	else {
		// TH : gameobj static : LAND, ROPE , ...
		return _boudingWorld;
	}
}

GameObject::GameObject()
{
	this->_device = DeviceManager::getInstance();
	this->_texture = Texture::getInstance();

	_isStaticObj = false;
	_boudingWorld = RECT();

	_isFlip = false;
	_isAnimated = true;

	_posWorld = Vec3(0, 0, 0);
	_scale = Vec2(1, 1);

	_state = eIdState::NONE;
	_speed = 1;
}

GameObject::GameObject(int id)
{
	this->_device = DeviceManager::getInstance();
	this->_texture = Texture::getInstance();

	_isStaticObj = false;
	_boudingWorld = RECT();

	_isFlip = false;
	_isAnimated = true;

	_posWorld = Vec3(0, 0, 0);
	_scale = Vec2(1, 1);

	_state = eIdState::NONE;
	_speed = 1;

	_id = id;
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
		float _curtHeight = _listAnimation[_state].getHeight();

		return (_curtHeight - _nextHeight) / 2;
	}
	return 0;
}

float GameObject::fixPosWidth(int nextState)
{
	if (_listAnimation.size() > 1) {
		float _nextWidth = _listAnimation[nextState].getWidth();
		float _curtWidth = _listAnimation[_state].getWidth();

		return (_nextWidth - _curtWidth) / 2;
	}
	return 0;
}


GameObject::~GameObject()
{

}

int GameObject::getId()
{
	_RPT1(0, "[GET ID] %s \n", _id);
	return this->_id;
}

void GameObject::setId(int id)
{
	this->_id = id;
	_RPT1(0, "[SET ID] %s \n", _id);
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
	this->_boudingWorld = rec;
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

void GameObject::setScale(float scale)
{
	this->setScale(Vec2(scale, scale));
}

void GameObject::setSpeed(float speed)
{
	this->_speed = speed;
}

void GameObject::setState(int state)
{
	this->_state = state;
	_curAnimation = _listAnimation[state];
}