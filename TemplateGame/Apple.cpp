#include "Apple.h"

Apple::Apple() : GameObject()
{
	_idType = eIdObject::APPLE;
}

void Apple::loadResource()
{
	_listAnimation[eIdState::NONE] = AnimationManager::getInstance()->get(eIdAnimation::APPLE_VISIBLE);

	this->setState(eIdState::NONE);
}

void Apple::render()
{
	_curAnimation.setPosition(_posWorld);
	_curAnimation.setScale(_scale);

	_curAnimation.render(_device, _texture);
}

void Apple::update(float dt)
{
	_curAnimation.update(dt);
}

void Apple::handlerInput()
{
}
