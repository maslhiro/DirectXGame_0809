#include "Aladin.h"

Aladin::Aladin() : GameObject()
{
	_idType = eIdObject::ALADIN;

	_pos = Vec3();

	_grid = nullptr;
	_camera = nullptr;

	_isOnGround = false;
}

void Aladin::setPosView(Vec3 pos)
{
	_pos = pos;
}

void Aladin::setPosView(int x, int y)
{
	_pos = Vec3((float)x, (float)y, 0);
}

Vec3 Aladin::getPosView()
{
	return _pos;
}

void Aladin::setGrid(pFixedGrid grid)
{
	_grid = grid;
}

void Aladin::setCamera(pCamera cam)
{
	_camera = cam;
}

void Aladin::loadResource()
{
	_listAnimation[eIdState::STANDING] = AnimationManager::getInstance()->get(eIdAnimation::ALADIN_STANDING);

	_listAnimation[eIdState::RUNNING] = AnimationManager::getInstance()->get(eIdAnimation::ALADIN_RUNNING);

	_listAnimation[eIdState::JUMPING] = AnimationManager::getInstance()->get(eIdAnimation::ALADIN_JUMPING);

	_listAnimation[eIdState::DAMAGE] = AnimationManager::getInstance()->get(eIdAnimation::ALADIN_DAMAGE);

	this->setState(eIdState::STANDING);
}

void Aladin::render()
{
	_curAnimation.setIsAnimated(_isAnimated);
	_curAnimation.setPosition(_posWorld);
	_curAnimation.setScale(_scale);
	//_curAnimation.setDrawingBound(true);
	_curAnimation.setIsFlip(_isFlip);
	_curAnimation.render(_device, _texture);
}

void Aladin::update(float dt)
{
	// Get list obj nam trong view port

	auto listObj = _grid->getListGameObjContain(getBoundingBox());

	// Va cham dung tao
	for (int i = 0; i < listObj.size(); i++)
	{
		auto obj = listObj[i];

		// Kiem tra va cham voi apple
		if (obj->getIdType() == eIdObject::APPLE)
		{
			//int objID = obj->getId();
			//_RPT1(0, "[ID OBJ] %d \n", objID);
			float check = this->checkCollision(obj->getBoundingBox());
			if (check) {
				if (obj->getState() != eIdState::EXPLODING)
				{
					obj->setState(eIdState::EXPLODING);
					//obj->setIsTerminated(true);
				}

			}
		}
	}

	switch (_state)
	{
	case eIdState::JUMPING:
	{
		// Qua frame thu 2 moi bat dau nhay len
		if (_curAnimation.getCurrentFrame() <= 2) break;

		if (_isOnGround)
		{
			RECT t1 = getBoundingBox();
			_RPT1(0, "[IS ON GROUND] RECT : %d %d %d %d \n", t1.left, t1.top, t1.right, t1.bottom);

			if (_curAnimation.getCurrentFrame() == 12)
			{
				_isOnGround = false;
				this->fixPosAnimation(eIdState::STANDING);
				_RPT1(0, "[CHECK Collision] POS WORLD FIX: %f %f \n", _posWorld.x, _posWorld.y);
				this->setState(eIdState::STANDING);
			}
			else break;
		}
		else {
			if (_dy < 0.f)
			{
				/*_jumpDistance += abs(_dy) * dt;
				_RPT1(0, "[CHECK Collision] JUMP DISTANCE : %f \n", _jumpDistance);*/
				this->updateAllPos(Vec3(0, _dy*dt, 0));

				// Den frame nay la phai roi xuong
				if (_curAnimation.getCurrentFrame() == 11) {
					this->setIsAnimated(false);
					this->setDy(_gravity);
				}
			}
			else if (_dy > 0.f)
			{
				this->updateAllPos(Vec3(0, _dy*dt, 0));

				for (int i = 0; i < listObj.size(); i++)
				{
					auto obj = listObj[i];

					// Va cham voi land
					if (obj->getIdType() == eIdObject::LAND)
					{
						//int objID = obj->getId();
/*						float check2 = this->checkCollision_SweptAABB(obj->getBoundingBox(), dt, 0.f, _dy);
						_RPT1(0, "[CHECK Collision] DELTA TIME : %f \n", dt);
						_RPT1(0, "[CHECK Collision] CHECK COLLISION : %f \n", check);*/
						float check = this->checkCollision(obj->getBoundingBox());

						RECT t = obj->getBoundingBox();
						RECT t1 = getBoundingBox();

						if (check)
						{
							//_RPT1(0, "[AAAAAAAAAAA] CURRENT FRAME : %d \n", _curAnimation.getCurrentFrame());
							//_RPT1(0, "[AAAAAAAAAAA] RECT : %d %d %d %d \n", t1.left, t1.top, t1.right, t1.bottom);
							//_RPT1(0, "[AAAAAAAAAAA] OTHER : %d %d %d %d \n", t.left, t.top, t.right, t.bottom);
							//_RPT1(0, "[AAAAAAAAAAA] POS WORLD : %f %f \n", _posWorld.x, _posWorld.y);
							_isOnGround = true;
							this->setIsAnimated(true);
						}
					}

				}
			}
		}
	}
	break;
	default:
		break;
	}

	_curAnimation.update(dt);

}

