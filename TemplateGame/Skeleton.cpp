#include "Skeleton.h"

Skeleton::Skeleton() : GameObject()
{
	_idType = eIdObject::SKELETON;
	_isTerminated = false;
}

Skeleton::Skeleton(int id) : GameObject(id)
{
	_idType = eIdObject::SKELETON;
}

void Skeleton::loadResource()
{
	_listAnimation[eIdState::NONE] = AnimationManager::getInstance()->get(eIdAnimation::SKELETON_VISIBLE);

	_listAnimation[eIdState::EXPLODE] = AnimationManager::getInstance()->get(eIdAnimation::APPLE_EXPLODE);

	this->setState(eIdState::NONE);
}

void Skeleton::render()
{
	if (_isTerminated) return;

	_curAnimation.setIsAnimated(_isAnimated);
	_curAnimation.setPosition(_posWorld);
	_curAnimation.setScale(_scale);

	_curAnimation.render(_device, _texture);
}

void Skeleton::update(float dt)
{
	if (_isTerminated) return;

	if (_state == eIdState::EXPLODE)
	{
		if (_curAnimation.getLoopCount() > 0) _isTerminated = true;
	}

	_curAnimation.update(dt);
}

void Skeleton::handlerInput(float)
{
}
