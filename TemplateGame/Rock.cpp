#include "Rock.h"

Rock::Rock() : GameObject()
{
	_idType = eIdObject::ROCK;
	_isTerminated = false;
	_waitTime = 0.f;
}

Rock::Rock(int id) : GameObject(id)
{
	_idType = eIdObject::ROCK;
}

void Rock::loadResource()
{
	_listAnimation[eIdState::NONE] = AnimationManager::getInstance()->get(eIdAnimation::ROCK_VISIBLE);

	this->setState(eIdState::NONE);
}

void Rock::render()
{
	_curAnimation.setPosition(_posWorld);
	_curAnimation.setScale(_scale);

	//RECT rr = getBoundingBox();
	//RECT ty;
	//ty.top = ty.left = 0;
	//ty.bottom = rr.bottom - rr.top;
	//ty.right = rr.right - rr.left;

	//float posXX = rr.right - _curAnimation.getWidth();

	//float posYY = rr.bottom - _curAnimation.getHeight();

	//_device->getSpriteHandler()->Draw(
	//	_texture->get(eIdTexture::BOX_GREEN_TEX),
	//	&ty,
	//	&Vec3(ty.right / 2, ty.bottom / 2, 0),
	//	&Vec3(posXX, posYY, 0),
	//	D3DCOLOR_XRGB(255, 255, 255)
	//);


	_curAnimation.render(_device, _texture);
}

void Rock::update(float dt)
{
	if (_curAnimation.getCurrentFrame() == 4)
	{
		_waitTime += dt;
		_isAnimated = false;
	}

	if (_waitTime > WAIT_TIME_ROCK)
	{
		//if (!_isAnimated) Sound::getInstance()->playNew(eIdSound::S_ROCK);
		_isAnimated = true;
		if (_curAnimation.getCurrentFrame() != 4) _waitTime = 0.f;
	}
	//_RPT1(0, "[WAIT TIME] %f\n", _waitTime);
	_curAnimation.setIsAnimated(_isAnimated);
	_curAnimation.update(dt);
}

void Rock::handlerInput(float)
{
}
