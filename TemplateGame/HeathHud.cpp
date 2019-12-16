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
	_listAnimation[80] = AnimationManager::getInstance()->get(eIdAnimation::HEALTH_01);
	_listAnimation[70] = AnimationManager::getInstance()->get(eIdAnimation::HEALTH_02);
	_listAnimation[60] = AnimationManager::getInstance()->get(eIdAnimation::HEALTH_03);
	_listAnimation[50] = AnimationManager::getInstance()->get(eIdAnimation::HEALTH_04);
	_listAnimation[40] = AnimationManager::getInstance()->get(eIdAnimation::HEALTH_05);
	_listAnimation[30] = AnimationManager::getInstance()->get(eIdAnimation::HEALTH_06);
	_listAnimation[20] = AnimationManager::getInstance()->get(eIdAnimation::HEALTH_07);
	_listAnimation[10] = AnimationManager::getInstance()->get(eIdAnimation::HEALTH_08);
	_listAnimation[0] = AnimationManager::getInstance()->get(eIdAnimation::HEALTH_09);

	this->setState(80);

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
		this->fixPosAnimation(val);
		this->setState(val);
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
