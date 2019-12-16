#include "Bone.h"

Bone::Bone() : GameObject()
{
	_idType = eIdObject::BAT;
	_isTerminated = false;
	_isAnimated = true;
	_scale = Vec2(2.f, 2.f);
	_gravity = 100.f;
}

Bone::Bone(int id) : GameObject(id)
{
	_idType = eIdObject::BONE;
}

void Bone::setListObj(std::vector<pGameObject> list)
{
	_listObj = list;
}

void Bone::loadResource()
{
	_listAnimation[eIdState::NONE] = AnimationManager::getInstance()->get(eIdAnimation::BONE_VISIBLE);

	_listAnimation[eIdState::EXPLODE] = AnimationManager::getInstance()->get(eIdAnimation::APPLE_THROW_EXPLODE);

	this->setState(eIdState::NONE);
}

void Bone::render()
{
	if (_isTerminated) return;

	_curAnimation.setPosition(_posWorld);
	_curAnimation.setScale(_scale);

	_curAnimation.render(_device, _texture);
}

void Bone::update(float dt)
{
	if (_isTerminated) return;


	if (_state == eIdState::EXPLODE)
	{
		if (_curAnimation.getLoopCount() > 0) {
			_isTerminated = true;
		}
	}
	else
	{
		_posWorld.x += _dx * dt;

		_posWorld.y += _gravity * dt;

		for (size_t i = 0; i < _listObj.size(); i++)
		{
			if (_listObj[i]->getIsTerminated()) continue;

			bool check = this->checkCollision(_listObj[i]->getBoundingBox());

			int id = _listObj[i]->getIdType();
			if (id == eIdObject::STONE_COLUMN_1
				|| id == eIdObject::STONE_COLUMN_2
				|| id == eIdObject::STONE_COLUMN_3
				|| id == eIdObject::STONE_COLUMN_4
				|| id == eIdObject::APPLE
				|| id == eIdObject::ROPE
				|| id == eIdObject::GENIE_HEAD) continue;
			if (check) {
				this->setState(eIdState::EXPLODE);
				goto updateAni;
			}
		}

	}

updateAni:
	_curAnimation.setIsAnimated(_isAnimated);
	_curAnimation.update(dt);

}

void Bone::handlerInput(float)
{
}
