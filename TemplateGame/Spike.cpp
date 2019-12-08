#include "Spike.h"

Spike::Spike() : GameObject()
{
	_idType = eIdObject::SPIKE;
	_isTerminated = false;
}

Spike::Spike(int id) : GameObject(id)
{
	_idType = eIdObject::ROCK;
}

void Spike::loadResource()
{
	_listAnimation[eIdState::NONE] = AnimationManager::getInstance()->get(eIdAnimation::SPIKE_VISIBLE);

	this->setState(eIdState::NONE);
}

void Spike::render()
{
	_curAnimation.setIsAnimated(_isAnimated);
	_curAnimation.setPosition(_posWorld);
	_curAnimation.setScale(_scale);

	_curAnimation.render(_device, _texture);
}

void Spike::update(float dt)
{
	if (_isTerminated) return;

	_curAnimation.update(dt);
}

void Spike::handlerInput(float)
{
}
