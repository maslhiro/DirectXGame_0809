#include "Aladdin.h"

Aladdin::Aladdin() : GameObject()
{
	_idType = eIdObject::ALADDIN;

	_pos = Vec3();

	_grid = nullptr;
	_camera = nullptr;

	_isOnGround = false;
	_isRunJump = false;
	_isDamage = false;

	_moveDirection = 0;
	_waitTime = 0.f;
}

void Aladdin::setPosView(Vec3 pos)
{
	_pos = pos;
}

void Aladdin::setPosView(int x, int y)
{
	_pos = Vec3((float)x, (float)y, 0);
}

Vec3 Aladdin::getPosView()
{
	return _pos;
}

void Aladdin::setGrid(pFixedGrid grid)
{
	_grid = grid;
}

void Aladdin::setCamera(pCamera cam)
{
	_camera = cam;
}

void Aladdin::loadResource()
{

	_listAnimation[eIdState::WAIT_01] = AnimationManager::getInstance()->get(eIdAnimation::ALADDIN_IDLING_01);

	_listAnimation[eIdState::WAIT_02] = AnimationManager::getInstance()->get(eIdAnimation::ALADDIN_IDLING_02);

	_listAnimation[eIdState::STAND] = AnimationManager::getInstance()->get(eIdAnimation::ALADDIN_STANDING);

	_listAnimation[eIdState::RUN] = AnimationManager::getInstance()->get(eIdAnimation::ALADDIN_RUNNING);

	_listAnimation[eIdState::JUMP] = AnimationManager::getInstance()->get(eIdAnimation::ALADDIN_JUMPING);

	_listAnimation[eIdState::RUN || eIdState::JUMP] = AnimationManager::getInstance()->get(eIdAnimation::ALADDING_RUN_JUMP);

	_listAnimation[eIdState::DAMAGE] = AnimationManager::getInstance()->get(eIdAnimation::ALADDIN_DAMAGE);

	this->setState(eIdState::STAND);
}

void Aladdin::render()
{
	_curAnimation.setIsAnimated(_isAnimated);
	_curAnimation.setPosition(_posWorld);
	_curAnimation.setScale(_scale);
	//_curAnimation.setDrawingBound(true);
	_curAnimation.setIsFlip(_isFlip);
	_curAnimation.render(_device, _texture);
}

