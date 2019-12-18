#include "SavePoint.h"

SavePoint::SavePoint() : GameObject()
{
	_idType = eIdObject::SAVE_POINT;
	_isAnimated = false;
}

SavePoint::SavePoint(int id) : GameObject(id)
{
	_idType = eIdObject::SAVE_POINT;
}

void SavePoint::loadResource()
{
	_listAnimation[eIdState::NONE] = AnimationManager::getInstance()->get(eIdAnimation::SAVE_POINT_VISIBLE);

	this->setState(eIdState::NONE);
}

void SavePoint::render()
{
	_curAnimation.setPosition(_posWorld);
	_curAnimation.setScale(_scale);

	_curAnimation.render(_device, _texture);
}

void SavePoint::update(float dt)
{
	_curAnimation.setIsAnimated(_isAnimated);
	_curAnimation.update(dt);
}

void SavePoint::handlerInput(float)
{
}
