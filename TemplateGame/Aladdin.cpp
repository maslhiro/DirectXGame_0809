﻿#include "Aladdin.h"

Aladdin::Aladdin() : GameObject()
{
	_idType = eIdObject::ALADDIN;

	_pos = Vec3();
	_numApple = NUM_APPLE_DEFAULT;
	_grid = nullptr;
	_camera = nullptr;
	_isFlash = false;
	_numBlood = BLOOD_ALADDIN;
	_isClimb = 0;
	_isThrow = false;
	_isFall = false;
	_isOnGround = false;
	_isRunJump = false;
	_isDamage = false;
	_isClimbJump = false;
	_checkClimb = false;
	_canMoveRight = true;
	_canMoveLeft = true;
	_isAttack = false;
	_isJump = false;
	_idGroundObj = 0;
	_isSit = false;
	_distanceJump = 0.f;
	_moveDirection = 0;
	_indexApple = 0;
	_waitTime = 0.f;
	_flashTime = 0.f;
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

int Aladdin::getNumBlood()
{
	return _numBlood;
}

int Aladdin::getNumApple()
{
	return _numApple - _indexApple;
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

	_listAnimation[eIdState::FALL] = AnimationManager::getInstance()->get(eIdAnimation::ALADDIN_FALL);

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
	_curAnimation.setPosition(_posWorld);
	_curAnimation.setScale(_scale);
	_curAnimation.setIsFlash(_isFlash);
	/*RECT rr = getCurrentBoudingBox();
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
	);*/


	//_curAnimation.setDrawingBound(true);
	_curAnimation.setIsFlip(_isFlip);
	_curAnimation.render(_device, _texture);


	if (_indexApple != 0)
	{
		for (int i = 0; i < _listApple.size(); i++)
		{
			_listApple[i]->render();

		}
	}
}

void Aladdin::update(float dt)
{
	//_RPT1(0, "STATE %d \n", _state);

	RECT _viewPort = _camera->getBounding();
	// Get list obj nam trong view port
	auto listObj = _grid->getListGameObjContain(_viewPort);

	if (_indexApple != 0)
	{
		if (_indexApple != 0)
		{
			for (int i = 0; i < _listApple.size(); i++)
			{
				_listApple[i]->setListGameObj(listObj);
				_listApple[i]->update(dt);
			}
			//_RPT0(0, "[UPDATE APPLE]\n");
		}

	}

	if (_isFlash)
	{
		_flashTime += dt;

		if (_flashTime >= FLASH_TIME_ALADDIN)
		{
			_isFlash = false;
			_flashTime = 0.f;
		}
	}

	if ((_state & eIdState::DAMAGE) == eIdState::DAMAGE)
	{
		// Damage chi tu stand
		// damage cua cac animation khac opacity se dc giam xuong
		if ((_state & eIdState::STAND) == eIdState::STAND)
		{
			if (_curAnimation.getLoopCount() > 0)
			{
				this->fixPosAnimation(eIdState::STAND);
				this->setState(eIdState::STAND);
				_isFlash = false;
			}
		}
	}

	if ((_state & eIdState::JUMP) != eIdState::JUMP) {

		//_RPT1(0, "[STATE] %d \n", _state);
		for (size_t i = 0; i < listObj.size(); i++)
		{
			auto obj = listObj[i];
			if (obj->getIdType() != eIdObject::GROUND && obj->getIdType() != eIdObject::ROCK) continue;

			// Kiem tra va cham voi ground
			if (obj->getId() == _idGroundObj)
			{
				int di = 0;

				//int objID = obj->getId();
				float check = this->checkCollision_SweptAABB_(obj->getBoundingBox(), _gravity, dt, di);
				if (obj->getIdType() != eIdObject::ROCK)
				{
					//_RPT1(0, "[ID OBJ] %d - %d\n", _idGroundObj, di);
					// Neu va cham va dang dung tren obj 
					if (di != eDirection::BOTTOM)
					{
						this->setDy(_gravity);
						this->setDx(0.f);
						this->setState(eIdState::JUMP);
						_isFall = true;
						_curAnimation = _listAnimation[eIdState::FALL];
						//this->setIsAnimated(false);
					}
				}
				else
				{
					//_RPT1(0, "[ID OBJ] %d - %d\n", _idGroundObj, di);
					// Neu va cham va dang dung tren obj 
					if (di != eDirection::BOTTOM || obj->getCurrentFrame() < 4 || obj->getCurrentFrame() > 6)
					{
						this->setDy(_gravity);
						this->setDx(0.f);
						this->setState(eIdState::JUMP);
						_isFall = true;
						_curAnimation = _listAnimation[eIdState::FALL];
						//this->setIsAnimated(false);
					}
				}
			}
		}
	}
	if ((_state & eIdState::JUMP) == eIdState::JUMP)
	{
		float timeUpdate = dt;

		// Check Climb
		if (_checkClimb && (_state & eIdState::CLIMB) != eIdState::CLIMB)
		{
			for (size_t i = 0; i < listObj.size(); i++)
			{
				auto obj = listObj[i];
				if (obj->getIdType() == eIdObject::ROPE)
				{
					RECT ropeRECT = obj->getBoundingBox();

					RECT curRECT = getCurrentBoudingBox();

					bool check = checkCollision(ropeRECT);

					float ropeX = obj->getPosWorld().x;

					// Check them aladin co va cham vao tam cua rope ko
					if (check && curRECT.bottom <= ropeRECT.bottom && curRECT.top >= ropeRECT.top) {

						this->setPositionWorld(ropeX, _posWorld.y);
						this->setState(eIdState::CLIMB);
						_idRopeObj = obj->getId();
						_checkClimb = false;
						_isOnGround = false;
						_isJump = _isRunJump = _isClimbJump = _isFall = false;
						_distanceJump = 0.f;
						_dx = 0.f;
						_dy = 0.f;
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
			if (_curAnimation.getLoopCount() > 0)
			{
				_isOnGround = false;
				_isJump = _isRunJump = _isClimbJump = _isFall = false;
				_distanceJump = 0.f;
				_dx = 0.f;
				_dy = 0.f;
				this->fixPosAnimation(eIdState::STAND);
				_RPT1(0, "[CHECK Collision] POS WORLD FIX: %f %f \n", _posWorld.x, _posWorld.y);
				this->setState(eIdState::STAND);
			}
		}
		else {
			if (_dy < 0.f)
			{
				_idGroundObj = 0;
				//_RPT1(0, "[CHECK Collision] JUMP DISTANCE : %f \n", _jumpDistance);*/

				this->updateAllPos(Vec3(0, _dy*dt, 0));

				_distanceJump += abs(_dy * dt);

				// Den frame nay la phai roi xuong
				if ((_isJump &&  _curAnimation.getCurrentFrame() == 6) ||
					(_isRunJump && _curAnimation.getCurrentFrame() == 4) ||
					(_isClimbJump && _curAnimation.getCurrentFrame() == 9))
				{
					this->setIsAnimated(false);
				}

				if (_distanceJump > ALTITUDE_JUMP)
				{
					//_distanceJump = 0.f;
					this->setDy(_gravity);
				}
			}
			else if (_dy >= 0.f)
			{
				//_RPT0(0, "==================================\n");

				if (_distanceJump < ALTITUDE_JUMP / 2 && !_isAnimated && !_isFall && !_isClimbJump)
				{
					this->setIsAnimated(true);
				}


				if (_isFall && _curAnimation.getCurrentFrame() == 5)
				{
					this->setIsAnimated(false);
				}

				for (size_t i = 0; i < listObj.size(); i++)
				{
					auto obj = listObj[i];

					// Va cham voi ground
					if (obj->getIdType() == eIdObject::GROUND || obj->getIdType() == eIdObject::ROCK)
					{
						int direction = 0;

						float check = this->checkCollision_SweptAABB_(obj->getBoundingBox(), _dy, timeUpdate, direction);

						//float check = this->checkCollision(obj->getBoundingBox());

						//RECT t = obj->getBoundingBox();
						//RECT t1 = getBoundingBox();

						if (check < timeUpdate && direction == eDirection::BOTTOM)
						{
							//_RPT1(0, "[AAAAAAAAAAA] VX : %f || VY  %f\n", _dx, _dy);

							//if (direction != eDirection::TOP) goto updatePos;

							//_RPT1(0, "[AAAAAAAAAAA] CURRENT FRAME : %d \n", _curAnimation.getCurrentFrame());
							//_RPT1(0, "[AAAAAAAAAAA] OTHER : %d %d %d %d \n", t.left, t.top, t.right, t.bottom);
							//_RPT1(0, "[AAAAAAAAAAA] POS WORLD : %f %f \n", _posWorld.x, _posWorld.y);
							//if (obj->getIdType() == eIdObject::ROCK) {
							_RPT1(0, "[CHECK JUMP COLLISION] id :%d -  %d \n", obj->getId(), direction);
							//}
							_idGroundObj = obj->getId();
							timeUpdate = check;
							_isOnGround = true;
							this->setIsAnimated(true);
						}
					}

				}

			updatePos:

				this->updateAllPos(Vec3(0, _dy*timeUpdate, 0));
				_distanceJump -= abs(_dy * timeUpdate);
			}
		}
	}

	if ((_state & eIdState::STAND) == eIdState::STAND)
	{
		// Kiem tra co dang dung tren ground
	}

	if ((_state & eIdState::ATTACK) == eIdState::ATTACK)
	{
		//_RPT0(0, "ATTACK \n");
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
		}
	}
	else if ((_state & eIdState::THROW) == eIdState::THROW)
	{
		if (_indexApple > _listApple.size() && _indexApple < _numApple)
		{
			pAppleThrow _apple = new AppleThrow();
			_apple->loadResource();
			_apple->setScale(2.0f);

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
			if (_state == eIdState::RUN)
			{
				this->fixPosAnimation(eIdState::STAND);
				this->setState(eIdState::STAND);
			}
			else
			{
				_state &= ~eIdState::RUN;
			}
		}
		// Move Left
		else
		{
			float timeUpdate = dt;

			if (_moveDirection != 0)
			{
				if (_moveDirection == -1 && _canMoveLeft) {
					_isFlip = true;
					this->setDx(-_speed);
				}
				// Move right
				else if (_moveDirection == 1 && _canMoveRight)
				{
					_isFlip = false;
					this->setDx(_speed);
				}

				for (size_t i = 0; i < listObj.size(); i++)
				{
					auto obj = listObj[i];

					if (obj->getIdType() == eIdObject::COLUMN)
					{
						if (obj->getIdType() != eIdObject::COLUMN) continue;

						int direction = 0;

						float check = this->checkCollision_SweptAABB_(obj->getBoundingBox(), 0.f, timeUpdate, direction);

						//_RPT1(0, "[CHECK RUN COLLISION] ID :%d -  %d  \n", obj->getId(), direction);

						if (check < timeUpdate && (direction == eDirection::RIGHT || direction == eDirection::LEFT))
						{
							timeUpdate = check;
							if (_dx > 0.f)
							{
								_canMoveRight = false;
								//_cantMoveRight = false;
							}
							if (_dx < 0.f) {
								_canMoveLeft = false;
								//_cantMoveRight = true;
							}
							goto updatePosRun;
						}
						else
						{
							_canMoveRight = true;
							_canMoveLeft = true;
						}
					}
				}

			}


			//_RPT0(0, "========================\n");
			//_RPT1(0, "Bool cantMove : L:%d R: %d \n", _canMoveLeft, _canMoveRight);
			//_RPT1(0, "DT : %f\n", timeUpdate);

		updatePosRun:
			this->updateAllPos(Vec3(_dx * timeUpdate, 0, 0));

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

	if ((_state & eIdState::CLIMB) == eIdState::CLIMB)
	{
		if (_isClimb != 0)
		{
			for (size_t i = 0; i < listObj.size(); i++)
			{
				auto obj = listObj[i];
				if (obj->getId() == _idRopeObj)
				{
					RECT ropeRECT = obj->getBoundingBox();

					RECT curRECT = getCurrentBoudingBox();

					bool check = checkCollision(ropeRECT);

					float ropeX = obj->getPosWorld().x;

					// Check them aladin co va cham vao tam cua rope ko
					if (check && curRECT.bottom <= ropeRECT.bottom && curRECT.top >= ropeRECT.top) {
						this->updateAllPos(Vec3(0, _speed *_isClimb * 2. / 3. * dt, 0));
					}
					else if (check && curRECT.top <= ropeRECT.top && _isClimb < 0)
					{
						// neu leo len dung top cua rope
					}
					else
					{
						// chan ra khoi rope
						this->setDy(_gravity);
						this->setDx(0.f);
						this->setState(eIdState::JUMP);
						_idRopeObj = 0;
						_isFall = true;
						_curAnimation = _listAnimation[eIdState::FALL];

					}
				}
			}
		}
	}

	for (size_t i = 0; i < listObj.size(); i++)
	{
		auto obj = listObj[i];

		if (obj->getIsTerminated()) continue;

		// Kiem tra va cham voi apple
		if (obj->getIdType() == eIdObject::APPLE || obj->getIdType() == eIdObject::GENIE_HEAD)
		{
			//int objID = obj->getId();
			//_RPT1(0, "[ID OBJ] %d \n", objID);
			float check = this->checkCollision(obj->getCurrentBoudingBox());
			if (check) {
				if (obj->getState() != eIdState::EXPLODE)
				{
					obj->setState(eIdState::EXPLODE);
					if (obj->getIdType() == eIdObject::APPLE) _numApple += 1;
					//obj->setIsTerminated(true);
				}
			}
		}
		else if (obj->getIdType() == eIdObject::WRECKING_BALL || obj->getIdType() == eIdObject::SPIKE)
		{
			//int objID = obj->getId();
			//_RPT1(0, "[ID OBJ] %d \n", objID);
			bool check = this->checkCollision(obj->getCurrentBoudingBox());

			if (
				check &&
				(
				(obj->getCurrentFrame() <= 14 && obj->getCurrentFrame() >= 12 && obj->getIdType() == eIdObject::WRECKING_BALL) ||
					(obj->getCurrentFrame() <= 6 && obj->getCurrentFrame() >= 4 && obj->getIdType() == eIdObject::SPIKE))
				&& ((_state & eIdState::DAMAGE) != eIdState::DAMAGE) && !_isFlash)
			{
				_numBlood -= DAMAGE_ENERMY;

				if (_state == eIdState::STAND)
				{

					this->fixPosAnimation(eIdState::DAMAGE);
					_curAnimation = _listAnimation[eIdState::DAMAGE];
					_state |= eIdState::DAMAGE;
					_isFlash = false;
				}
				else
				{
					_isFlash = true;
				}
			}
		}
		else if (obj->getIdType() == eIdObject::NAHBI)
		{
			pNahbi na = dynamic_cast<pNahbi>(obj);

			na->setPosXPlayer(_posWorld.x);

			bool check = this->checkCollision(obj->getCurrentBoudingBox());

			if (check && (_state & eIdState::ATTACK) == eIdState::ATTACK && _isAttack)
			{
				_isAttack = false;
				na->getDamaged(ATTACK_DAMAGE_ALADDIN);
			}
			else if (check && !_isFlash && ((_state & eIdState::ATTACK) != eIdState::ATTACK) && ((_state & eIdState::DAMAGE) != eIdState::DAMAGE))
			{
				_RPT0(0, "GET DAM NAHBI\n");
				_numBlood -= DAMAGE_ENERMY;

				if (_state == eIdState::STAND)
				{

					this->fixPosAnimation(eIdState::DAMAGE);
					_curAnimation = _listAnimation[eIdState::DAMAGE];
					_state |= eIdState::DAMAGE;
					_isFlash = false;
				}
				else
				{
					_isFlash = true;
				}
			}

		}
		else if (obj->getIdType() == eIdObject::FAZAL)
		{
			pFazal fa = dynamic_cast<pFazal>(obj);

			fa->setPosXPlayer(_posWorld.x);

			bool check = this->checkCollision(obj->getCurrentBoudingBox());

			if (check && _isAttack && (_state & eIdState::ATTACK) == eIdState::ATTACK)
			{
				_isAttack = false;
				fa->getDamaged(ATTACK_DAMAGE_ALADDIN);
			}
			else if (check && !_isFlash && ((_state & eIdState::ATTACK) != eIdState::ATTACK) && ((_state & eIdState::DAMAGE) != eIdState::DAMAGE))
			{
				_RPT0(0, "GET DAM FAZAL\n");
				_numBlood -= DAMAGE_ENERMY;
				if (_state == eIdState::STAND)
				{

					this->fixPosAnimation(eIdState::DAMAGE);
					_curAnimation = _listAnimation[eIdState::DAMAGE];
					_state |= eIdState::DAMAGE;
					_isFlash = false;
				}
				else
				{
					_isFlash = true;
				}
			}
		}
		else if (obj->getIdType() == eIdObject::BAT && obj->getState() != eIdState::EXPLODE)
		{
			pBat bat = dynamic_cast<pBat>(obj);

			bat->setPosXPlayer(_posWorld);

			bool check = this->checkCollision(obj->getCurrentBoudingBox());

			if (check && (_state & eIdState::ATTACK) == eIdState::ATTACK && _isAttack)
			{
				_isAttack = false;
				bat->setState(eIdState::EXPLODE);
			}
			else if (check && ((_state & eIdState::ATTACK) != eIdState::ATTACK) && ((_state & eIdState::DAMAGE) != eIdState::DAMAGE))
			{
				_numBlood -= DAMAGE_ENERMY;

				bat->setState(eIdState::EXPLODE);
				//_RPT0(0, "GET DAM\n");
				if (_state == eIdState::STAND)
				{

					this->fixPosAnimation(eIdState::DAMAGE);
					_curAnimation = _listAnimation[eIdState::DAMAGE];
					_state |= eIdState::DAMAGE;
					_isFlash = false;
				}
				else
				{
					_isFlash = true;
				}
			}
		}
		else if (obj->getIdType() == eIdObject::SKELETON)
		{
			pSkeleton ke = dynamic_cast<pSkeleton>(obj);
			ke->setListObj(listObj);
		}

	}

updateAni:
	_curAnimation.setIsAnimated(_isAnimated);

	_curAnimation.update(dt);

	_camera->setNextPositisonWorld(_posWorld);
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
		else if (_input->getMapKey()[KEY_D] && !_input->getMapKey()[KEY_A])
		{
			_moveDirection = 1;
			_waitTime = 0.f;
			_isFlip = false;
			this->fixPosAnimation(eIdState::RUN);
			this->setState(eIdState::RUN);

		}
		else if (_input->getMapKey()[KEY_J])
		{
			_waitTime = 0.f;
			_isRunJump = false;
			_isJump = true;
			_isClimbJump = false;
			this->setState(eIdState::JUMP);
			this->setDx(0.f);
			this->setDy(-_gravity);
		}
		else if (_input->getMapKey()[KEY_H]) {
			_waitTime = 0.f;
			this->fixPosAnimation(eIdState::ATTACK);
			this->setState(eIdState::ATTACK);
			_isAttack = true;

		}
		else if (_input->getMapKey()[KEY_S]) {
			_waitTime = 0.f;
			this->fixPosAnimation(eIdState::SIT);
			this->setState(eIdState::SIT);
		}
		else if (_input->getMapKey()[KEY_K]) {

			_waitTime = 0.f;
			_indexApple += 1;

			this->fixPosAnimation(eIdState::THROW);
			this->setState(eIdState::THROW);
			_RPT0(0, "[THROW]\n");
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
			if (_input->getMapKey()[KEY_H])
			{
				this->fixPosAnimation(eIdState::SIT | eIdState::ATTACK);
				_curAnimation = _listAnimation[eIdState::SIT | eIdState::ATTACK];
				_state |= eIdState::ATTACK;
				_isAttack = true;

			}
			else if (_input->getMapKey()[KEY_K])
			{
				if ((_state & eIdState::THROW) != eIdState::THROW)
				{
					this->fixPosAnimation(eIdState::SIT | eIdState::THROW);
					_curAnimation = _listAnimation[eIdState::SIT | eIdState::THROW];
					_state |= eIdState::THROW;

					_indexApple += 1;
				}
			}
		}
		else {
			_isSit = false;
		}
	}

	if ((_state & eIdState::CLIMB) == eIdState::CLIMB)
	{
		if (_input->getMapKey()[KEY_W]) {
			this->setIsAnimated(true);
			_isClimb = -1;
		}
		else if (_input->getMapKey()[KEY_S]) {
			this->setIsAnimated(true);
			_isClimb = 1;
		}
		else if (_input->getMapKey()[KEY_J]) {
			this->setIsAnimated(true);
			this->setState(eIdState::JUMP);

			_isClimb = 0;
			_idRopeObj = 0;
			_checkClimb = false;
			_isClimbJump = true;
			_isRunJump = false;
			_isJump = false;
			_isFall = false;
			_curAnimation = _listAnimation[eIdState::CLIMB | eIdState::JUMP];
			this->setDx(0.f);
			this->setDy(-_gravity);
		}
		else {
			_isClimb = 0;
			this->setIsAnimated(false);
		}
	}
	else if ((_state & eIdState::JUMP) == eIdState::JUMP)
	{

		if (_input->getMapKey()[KEY_W]) {
			_checkClimb = true;
		}
		else {
			_checkClimb = false;

			if (_input->getMapKey()[KEY_H] && (_state & eIdState::ATTACK) != eIdState::ATTACK)
			{
				_state |= eIdState::ATTACK;
				//this->setDy(10.f);
				_isAnimated = true;
				_curAnimation = _listAnimation[eIdState::JUMP | eIdState::ATTACK];
				_isAttack = true;

			}
			else if (_input->getMapKey()[KEY_K] && (_state & eIdState::THROW) != eIdState::THROW)
			{
				_isAnimated = true;
				_state |= eIdState::THROW;
				_curAnimation = _listAnimation[eIdState::JUMP | eIdState::THROW];

				_indexApple += 1;
			}

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
			else {
				//_state &= ~eIdState::RUN;
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
			if (_input->getMapKey()[KEY_J])
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
			if (_input->getMapKey()[KEY_J])
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

		if (_input->getMapKey()[KEY_H]) {
			this->fixPosAnimation(eIdState::RUN | eIdState::ATTACK);
			_state |= eIdState::ATTACK;
			_curAnimation = _listAnimation[eIdState::RUN | eIdState::ATTACK];
			_isAttack = true;
		}
	}
}

void Aladdin::updateAllPos(Vec3 val)
{
	_pos += val;
	_posWorld += val;
}
