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

void Peddler::fixPosBottom(int nextState)
{
	float fixBottom = this->fixPosHeight(nextState);
	float fixLeft = (nextState == eIdState::PREPARE ? 0 : 40);

	this->setPositionWorld(_posWorld.x + fixLeft, _posWorld.y + fixBottom * _scale.y);
}

void Peddler::update(float dt)
{
	if (_isTerminated) return;

	if (abs(_posWorld.x - posPlayer.x) <= ATTACK_DISTANCE && abs(_posWorld.y - posPlayer.y) <= ATTACK_DISTANCE)
	{
		_isAnimated = true;
	}

	if (_state == eIdState::WAIT_01)
	{
		if (_curAnimation.getLoopCount() > 0)
		{
			this->fixPosBottom(eIdState::PREPARE);
			this->setState(eIdState::PREPARE);
		}
	}
	else if (_state == eIdState::PREPARE)
	{
		if (_curAnimation.getLoopCount() > 0)
		{
			this->fixPosBottom(eIdState::SELL);
			this->setState(eIdState::SELL);
		}
	}

	_curAnimation.setIsAnimated(_isAnimated);
	_curAnimation.setDrawingBound(false);
	_curAnimation.update(dt);
}

void Peddler::handlerInput(float)
{
}
