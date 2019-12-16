#include "Skeleton.h"

Skeleton::Skeleton() : GameObject()
{
	_idType = eIdObject::SKELETON;
	_isTerminated = false;
	_isAnimated = false;
}

Skeleton::Skeleton(int id) : GameObject(id)
{
	_idType = eIdObject::SKELETON;
}

void Skeleton::setListObj(std::vector<pGameObject> list)
{
	_listObj = list;
}

void Skeleton::loadResource()
{
	_listAnimation[eIdState::NONE] = AnimationManager::getInstance()->get(eIdAnimation::SKELETON_VISIBLE);

	_listAnimation[eIdState::EXPLODE] = AnimationManager::getInstance()->get(eIdAnimation::ENERMY_EXPLODE);

	this->setState(eIdState::NONE);
}

void Skeleton::setPosPlayer(Vec3 val)
{
	posPlayer = val;
}

void Skeleton::render()
{
	if (_isTerminated) return;

	_curAnimation.setIsAnimated(_isAnimated);
	_curAnimation.setPosition(_posWorld);
	_curAnimation.setScale(_scale);

	_curAnimation.render(_device, _texture);

	if (_state == 99)
	{
		for (size_t i = 0; i < _listBone.size(); i++)
		{
			_listBone[i]->render();
		}
	}
}

void Skeleton::update(float dt)
{
	if (_isTerminated) return;

	if (abs(_posWorld.x - posPlayer.x) <= ATTACK_DISTANCE && abs(_posWorld.y - posPlayer.y) <= ATTACK_DISTANCE)
	{
		_isAnimated = true;
	}

	if (_state == eIdState::EXPLODE)
	{
		if (_curAnimation.getLoopCount() > 0) _isTerminated = true;
	}
	else if (_state == eIdState::NONE)
	{
		if (_curAnimation.getLoopCount() > 0)
		{
			this->setState(99);
			int i = -7;

			srand(time(NULL));
			while (i < 8)
			{
				pBone bone = new Bone();
				bone->setPositionWorld(_posWorld + Vec3(5 * i, 5 * i, 0));
				bone->setListObj(_listObj);

				bone->setDx(i == 0 ? 250 : i < 0 ? -270 : 270);

				int gravity = -30;

				int a = rand() % 50 + 1;

				if (i == 0) bone->setGravity(gravity * 10);
				else bone->setGravity(gravity * abs(i) * 2 + a - 20);

				//int gravity = rand() % 200 + 1;
				bone->loadResource();
				_listBone.push_back(bone);

				i += 1;
			}

		}
	}
	// Skeleton da no ? chi update bone
	else if (_state == 99)
	{
		for (size_t i = 0; i < _listBone.size(); i++)
		{
			_listBone[i]->update(dt);
		}
	}

	_curAnimation.update(dt);
}

void Skeleton::handlerInput(float)
{
}
