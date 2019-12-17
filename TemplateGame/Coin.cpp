#include "Coin.h"

Coin::Coin() : GameObject()
{
	_idType = eIdObject::COIN;
	_isTerminated = false;
}

Coin::Coin(int id) : GameObject(id)
{
	_idType = eIdObject::COIN;
}

void Coin::loadResource()
{
	_listAnimation[eIdState::NONE] = AnimationManager::getInstance()->get(eIdAnimation::COIN_VISIBLE);

	_listAnimation[eIdState::EXPLODE] = AnimationManager::getInstance()->get(eIdAnimation::ITEM_EXPLODE);

	this->setState(eIdState::NONE);
}

void Coin::render()
{
	if (_isTerminated) return;

	_curAnimation.setPosition(_posWorld);
	_curAnimation.setScale(_scale);

	_curAnimation.render(_device, _texture);
}

void Coin::update(float dt)
{
	_curAnimation.setIsAnimated(_isAnimated);

	if (_isTerminated) return;

	if (_state == eIdState::EXPLODE)
	{
		if (_curAnimation.getLoopCount() > 0) _isTerminated = true;
	}

	_curAnimation.update(dt);
}

void Coin::handlerInput(float)
{
}
