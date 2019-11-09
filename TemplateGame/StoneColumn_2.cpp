#include "StoneColumn_2.h"

StoneColumn_2::StoneColumn_2() :GameObject()
{
	_idType = eIdObject::STONE_COLUMN_2;
}

void StoneColumn_2::loadResource()
{
	_listAnimation[eIdState::NONE] = AnimationManager::getInstance()->get(eIdAnimation::STONE_COLUMN_02_VISIBLE);

	this->setState(eIdState::NONE);
}

void StoneColumn_2::render()
{
	_curAnimation.setPosition(_posWorld);
	_curAnimation.setScale(_scale);

	_curAnimation.render(_device, _texture);
}

void StoneColumn_2::update(float)
{
}

void StoneColumn_2::handlerInput()
{
}