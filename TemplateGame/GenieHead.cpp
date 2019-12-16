#include "GenieHead.h"

GenieHead::GenieHead() : GameObject()
{
	_idType = eIdObject::GENIE_HEAD;
	_isTerminated = false;
	_dy = _gravity = 5.f;
	_moveTime = 0.f;
}

GenieHead::GenieHead(int id) : GameObject(id)
{
	_idType = eIdObject::GENIE_HEAD;
}

void GenieHead::loadResource()
{
	_listAnimation[eIdState::NONE] = AnimationManager::getInstance()->get(eIdAnimation::GENIE_HEAD_VISIBLE);

	_listAnimation[eIdState::EXPLODE] = AnimationManager::getInstance()->get(eIdAnimation::GENIE_HEAD_EXPLODE);

	this->setState(eIdState::NONE);
}

void GenieHead::render()
{
	if (_isTerminated) return;

	_curAnimation.setPosition(_posWorld);
	_curAnimation.setScale(_scale);

	_curAnimation.render(_device, _texture);
}

void GenieHead::update(float dt)
{

	if (_isTerminated) return;

	if (_state == eIdState::EXPLODE)
	{
		if (_curAnimation.getLoopCount() > 0) _isTerminated = true;
	}
	else
	{
		_moveTime += dt;
		_posWorld.y += _dy * dt;
		if (_moveTime > 2.f)
		{
			_moveTime = 0.f;
			_dy = -_dy;
		}

	}

	_curAnimation.setIsAnimated(_isAnimated);
	_curAnimation.update(dt);
}

void GenieHead::handlerInput(float)
{
}
