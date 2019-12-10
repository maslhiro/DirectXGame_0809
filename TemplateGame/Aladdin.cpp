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
	_isClimbJump = false;
	_checkClimb = false;
	_isJump = false;

	_isSit = false;
	_distanceJump = 0.f;
	_moveDirection = 0;
	_indexApple = 0;
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

	_listAnimation[eIdState::WAIT_01] = AnimationManager::getInstance()->get(eIdAnimation::ALADDIN_IDLE_01);

	_listAnimation[eIdState::WAIT_02] = AnimationManager::getInstance()->get(eIdAnimation::ALADDIN_IDLE_02);

	_listAnimation[eIdState::STAND] = AnimationManager::getInstance()->get(eIdAnimation::ALADDIN_STAND);

	_listAnimation[eIdState::ATTACK] = AnimationManager::getInstance()->get(eIdAnimation::ALADDIN_ATTACK);

	_listAnimation[eIdState::THROW] = AnimationManager::getInstance()->get(eIdAnimation::ALADDIN_THROW);

	_listAnimation[eIdState::RUN] = AnimationManager::getInstance()->get(eIdAnimation::ALADDIN_RUN);

	_listAnimation[eIdState::RUN | eIdState::ATTACK] = AnimationManager::getInstance()->get(eIdAnimation::ALADDIN_RUN_ATTACK);

	_listAnimation[eIdState::JUMP] = AnimationManager::getInstance()->get(eIdAnimation::ALADDIN_JUMP);

	_listAnimation[eIdState::CLIMB] = AnimationManager::getInstance()->get(eIdAnimation::ALADDIN_CLIMB);

	_listAnimation[eIdState::CLIMB | eIdState::JUMP] = AnimationManager::getInstance()->get(eIdAnimation::ALADDIN_CLIMB_JUMP);

	_listAnimation[eIdState::JUMP | eIdState::ATTACK] = AnimationManager::getInstance()->get(eIdAnimation::ALADDIN_JUMP_ATTACK);

	_listAnimation[eIdState::JUMP | eIdState::THROW] = AnimationManager::getInstance()->get(eIdAnimation::ALADDIN_JUMP_THROW);

	_listAnimation[eIdState::SIT] = AnimationManager::getInstance()->get(eIdAnimation::ALADDIN_SIT);

	_listAnimation[eIdState::SIT_] = AnimationManager::getInstance()->get(eIdAnimation::ALADDIN_SIT_);

	_listAnimation[eIdState::SIT | eIdState::ATTACK] = AnimationManager::getInstance()->get(eIdAnimation::ALADDIN_SIT_ATTACK);

	_listAnimation[eIdState::SIT | eIdState::THROW] = AnimationManager::getInstance()->get(eIdAnimation::ALADDIN_SIT_THROW);

	_listAnimation[eIdState::RUN | eIdState::JUMP] = AnimationManager::getInstance()->get(eIdAnimation::ALADDIN_RUN_JUMP);

	_listAnimation[eIdState::DAMAGE] = AnimationManager::getInstance()->get(eIdAnimation::ALADDIN_DAMAGE);

	this->setState(eIdState::STAND);
}

void Aladdin::render()
{
	_curAnimation.setIsAnimated(_isAnimated);
	_curAnimation.setPosition(_posWorld);
	_curAnimation.setScale(_scale);

	RECT rr = getCurrentBoudingBox();
	RECT ty;
	ty.top = ty.left = 0;
	ty.bottom = rr.bottom - rr.top;
	ty.right = rr.right - rr.left;

	float posXX = rr.right - _curAnimation.getCurrentWidth();

	float posYY = rr.bottom - _curAnimation.getCurrentHeight();

	_device->getSpriteHandler()->Draw(
		_texture->get(eIdTexture::BOX_GREEN_TEX),
		&ty,
		&Vec3(ty.right / 2, ty.bottom / 2, 0),
		&Vec3(posXX, posYY, 0),
		D3DCOLOR_XRGB(255, 255, 255)
	);


	//_curAnimation.setDrawingBound(true);
	_curAnimation.setIsFlip(_isFlip);
	_curAnimation.render(_device, _texture);


	if (_indexApple != 0)
	{
		//_RPT0(0, "[UPDATE APPLE]\n");
		_listApple[_indexApple - 1]->render();
	}

	RECT _viewPort = _camera->getBounding();
	// Get list obj nam trong view port

	/*auto listObj = _grid->getListGameObjContain(_viewPort);
	for (size_t i = 0; i < listObj.size(); i++)
	{
		auto obj = listObj[i];
		if (obj->getIdType() == eIdObject::GROUND)
		{
			RECT bound;

			bound.left = 0;
			bound.right = obj->getBoundingBox().right - obj->getBoundingBox().left;
			bound.top = 0;
			bound.bottom = obj->getBoundingBox().bottom - obj->getBoundingBox().top;

			_device->getSpriteHandler()->Draw(_texture->get(eIdTexture::BOX_RED_TEX),
				&bound,
				&Vec3(bound.right / 2., bound.bottom / 2., 0),
				&Vec3(obj->getBoundingBox().right - (bound.right) / 2., obj->getBoundingBox().bottom - (bound.bottom / 2), 0.),
				D3DCOLOR_ARGB(255, 255, 255, 255));

		}
	}*/

}

