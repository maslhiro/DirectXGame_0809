#include "StoneColumn_3.h"

StoneColumn_3::StoneColumn_3() :GameObject()
{
	_idType = eIdObject::STONE_COLUMN_3;
}

void StoneColumn_3::loadResource()
{
	_listAnimation[eIdState::NONE] = AnimationManager::getInstance()->get(eIdAnimation::STONE_COLUMN_03_VISIBLE);

	this->setState(eIdState::NONE);
}

void StoneColumn_3::render()
{
	_curAnimation.setPosition(_posWorld);
	_curAnimation.setScale(_scale);

	_curAnimation.render(_device, _texture);
}

void StoneColumn_3::update(float)
{
}

void StoneColumn_3::handlerInput(float)
{
}