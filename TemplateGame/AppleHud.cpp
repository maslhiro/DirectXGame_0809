#include "AppleHud.h"

AppleHud::AppleHud() : GameObject()
{
	_posWorld = Vec3(520, 460, 0);
	_scale = Vec2(2.f, 2.f);
	_numApple = NUM_APPLE_DEFAULT;
}

AppleHud::~AppleHud()
{
}

void AppleHud::loadResource()
{
	_listAnimation[99] = AnimationManager::getInstance()->get(eIdAnimation::APPLE_COLLECTION);

	_listAnimation[0] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_COLLECTION_00);
	_listAnimation[1] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_COLLECTION_01);
	_listAnimation[2] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_COLLECTION_02);
	_listAnimation[3] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_COLLECTION_03);
	_listAnimation[4] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_COLLECTION_04);
	_listAnimation[5] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_COLLECTION_05);
	_listAnimation[6] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_COLLECTION_06);
	_listAnimation[7] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_COLLECTION_07);
	_listAnimation[8] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_COLLECTION_08);
	_listAnimation[9] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_COLLECTION_09);

	this->setState(99);

	_cha01 = _listAnimation[_numApple / 10];
	_cha02 = _listAnimation[_numApple % 10];

}

void AppleHud::setNumApple(int val)
{
	if (val == _numApple) return;

	_numApple = val;
	if (val <= 0)
	{
		_cha01 = _listAnimation[0];
		_cha02 = _listAnimation[0];
	}
	else
	{
		_cha01 = _listAnimation[_numApple / 10];
		_cha02 = _listAnimation[_numApple % 10];
	}


}

void AppleHud::render()
{
	_curAnimation.setPosition(_posWorld);
	//_curAnimation.setDrawingBound(true);
	_curAnimation.setScale(_scale);
	_curAnimation.render(_device, _texture);

	_cha01.setPosition(_posWorld + Vec3(40, 0, 0));
	//_curAnimation.setDrawingBound(true);
	_cha01.setScale(_scale);
	_cha01.render(_device, _texture);

	_cha02.setPosition(_posWorld + Vec3(70, 0, 0));
	//_curAnimation.setDrawingBound(true);
	_cha02.setScale(_scale);
	_cha02.render(_device, _texture);


}

void AppleHud::update(float dt)
{
	_curAnimation.update(dt);
}
