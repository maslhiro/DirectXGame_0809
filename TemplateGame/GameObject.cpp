#include "GameObject.h"

GameObject::GameObject()
{
	this->_device = DeviceManager::getInstance();
	this->_texture = Texture::getInstance();

	_isReverse = false;
	_isAnimated = true;

	_pos = Vec3(0, 0, 0);
	_scale = Vec2(1, 1);

	_state = 0;
	_speed = 1;
}

void GameObject::fixPosAnimation(int nextState)
{
	float fixBottom = this->fixPosHeight(nextState);
	float fixLeft = this->fixPosWidth(nextState);
	if (_isReverse) {
		// Tuong tu trong animation
		this->setPosition(_pos.x - fixLeft * _scale.x, _pos.y + fixBottom * _scale.y);
	}
	else this->setPosition(_pos.x + fixLeft * _scale.x, _pos.y + fixBottom * _scale.y);
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
	return this->_id;
}

void GameObject::setId(int id)
{
	this->_id = id;
}

void GameObject::setPosition(Vec3 pos)
{
	this->_pos = pos;
}

void GameObject::setPosition(Vec2 pos)
{
	this->_pos = Vec3(pos.x, pos.y, 0);
}

void GameObject::setPosition(float x, float y)
{
	this->setPosition(Vec2(x, y));
}

void GameObject::setScale(Vec2 pos)
{
	this->_scale = Vec2(pos.x, pos.y);
}

void GameObject::setScale(float x, float y)
{
	this->setScale(Vec2(x, y));
}

void GameObject::setIsReverse(bool isReverse)
{
	this->_isReverse = isReverse;
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