void Aladdin::update(float dt)
{
	RECT _viewPort = _camera->getBounding();
	// Get list obj nam trong view port
	auto listObj = _grid->getListGameObjContain(getBoundingBox());
	auto listObj_Apple = _grid->getListGameObjContain(_viewPort);

	if (_indexApple != 0)
	{
		_listApple[_indexApple - 1]->setListGameObj(listObj_Apple);
		_listApple[_indexApple - 1]->update(dt);
	}

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

	if ((_state & eIdState::ATTACK) == eIdState::ATTACK)
	{
		this->setIsAnimated(true);
		if (_curAnimation.getLoopCount() > 0)
		{
			if (_state == eIdState::ATTACK)
			{
				this->fixPosAnimation(eIdState::STAND);
				this->setState(eIdState::STAND);
			}
			else if ((_state & (eIdState::JUMP)) == (eIdState::JUMP))
			{
				this->setDy(_gravity);
				_state &= ~eIdState::ATTACK;
			}
			else if ((_state & (eIdState::SIT)) == (eIdState::SIT))
			{
				this->fixPosAnimation(eIdState::SIT_);
				_curAnimation = _listAnimation[eIdState::SIT_];
				_state &= ~eIdState::ATTACK;
			}
			else if ((_state & (eIdState::RUN)) == (eIdState::RUN))
			{
				this->fixPosAnimation(eIdState::RUN);
				_curAnimation = _listAnimation[eIdState::RUN];
				_state &= ~eIdState::ATTACK;
			}
			/*else
			{
				int newState = _state & ~eIdState::ATTACK;
				this->fixPosAnimation(newState);
				_state &= ~eIdState::ATTACK;
				_curAnimation = _listAnimation[_state];
			}*/
		}
	}

	if ((_state & eIdState::THROW) == eIdState::THROW)
	{
		this->setIsAnimated(true);
		if (_curAnimation.getLoopCount() > 0)
		{
			if (_state == eIdState::THROW)
			{
				this->fixPosAnimation(eIdState::STAND);
				this->setState(eIdState::STAND);
			}
			else if ((_state & (eIdState::SIT)) == (eIdState::SIT))
			{
				this->fixPosAnimation(eIdState::SIT_);
				_curAnimation = _listAnimation[eIdState::SIT_];
				_state &= ~eIdState::THROW;
			}
			else if ((_state & (eIdState::JUMP)) == (eIdState::JUMP))
			{
				this->setDy(_gravity);
				_state &= ~eIdState::THROW;
			}
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

			if (_posWorld.x >= _device->getWidthWindow() / 2.)
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

			if (_posWorld.x >= _device->getWidthWindow() / 2.)
			{
				_camera->addNextPositisonWorld(Vec3(_dx * dt, 0, 0));
			}
		}
	}

	if ((_state & eIdState::SIT) == eIdState::SIT)
	{
		if (!_isSit)
		{
			this->fixPosAnimation(eIdState::STAND);
			this->setState(eIdState::STAND);
		}
	}

	if ((_state & eIdState::JUMP) == eIdState::JUMP)
	{
		// Check Climb
		if (_checkClimb)
		{
			for (size_t i = 0; i < listObj.size(); i++)
			{
				auto obj = listObj[i];
				if (obj->getIdType() == eIdObject::ROPE)
				{
					bool check = checkCollision(obj->getBoundingBox());

					float ropeX = obj->getPosWorld().x;

					if (check) {

						this->setPositionWorld(ropeX, _posWorld.y);
						this->setState(eIdState::CLIMB);
						this->setIsAnimated(false);
					}
				}
			}
		}

		if (_isJump)
		{
			// Qua frame thu 2 moi bat dau nhay len
			if (_curAnimation.getCurrentFrame() <= 2) goto updateAni;
		}

		if (_isOnGround)
		{
			//RECT t1 = getBoundingBox();
			//_RPT1(0, "[IS ON GROUND] RECT : %d %d %d %d \n", t1.left, t1.top, t1.right, t1.bottom);

			if (_curAnimation.getLoopCount() > 0)
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
				_distanceJump += abs(_dy * dt);
				if (_posWorld.y <= _camera->getMapHeight() - _device->getHeightWindow() / 2.)
				{
					_camera->addNextPositisonWorld(Vec3(0, _dy*dt, 0));
				}

				// Den frame nay la phai roi xuong
				if ((_isJump &&  _curAnimation.getCurrentFrame() == 6) ||
					(_isRunJump && _curAnimation.getCurrentFrame() == 4) ||
					(_isClimbJump && _curAnimation.getLoopCount() > 0))
				{
					//if (!_isRunJump) 
					this->setIsAnimated(false);
					//this->setDy(_gravity);
				}

				if (_distanceJump > 145.f)
				{
					_distanceJump = 0.f;
					this->setDy(_gravity);
				}
			}
			else if (_dy >= 0.f)
			{
				float timeUpdate = dt;
				//_RPT0(0, "==================================\n");
				//_RPT1(0, "[CHECK Collision] JUMP DISTANCE: %f \n", _dy);

				for (size_t i = 0; i < listObj.size(); i++)
				{
					auto obj = listObj[i];

					// Va cham voi ground
					if (obj->getIdType() == eIdObject::GROUND || obj->getIdType() == eIdObject::ROCK)
					{
						int direction = 0;

						float check2 = this->checkCollision_SweptAABB(obj->getBoundingBox(), timeUpdate, direction);

						//float check = this->checkCollision(obj->getBoundingBox());

						//RECT t = obj->getBoundingBox();
						//RECT t1 = getBoundingBox();

						if (check2 < timeUpdate)
						{
							_RPT1(0, "[AAAAAAAAAAA] VX : %f || VY  %f\n", _dx, _dy);

							//if (direction != eDirection::TOP) goto updatePos;

							//_RPT1(0, "[AAAAAAAAAAA] CURRENT FRAME : %d \n", _curAnimation.getCurrentFrame());
							//_RPT1(0, "[AAAAAAAAAAA] OTHER : %d %d %d %d \n", t.left, t.top, t.right, t.bottom);
							//_RPT1(0, "[AAAAAAAAAAA] POS WORLD : %f %f \n", _posWorld.x, _posWorld.y);
							//if (obj->getIdType() == eIdObject::ROCK) {
							_RPT1(0, "[CHECK Collision] CHECK COLLISION id :%d -  %d \n", obj->getId(), direction);
							//}

							timeUpdate = check2;

							_isOnGround = true;
							this->setIsAnimated(true);
						}
					}

				}
			updatePos:

				this->updateAllPos(Vec3(0, _dy*timeUpdate, 0));

				//if (_posWorld.y < (_camera->getMapHeight() - _device->getHeightWindow() / 2))
				{
					_camera->addNextPositisonWorld(Vec3(0, _dy*dt, 0));
				}

			}

		}

	}

