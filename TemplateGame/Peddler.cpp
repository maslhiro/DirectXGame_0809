#include "Peddler.h"

Peddler::Peddler() : GameObject()
{
	_idType = eIdObject::PEDDLER;
	_isAnimated = false;
	_isTerminated = false;
	posPlayer = Vec3();
}

Peddler::Peddler(int id) : GameObject(id)
{
	_idType = eIdObject::PEDDLER;
}

void Peddler::setPosPlayer(Vec3 val)
{
	posPlayer = val;
}


void Peddler::loadResource()
{
	_listAnimation[eIdState::WAIT_01] = AnimationManager::getInstance()->get(eIdAnimation::PEDDLER_IDLE);

	_listAnimation[eIdState::SELL] = AnimationManager::getInstance()->get(eIdAnimation::PEDDLER_SELL);

	_listAnimation[eIdState::PREPARE] = AnimationManager::getInstance()->get(eIdAnimation::PEDDLER_PREPARE);

	this->setState(eIdState::WAIT_01);
}

int Peddler::getState()
{
	return _state;
}

void Peddler::render()
{
	if (_isTerminated) return;

	_curAnimation.setPosition(_posWorld);
	_curAnimation.setScale(_scale);

	_curAnimation.render(_device, _texture);
}

void Peddler::update(float dt)
{
	if (_isTerminated) return;

	if (abs(_posWorld.x - posPlayer.x) <= 50 && abs(_posWorld.y - posPlayer.y) <= 50)
	{
		_isAnimated = true;
	}

	if (_state == eIdState::WAIT_01)
	{
		if (_curAnimation.getLoopCount() > 0)
		{
			//this->fixPosAnimation(eIdState::PREPARE);
			this->setState(eIdState::PREPARE);
		}
	}
	else if (_state == eIdState::PREPARE)
	{
		if (_curAnimation.getLoopCount() > 0)
		{
			//this->fixPosAnimation(eIdState::SELL);
			this->setState(eIdState::SELL);
		}
	}

	_curAnimation.setIsAnimated(_isAnimated);
	_curAnimation.setDrawingBound(true);
	_curAnimation.update(dt);
}

void Peddler::handlerInput(float)
{
}
