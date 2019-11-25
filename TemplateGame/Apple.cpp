#include "Apple.h"

Apple::Apple() : GameObject()
{
	_idType = eIdObject::APPLE;
	_isTerminated = false;
}

Apple::Apple(int id) : GameObject(id)
{
	_idType = eIdObject::APPLE;
}

void Apple::loadResource()
{
	_listAnimation[eIdState::NONE] = AnimationManager::getInstance()->get(eIdAnimation::APPLE_VISIBLE);

	_listAnimation[eIdState::EXPLODE] = AnimationManager::getInstance()->get(eIdAnimation::APPLE_EXPLODE);

	this->setState(eIdState::NONE);
}

void Apple::render()
{
	if (_isTerminated) return;

	_curAnimation.setIsAnimated(_isAnimated);
	_curAnimation.setPosition(_posWorld);
	_curAnimation.setScale(_scale);

	_curAnimation.render(_device, _texture);
}

void Apple::update(float dt)
{
	if (_isTerminated) return;

	if (_state == eIdState::EXPLODE)
	{
		if (_curAnimation.getLoopCount() == 1) _isTerminated = true;
	}

	_curAnimation.update(dt);
}

void Apple::handlerInput(float)
{
}
