#include "ExtraHealth.h"

ExtraHealth::ExtraHealth() : GameObject()
{
	_idType = eIdObject::EXTRA_HEALTH;
	_isTerminated = false;
}

ExtraHealth::ExtraHealth(int id) : GameObject(id)
{
	_idType = eIdObject::EXTRA_HEALTH;
}

void ExtraHealth::loadResource()
{
	_listAnimation[eIdState::NONE] = AnimationManager::getInstance()->get(eIdAnimation::EXTRA_HEALTH_VISIBLE);

	_listAnimation[eIdState::EXPLODE] = AnimationManager::getInstance()->get(eIdAnimation::ITEM_EXPLODE);

	this->setState(eIdState::NONE);
}

void ExtraHealth::render()
{
	if (_isTerminated) return;

	_curAnimation.setPosition(_posWorld);
	_curAnimation.setScale(_scale);

	_curAnimation.render(_device, _texture);
}

void ExtraHealth::update(float dt)
{
	_curAnimation.setIsAnimated(_isAnimated);

	if (_isTerminated) return;

	if (_state == eIdState::EXPLODE)
	{
		if (_curAnimation.getLoopCount() > 0) _isTerminated = true;
	}

	_curAnimation.update(dt);
}

void ExtraHealth::handlerInput(float)
{
}