void Aladdin::update(float dt)
{
	// Get list obj nam trong view port
	auto listObj = _grid->getListGameObjContain(getBoundingBox());

	if ((_state & eIdState::STAND) == eIdState::STAND)
	{
		// Kiem tra co dang dung tren ground
		for (size_t i = 0; i < listObj.size(); i++)
		{
			auto obj = listObj[i];

			// Kiem tra va cham voi ground
			//if (obj->getIdType() == eIdObject::GROUND)
			//{
			//	//int objID = obj->getId();
			//	//_RPT1(0, "[ID OBJ] %d \n", objID);
			//	float check = this->checkCollision(obj->getBoundingBox());
			//	if (!check) {
			//		this->setDy(_gravity);
			//		this->setState(eIdState::JUMP);
			//	}
			//}

			// Kiem tra co dang dung tren rock ko
			//if (obj->getIdType() == eIdObject::ROCK)
			//{
			//	//int objID = obj->getId();
			//	//_RPT1(0, "[ID OBJ] %d \n", objID);
			//	int direction = 0;
			//	float check = this->checkCollision(obj->getCurrentBoudingBox());
			//	if (!check) {
			//		this->setDy(_gravity);
			//		this->setState(eIdState::JUMP);
			//	}
			//}
		}
	}

	if ((_state & eIdState::RUN) == eIdState::RUN)
	{
		// Ko co su kien tu A va D
		if (_moveDirection == 0) {
			this->setDx(0.f);
			this->fixPosAnimation(eIdState::STAND);
			this->setState(eIdState::STAND);
		}
		// Move Left
		else if (_moveDirection == -1) {
			_isFlip = true;

			this->setDx(-_speed);

			this->updateAllPos(Vec3(_dx * dt, 0, 0));

			if (_posWorld.x >= _device->getWidthWindow() *2.0 / 3.0)
			{
				_camera->addNextPositisonWorld(Vec3(_dx * dt, 0, 0));
			}
		}
		// Move right
		else if (_moveDirection == 1)
		{
			_isFlip = false;

			this->setDx(_speed);

			this->updateAllPos(Vec3(_dx * dt, 0, 0));

			if (_posWorld.x >= _device->getWidthWindow() *2.0 / 3.0)
			{
				_camera->addNextPositisonWorld(Vec3(_dx * dt, 0, 0));
			}
		}
	}

	if ((_state & eIdState::JUMP) == eIdState::JUMP)
	{

		if (!_isRunJump)
		{
			// Qua frame thu 2 moi bat dau nhay len
			if (_curAnimation.getCurrentFrame() <= 2) goto updateAni;
		}

		if (_isOnGround)
		{
			//RECT t1 = getBoundingBox();
			//_RPT1(0, "[IS ON GROUND] RECT : %d %d %d %d \n", t1.left, t1.top, t1.right, t1.bottom);

			if ((!_isRunJump && _curAnimation.getCurrentFrame() == 12) || (_isRunJump && _curAnimation.getLoopCount() > 0))
			{
				_isOnGround = false;
				this->fixPosAnimation(eIdState::STAND);
				_RPT1(0, "[CHECK Collision] POS WORLD FIX: %f %f \n", _posWorld.x, _posWorld.y);
				this->setState(eIdState::STAND);
			}
		}
		else {
			if (_dy < 0.f)
			{
				/*_jumpDistance += abs(_dy) * dt;
				_RPT1(0, "[CHECK Collision] JUMP DISTANCE : %f \n", _jumpDistance);*/
				this->updateAllPos(Vec3(0, _dy*dt, 0));

				// Den frame nay la phai roi xuong
				if ((!_isRunJump && _curAnimation.getCurrentFrame() == 10) || (_isRunJump && _curAnimation.getCurrentFrame() == 3))
				{
					if (!_isRunJump) this->setIsAnimated(false);
					this->setDy(_gravity);
				}
			}
			else if (_dy > 0.f)
			{
				float timeUpdate = dt;

				for (size_t i = 0; i < listObj.size(); i++)
				{
					auto obj = listObj[i];

					// Va cham voi land
					if (obj->getIdType() == eIdObject::GROUND || obj->getIdType() == eIdObject::ROCK)
					{
						int direction = 0;

						float check2 = this->checkCollision_SweptAABB(obj->getCurrentBoudingBox(), timeUpdate, _dx, _dy, direction);

						//if (obj->getIdType() == eIdObject::ROCK) {
						//_RPT1(0, "[CHECK Collision] CHECK COLLISION : %d \n", direction);
						//}
						//float check = this->checkCollision(obj->getBoundingBox());

						//RECT t = obj->getBoundingBox();
						//RECT t1 = getBoundingBox();

						if (check2 < timeUpdate)
						{
							if (obj->getIdType() == eIdObject::ROCK) {
								if (direction != eDirection::TOP) break;
							}
							//_RPT1(0, "[AAAAAAAAAAA] CURRENT FRAME : %d \n", _curAnimation.getCurrentFrame());
							//_RPT1(0, "[AAAAAAAAAAA] RECT : %d %d %d %d \n", t1.left, t1.top, t1.right, t1.bottom);
							//_RPT1(0, "[AAAAAAAAAAA] OTHER : %d %d %d %d \n", t.left, t.top, t.right, t.bottom);
							//_RPT1(0, "[AAAAAAAAAAA] POS WORLD : %f %f \n", _posWorld.x, _posWorld.y);
							timeUpdate = check2;

							_isOnGround = true;
							this->setIsAnimated(true);
						}
					}

				}

				this->updateAllPos(Vec3(0, _dy*timeUpdate, 0));
			}

		}

	}

updateAni:	_curAnimation.update(dt);
	//if (_state == eIdState::WAIT_01) _RPT1(0, "[STATE UPDATE] %d \n", _isAnimated);

	// Va chạm với apple va ball
	for (size_t i = 0; i < listObj.size(); i++)
	{
		auto obj = listObj[i];

		// Kiem tra va cham voi apple
		if (obj->getIdType() == eIdObject::APPLE)
		{
			//int objID = obj->getId();
			//_RPT1(0, "[ID OBJ] %d \n", objID);
			float check = this->checkCollision(obj->getCurrentBoudingBox());
			if (check) {
				if (obj->getState() != eIdState::EXPLODE)
				{
					obj->setState(eIdState::EXPLODE);
					//obj->setIsTerminated(true);
				}
			}
		}

		if (obj->getIdType() == eIdObject::WRECKING_BALL)
		{
			//int objID = obj->getId();
			//_RPT1(0, "[ID OBJ] %d \n", objID);
			float check = this->checkCollision(obj->getCurrentBoudingBox());
			if (
				check &&
				(obj->getCurrentFrame() <= 14 && obj->getCurrentFrame() >= 12) &&
				(_state & eIdState::DAMAGE) != eIdState::DAMAGE
				)
			{
				//_curAnimation = _listAnimation[eIdState::DAMAGE];
				//this->fixPosAnimation(eIdState::DAMAGE);
				//_state |= eIdState::DAMAGE;
				//obj->setIsTerminated(true);
			}
			else {
				//if ((_state & eIdState::DAMAGE) == eIdState::DAMAGE) _curAnimation = _listAnimation[_state & ~eIdState::DAMAGE];
				//_state &= ~eIdState::DAMAGE;
			}
		}
	}

}

