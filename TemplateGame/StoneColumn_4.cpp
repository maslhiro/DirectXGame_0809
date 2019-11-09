#include "StoneColumn_4.h"

StoneColumn_4::StoneColumn_4() :GameObject()
{
	_idType = eIdObject::STONE_COLUMN_4;
}

void StoneColumn_4::loadResource()
{
	_listAnimation[eIdState::NONE] = AnimationManager::getInstance()->get(eIdAnimation::STONE_COLUMN_04_VISIBLE);

	this->setState(eIdState::NONE);
}

void StoneColumn_4::render()
{
	_curAnimation.setPosition(_posWorld);
	_curAnimation.setScale(_scale);

	_curAnimation.render(_device, _texture);
}

void StoneColumn_4::update(float)
{
}

void StoneColumn_4::handlerInput()
{
}