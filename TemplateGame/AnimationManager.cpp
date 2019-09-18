#include "AnimationManager.h"

AnimationManager* AnimationManager::_instance = nullptr;

AnimationManager::AnimationManager()
{
}

void AnimationManager::loadAnimation() {
	Animation _tank;
	_tank.setTimePerFrame(1.0f);
	_tank.addSprite(eIdSprite::TANK_EXPLODING_01);
	_tank.addSprite(eIdSprite::TANK_EXPLODING_02);
	_tank.addSprite(eIdSprite::TANK_EXPLODING_03);

	_listAnimation[eIdAnimation::TANK_EXPLODING] = _tank;

	Animation _tank01;
	_tank01.setTimePerFrame(0.1f);
	_tank01.addSprite(eIdSprite::TANK_RUNNING_01);
	_tank01.addSprite(eIdSprite::TANK_RUNNING_02);
	_tank01.addSprite(eIdSprite::TANK_RUNNING_03);
	_tank01.addSprite(eIdSprite::TANK_RUNNING_04);
	_tank01.addSprite(eIdSprite::TANK_RUNNING_05);
	_tank01.addSprite(eIdSprite::TANK_RUNNING_06);
	_tank01.addSprite(eIdSprite::TANK_RUNNING_07);
	_tank01.addSprite(eIdSprite::TANK_RUNNING_08);
	_tank01.addSprite(eIdSprite::TANK_RUNNING_09);
	_tank01.addSprite(eIdSprite::TANK_RUNNING_10);
	_tank01.addSprite(eIdSprite::TANK_RUNNING_11);

	_listAnimation[eIdAnimation::TANK_RUNNING] = _tank01;

}

pAnimationManager AnimationManager::getInstance() {
	if (_instance == nullptr) {
		_instance = new AnimationManager();
	}
	return _instance;
}

void AnimationManager::add(eIdAnimation id, Animation animation)
{
	this->_listAnimation[id] = animation;
}

Animation AnimationManager::get(int id)
{
	return this->_listAnimation[id];
}
