#include "JafarFlame.h"

JafarFlame::JafarFlame() : GameObject()
{
	_idType = eIdObject::JAFAR_FLAME;
	_isTerminated = false;
	_isAnimated = true;
	_scale = Vec2(2.f, 2.f);
	_speed = 250.f;
	_gravity = 50.f;
	_distance = 0.f;
	_waitTime = 0.f;
}

JafarFlame::JafarFlame(int id) : GameObject(id)
{
	_idType = eIdObject::JAFAR_FLAME;
}

void JafarFlame::loadResource()
{
	_listAnimation[eIdState::NONE] = AnimationManager::getInstance()->get(eIdAnimation::JAFAR_FLAME_THROW);

	this->setState(eIdState::NONE);
}

void JafarFlame::setDirection(bool val)
{
	_isFlip = val;
	_dx = val ? -_speed : _speed;
}

void JafarFlame::render()
{
	if (_isTerminated) return;

	_curAnimation.setPosition(_posWorld);
	_curAnimation.setScale(_scale);

	_curAnimation.render(_device, _texture);
}

void JafarFlame::update(float dt)
{
	if (_isTerminated) return;

	_waitTime += dt;
	if (_waitTime <= 0.7)
	{
		_posWorld.x += _dx / 2 * dt;
		_posWorld.y += _gravity * dt;;
	}
	else
	{
		_posWorld.x += _dx * dt;
		_distance += abs(_speed) * dt;
	}
	if (_distance > 550.)
	{
		_isTerminated = true;
	}

	_curAnimation.setIsAnimated(_isAnimated);
	_curAnimation.setIsFlip(_isFlip);
	_curAnimation.update(dt);

}

void JafarFlame::handlerInput(float)
{
}
