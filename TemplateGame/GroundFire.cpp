#include "GroundFire.h"

GroundFire::GroundFire() :GameObject()
{
	_isStaticObj = true;
	posPlayer = Vec3();
	_scale = Vec2(2.f, 2.f);
	_idType = eIdObject::GROUND_FIRE;
}

void GroundFire::loadResource()
{
	_listAnimation[eIdState::NONE] = AnimationManager::getInstance()->get(eIdAnimation::GROUND_FIRE_VISIBLE);
	_curAnimation = _listAnimation[eIdState::NONE];
}

void GroundFire::setPosPlayer(Vec3 val)
{
	posPlayer = val;
}

void GroundFire::render()
{
	_curAnimation.setScale(_scale);
	_curAnimation.setPosition(_posWorld + Vec3(30, -50, 0));
	_curAnimation.render(_device, _texture);

}

void GroundFire::update(float dt)
{
	_curAnimation.update(dt);
}

void GroundFire::handlerInput(float)
{
}
