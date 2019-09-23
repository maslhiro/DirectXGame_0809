#include "GameObject.h"

GameObject::GameObject()
{
	this->_device = DeviceManager::getInstance();
	this->_texture = Texture::getInstance();
	_pos = Vec3(0, 0, 0);
	_scale = Vec2(1, 1);
	_state = _preState = 0;
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
	this->_preState = this->_state;
	this->_state = state;
}