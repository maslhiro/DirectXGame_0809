#include "AnimationManager.h"

AnimationManager* AnimationManager::_instance = nullptr;

AnimationManager::AnimationManager()
{
}

void AnimationManager::load() {
	//Animation _tank;
	//_tank.setTimePerFrame(0.3f);
	//_tank.addSprite(eIdSprite::TANK_EXPLODING_01);
	//_tank.addSprite(eIdSprite::TANK_EXPLODING_02);
	//_tank.addSprite(eIdSprite::TANK_EXPLODING_03);

	//_listAnimation[eIdAnimation::TANK_EXPLODING] = _tank;

	//Animation _tank01;
	//_tank01.setTimePerFrame(0.1f);
	//_tank01.addSprite(eIdSprite::TANK_RUNNING_01);
	//_tank01.addSprite(eIdSprite::TANK_RUNNING_02);
	//_tank01.addSprite(eIdSprite::TANK_RUNNING_03);
	//_tank01.addSprite(eIdSprite::TANK_RUNNING_04);
	//_tank01.addSprite(eIdSprite::TANK_RUNNING_05);
	//_tank01.addSprite(eIdSprite::TANK_RUNNING_06);
	//_tank01.addSprite(eIdSprite::TANK_RUNNING_07);
	//_tank01.addSprite(eIdSprite::TANK_RUNNING_08);
	//_tank01.addSprite(eIdSprite::TANK_RUNNING_09);
	//_tank01.addSprite(eIdSprite::TANK_RUNNING_10);
	//_tank01.addSprite(eIdSprite::TANK_RUNNING_11);

	Animation _billy;
	_billy.setTimePerFrame(0.4f);
	//_billy.setIsLoop(false);
	//_billy.setIsReverse(true);
	//_billy.setDrawingBound(true);
	_billy.addSprite(eIdSprite::BILLY_STANDING_01);
	_billy.addSprite(eIdSprite::BILLY_STANDING_02);
	_billy.addSprite(eIdSprite::BILLY_STANDING_03);

	_listAnimation[eIdAnimation::BILLY_STANDING] = _billy;

	Animation _billy01;
	_billy01.setTimePerFrame(0.3f);
	_billy01.addSprite(eIdSprite::BILLY_PUNCHING_01);
	_billy01.addSprite(eIdSprite::BILLY_PUNCHING_02);
	_billy01.addSprite(eIdSprite::BILLY_PUNCHING_03);

	_listAnimation[eIdAnimation::BILLY_PUNCHING] = _billy01;
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
