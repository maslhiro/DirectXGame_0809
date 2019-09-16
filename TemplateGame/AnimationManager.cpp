#include "AnimationManager.h"

AnimationManager* AnimationManager::_instance = nullptr;

AnimationManager::AnimationManager()
{
}

void AnimationManager::init() {
	this->_texture = Texture::getInstance();
	this->_sprite = Sprite::getInstance();
	this->_device = DeviceManager::getInstance();
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

int AnimationManager::draw(int id)
{
	//int idAnimation = id;

	//Animation _animation = this->get(id);

	//_animation.getListSprite();

	//_device->getSpriteHandler()->Draw(

	//)

	return 1;
}