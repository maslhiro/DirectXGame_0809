#include "Rock.h"

Rock::Rock() : GameObject()
{
	_idType = eIdObject::ROCK;
	_isTerminated = false;
}

Rock::Rock(int id) : GameObject(id)
{
	_idType = eIdObject::ROCK;
}

void Rock::loadResource()
{
	_listAnimation[eIdState::NONE] = AnimationManager::getInstance()->get(eIdAnimation::ROCK_VISIBLE);

	this->setState(eIdState::NONE);
}

void Rock::render()
{
	_curAnimation.setIsAnimated(_isAnimated);
	_curAnimation.setPosition(_posWorld);
	_curAnimation.setScale(_scale);

	_curAnimation.render(_device, _texture);
}

void Rock::update(float dt)
{
	if (_isTerminated) return;

	_curAnimation.update(dt);
}

void Rock::handlerInput(float)
{
}
