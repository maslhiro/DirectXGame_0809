#include "HeathHud.h"

HeathHud::HeathHud() : GameObject()
{
	_posWorld = Vec3(150, 50, 0);
	_scale = Vec2(2.f, 2.f);
}

HeathHud::~HeathHud()
{
}

void HeathHud::loadResource()
{
	_listAnimation[8] = AnimationManager::getInstance()->get(eIdAnimation::HEALTH_01);
	_listAnimation[7] = AnimationManager::getInstance()->get(eIdAnimation::HEALTH_02);
	_listAnimation[6] = AnimationManager::getInstance()->get(eIdAnimation::HEALTH_03);
	_listAnimation[5] = AnimationManager::getInstance()->get(eIdAnimation::HEALTH_04);
	_listAnimation[4] = AnimationManager::getInstance()->get(eIdAnimation::HEALTH_05);
	_listAnimation[3] = AnimationManager::getInstance()->get(eIdAnimation::HEALTH_06);
	_listAnimation[2] = AnimationManager::getInstance()->get(eIdAnimation::HEALTH_07);
	_listAnimation[1] = AnimationManager::getInstance()->get(eIdAnimation::HEALTH_08);
	_listAnimation[0] = AnimationManager::getInstance()->get(eIdAnimation::HEALTH_09);

	_state = 80;
	_curAnimation = _listAnimation[8];

}

void HeathHud::setHealth(int val)
{
	if (val == _state) return;

	if (val < 0)
	{
		this->fixPosAnimation(0);
		this->setState(0);
	}
	else {
		this->fixPosAnimation(val / 10);
		_state = val;
		_curAnimation = _listAnimation[val / 10];

	}
}

void HeathHud::render()
{
	_curAnimation.setPosition(_posWorld);
	//_curAnimation.setDrawingBound(true);
	_curAnimation.setScale(_scale);
	_curAnimation.render(_device, _texture);
}

void HeathHud::update(float dt)
{
	_curAnimation.update(dt);
}
