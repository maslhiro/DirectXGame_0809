#include "WreckingBall.h"

WreckingBall::WreckingBall() :GameObject()
{
	_idType = eIdObject::WRECKING_BALL;
}

void WreckingBall::loadResource()
{
	_listAnimation[eIdState::NONE] = AnimationManager::getInstance()->get(eIdAnimation::WRECKING_BALL_VISIBLE);

	this->setState(eIdState::NONE);
}

void WreckingBall::render()
{
	if (_isTerminated) return;

	_curAnimation.setPosition(_posWorld);
	_curAnimation.setScale(_scale);

	_curAnimation.render(_device, _texture);
}

void WreckingBall::update(float dt)
{
	if (_isTerminated) return;

	_curAnimation.update(dt);
}

void WreckingBall::handlerInput(float)
{
}