void Aladdin::handlerInput(float dt)
{
	//auto _device = DeviceManager::getInstance();
	auto _input = InputHandler::getInstance();

	if (_waitTime >= WAIT_TIME_ALADDIN && (_state & eIdState::WAIT_01) != eIdState::WAIT_01)
	{
		this->setIsAnimated(true);
		this->fixPosAnimation(eIdState::WAIT_01);

		_curAnimation = _listAnimation[eIdState::WAIT_01];
		_state = eIdState::WAIT_01 | eIdState::STAND;
	}

	if ((_state & eIdState::WAIT_01) == eIdState::WAIT_01)
	{
		if (_curAnimation.getLoopCount() == 4)
		{
			this->fixPosAnimation(eIdState::WAIT_02);
			_curAnimation = _listAnimation[eIdState::WAIT_02];
		}
	}

	if ((_state & eIdState::STAND) == eIdState::STAND)
	{
		// A
		if (_input->getMapKey()[KEY_A] && !_input->getMapKey()[KEY_D]) {

			_moveDirection = -1;
			_waitTime = 0.f;
			_isFlip = true;
			this->fixPosAnimation(eIdState::RUN);
			this->setState(eIdState::RUN);

		}
		// D
		else if (_input->getMapKey()[KEY_D] && !_input->getMapKey()[KEY_A])
		{
			_moveDirection = 1;
			_waitTime = 0.f;
			_isFlip = false;
			this->fixPosAnimation(eIdState::RUN);
			this->setState(eIdState::RUN);

		}
		// W
		else if (_input->getMapKey()[KEY_W])
		{
			_waitTime = 0.f;
			_isRunJump = false;
			this->setState(eIdState::JUMP);
			this->setDy(-_gravity);
		}
		//else if (_input->getMapKey()[KEY_Q]) {
			// Test
			//this->fixPosAnimation(eIdState::WAIT_01);
			//this->setState(eIdState::WAIT_01);
		//}

		// Khong co su kien phim nao 
		// Update waitTime
		else {
			_waitTime += dt;
			//_RPT1(0, "[WAIT_01 TIME] %f \n", _waitTime);
		}
	}

	if ((_state & eIdState::JUMP) == eIdState::JUMP)
	{

		if (_input->getMapKey()[KEY_A] && !_input->getMapKey()[KEY_D]) {
			_state |= eIdState::RUN;
			_moveDirection = -1;
		}
		else if (_input->getMapKey()[KEY_D] && !_input->getMapKey()[KEY_A])
		{
			_state |= eIdState::RUN;
			_moveDirection = 1;
		}
		// Ko co su kien tu A va D
		else if (!_input->getMapKey()[KEY_A] && !_input->getMapKey()[KEY_D]) {
			_state &= ~eIdState::RUN;
			_moveDirection = 0;
		}
		// Vừa bấm A vừa D
		else if (_input->getMapKey()[KEY_A] && _input->getMapKey()[KEY_D]) {
			_state &= ~eIdState::RUN;
			_moveDirection = 0;
		}
	}
	else if ((_state & eIdState::RUN) == eIdState::RUN)
	{
		// Ko co su kien tu A va D
		if (!_input->getMapKey()[KEY_A] && !_input->getMapKey()[KEY_D]) {
			_moveDirection = 0;
		}
		// Vừa bấm A vừa D
		else if (_input->getMapKey()[KEY_A] && _input->getMapKey()[KEY_D]) {
			_moveDirection = 0;
		}
		// A
		else if (_input->getMapKey()[KEY_A] && !_input->getMapKey()[KEY_D]) {
			_moveDirection = -1;
			if (_input->getMapKey()[KEY_W])
			{
				_isRunJump = true;
				_state |= eIdState::JUMP;
				_curAnimation = _listAnimation[eIdState::RUN || eIdState::JUMP];
				this->setDy(-_gravity);
			}
		}
		// D
		else if (_input->getMapKey()[KEY_D] && !_input->getMapKey()[KEY_A])
		{
			_moveDirection = 1;
			if (_input->getMapKey()[KEY_W])
			{
				_isRunJump = true;
				_state |= eIdState::JUMP;
				_curAnimation = _listAnimation[eIdState::RUN || eIdState::JUMP];
				this->setDy(-_gravity);
				_RPT0(0, "[RUN JUMP]\n");
			}
		}
	}
}

void Aladdin::updateAllPos(Vec3 val)
{
	_pos += val;
	_posWorld += val;
}