void Aladin::handlerInput(float dt)
{
	//auto _device = DeviceManager::getInstance();
	auto _input = InputHandler::getInstance();

	// Xu ly phan di chuyen cua aladin
	switch (_state)
	{
	case eIdState::STANDING:
	{
		if (_input->getMapKey()[KEY_A] && !_input->getMapKey()[KEY_D]) {
			_isFlip = true;

			this->fixPosAnimation(eIdState::RUNNING);
			this->setState(eIdState::RUNNING);

			if (!_camera->getIsReverse())
			{
				_camera->setIsReverse(true);
				_camera->setNextPositisonWorld(_camera->getPositionWorld().x - 300, _camera->getPositionWorld().y);
			}

		}
		else if (_input->getMapKey()[KEY_D] && !_input->getMapKey()[KEY_A])
		{
			_isFlip = false;

			if (_camera->getIsReverse() && _camera->getPositionWorld().x > 500)
			{
				_camera->setIsReverse(false);
				_camera->setNextPositisonWorld(_camera->getPositionWorld().x + 300, _camera->getPositionWorld().y);
			}

			this->fixPosAnimation(eIdState::RUNNING);
			this->setState(eIdState::RUNNING);

		}
		else if (_input->getMapKey()[KEY_W])
		{
			this->setState(eIdState::JUMPING);
			this->setDy(-_gravity);
		}
	}
	break;
	case eIdState::RUNNING:
	{
		// Ko co su kien tu A va D
		if (!_input->getMapKey()[KEY_A] && !_input->getMapKey()[KEY_D]) {
			this->fixPosAnimation(eIdState::STANDING);
			this->setState(eIdState::STANDING);
		}
		else if (_input->getMapKey()[KEY_A] && !_input->getMapKey()[KEY_D]) {
			_isFlip = true;

			this->setDx(-_speed);

			this->updateAllPos(Vec3(_dx * dt, 0, 0));
			_camera->setIsReverse(true);
			_camera->addNextPositisonWorld(Vec3(_dx * dt, 0, 0));

		}
		else if (_input->getMapKey()[KEY_D] && !_input->getMapKey()[KEY_A])
		{
			_isFlip = false;

			this->setDx(_speed);

			this->updateAllPos(Vec3(_dx * dt, 0, 0));
			_camera->setIsReverse(false);
			_camera->addNextPositisonWorld(Vec3(_dx * dt, 0, 0));


		}
	}break;
	case eIdState::JUMPING:
	{
		// test

	}
	break;
	default:
		break;
	}
}

void Aladin::updateAllPos(Vec3 val)
{
	_pos += val;
	_posWorld += val;
}