updateAni:	_curAnimation.update(dt);

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

	if ((_state & eIdState::CLIMB) == eIdState::CLIMB)
	{
		// S
		if (_input->getMapKey()[KEY_W]) {
			this->setIsAnimated(true);
			this->updateAllPos(Vec3(0, -_speed * dt, 0));
		}
		else if (_input->getMapKey()[KEY_S]) {
			this->setIsAnimated(true);
			this->updateAllPos(Vec3(0, _speed*dt, 0));
		}
		else if (_input->getMapKey()[KEY_F]) {
			this->setIsAnimated(true);
			this->setState(eIdState::JUMP);
			_isClimbJump = true;
			_curAnimation = _listAnimation[eIdState::CLIMB | eIdState::JUMP];
			this->setDy(-_gravity);
		}
		else {
			this->setIsAnimated(false);
		}
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
		else if (_input->getMapKey()[KEY_D] && !_input->getMapKey()[KEY_A])
		{
			_moveDirection = 1;
			_waitTime = 0.f;
			_isFlip = false;
			this->fixPosAnimation(eIdState::RUN);
			this->setState(eIdState::RUN);

		}
		else if (_input->getMapKey()[KEY_W])
		{
			_waitTime = 0.f;
			_isRunJump = false;
			_isJump = true;
			_isClimbJump = false;
			this->setState(eIdState::JUMP);
			this->setDx(0.f);
			this->setDy(-_gravity);
		}
		else if (_input->getMapKey()[KEY_Q]) {
			_waitTime = 0.f;
			this->fixPosAnimation(eIdState::ATTACK);
			this->setState(eIdState::ATTACK);
		}
		else if (_input->getMapKey()[KEY_S]) {
			_waitTime = 0.f;
			this->fixPosAnimation(eIdState::SIT);
			this->setState(eIdState::SIT);
		}
		else if (_input->getMapKey()[KEY_E]) {
			_waitTime = 0.f;
			this->fixPosAnimation(eIdState::THROW);
			this->setState(eIdState::THROW);
			//_RPT0(0, "[THROW]\n");

			pAppleThrow _apple = new AppleThrow();
			_apple->loadResource();
			_apple->setScale(2.0f);

			_indexApple += 1;

			if (_isFlip)
			{
				_apple->setPositionWorld(_posWorld + Vec3(-20, -40, 0));

				_apple->moveLeft();
			}
			else {
				_apple->setPositionWorld(_posWorld + Vec3(20, -40, 0));
				_apple->moveRight();
			}
			_listApple.push_back(_apple);
		}

		// Khong co su kien phim nao 
		// Update waitTime
		else {
			_waitTime += dt;
			//_RPT1(0, "[WAIT_01 TIME] %f \n", _waitTime);
		}
	}

	if ((_state & eIdState::SIT) == eIdState::SIT)
	{
		// S
		if (_input->getMapKey()[KEY_S]) {

			_isSit = true;
			if (_input->getMapKey()[KEY_Q])
			{
				this->fixPosAnimation(eIdState::SIT | eIdState::ATTACK);
				_curAnimation = _listAnimation[eIdState::SIT | eIdState::ATTACK];
				_state |= eIdState::ATTACK;
			}
			else if (_input->getMapKey()[KEY_E])
			{
				this->fixPosAnimation(eIdState::SIT | eIdState::THROW);
				_curAnimation = _listAnimation[eIdState::SIT | eIdState::THROW];
				_state |= eIdState::THROW;

				pAppleThrow _apple = new AppleThrow();
				_apple->loadResource();
				_apple->setScale(2.0f);

				_indexApple += 1;

				if (_isFlip)
				{
					_apple->setPositionWorld(_posWorld + Vec3(-40, -30, 0));

					_apple->moveLeft();
				}
				else {
					_apple->setPositionWorld(_posWorld + Vec3(40, -30, 0));
					_apple->moveRight();
				}
				_listApple.push_back(_apple);
			}
		}
		else {
			_isSit = false;
		}
	}

	if ((_state & eIdState::JUMP) == eIdState::JUMP)
	{

		if (_input->getMapKey()[KEY_X]) {
			_checkClimb = true;
		}
		else {
			_checkClimb = false;

			if (_input->getMapKey()[KEY_Q]) {
				_state |= eIdState::ATTACK;
				//this->setDy(10.f);
				_curAnimation = _listAnimation[eIdState::JUMP | eIdState::ATTACK];
			}
			else if (_input->getMapKey()[KEY_E]) {
				_state |= eIdState::THROW;
				_curAnimation = _listAnimation[eIdState::JUMP | eIdState::THROW];

				pAppleThrow _apple = new AppleThrow();
				_apple->loadResource();
				_apple->setScale(2.0f);

				_indexApple += 1;

				if (_isFlip)
				{
					_apple->setPositionWorld(_posWorld + Vec3(-40, -40, 0));

					_apple->moveLeft();
				}
				else {
					_apple->setPositionWorld(_posWorld + Vec3(40, -40, 0));
					_apple->moveRight();
				}
				_listApple.push_back(_apple);
			}
			else if (_input->getMapKey()[KEY_A] && !_input->getMapKey()[KEY_D]) {
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
				_isJump = false;
				_isClimbJump = false;
				_state |= eIdState::JUMP;
				_curAnimation = _listAnimation[eIdState::RUN | eIdState::JUMP];
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
				_isJump = false;
				_isClimbJump = false;
				_state |= eIdState::JUMP;
				_curAnimation = _listAnimation[eIdState::RUN | eIdState::JUMP];
				this->setDy(-_gravity);
				_RPT0(0, "[RUN JUMP]\n");
			}
		}

		if (_input->getMapKey()[KEY_Q]) {
			this->fixPosAnimation(eIdState::RUN | eIdState::ATTACK);
			_state |= eIdState::ATTACK;
			_curAnimation = _listAnimation[eIdState::RUN | eIdState::ATTACK];
		}
	}
}

void Aladdin::updateAllPos(Vec3 val)
{
	_pos += val;
	_posWorld += val;
}
