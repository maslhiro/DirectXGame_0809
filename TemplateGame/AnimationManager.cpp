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
