#include "Aladin.h"

Aladin::Aladin() : GameObject()
{
	_idType = eIdObject::ALADIN;

	_pos = Vec3();

	_camera = nullptr;
	_grid = nullptr;
}

void Aladin::setPosView(Vec3 pos)
{
	_pos = pos;
}

void Aladin::setPosView(int x, int y)
{
	_pos = Vec3((float)x, (float)y, 0);
}

void Aladin::setCamera(pCamera cam)
{
	_camera = cam;
}

void Aladin::setGrid(pFixedGrid grid)
{
	_grid = grid;
}

void Aladin::loadResource()
{
	_listAnimation[eIdState::STANDING] = AnimationManager::getInstance()->get(eIdAnimation::ALADIN_STANDING);

	_listAnimation[eIdState::RUNNING] = AnimationManager::getInstance()->get(eIdAnimation::ALADIN_RUNNING);

	this->setState(eIdState::STANDING);
}

void Aladin::render()
{
	_curAnimation.setIsAnimated(_isAnimated);
	_curAnimation.setPosition(_pos);
	_curAnimation.setScale(_scale);
	_curAnimation.setIsFlip(_isFlip);
	_curAnimation.setDrawingBound(true);
	_curAnimation.render(_device, _texture);
}

void Aladin::update(float dt)
{
	_curAnimation.update(dt);
	if (_grid == nullptr || _camera == nullptr) return;

}

void Aladin::handlerInput(float dt)
{
	//auto _device = DeviceManager::getInstance();
	auto _input = InputHandler::getInstance();

	// Get list obj nam trong view port
	auto listUnit = _grid->getUnitsContain(getBoudingBox());

	for (int i = 0; i < listUnit.size(); i++)
	{
		auto listObj = listUnit[i].getListGameObj();
		if (listObj.size() == 0) continue;

		for (int j = 0; j < listObj.size(); j++)
		{
			// Kiem tra va cham voi apple
			auto obj = listObj[j];
			if (obj->getIdType() == eIdObject::APPLE)
			{
				float check = this->checkCollision(obj->getBoudingBox());
				if (check) obj->setIsTerminated(true);
			}
		}

	}

	// Xu ly phan di chuyen cua aladin
	switch (_state)
	{
	case eIdState::STANDING:
	{
		if (_input->getMapKey()[KEY_A] && !_input->getMapKey()[KEY_D]) {
			_isFlip = true;

			this->fixPosAnimation(eIdState::RUNNING);
			this->setState(eIdState::RUNNING);

		}
		else if (_input->getMapKey()[KEY_D] && !_input->getMapKey()[KEY_A])
		{
			_isFlip = false;

			this->fixPosAnimation(eIdState::RUNNING);
			this->setState(eIdState::RUNNING);

		}
	}break;
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

			// Di chuyen cam neu aladin
			if (_camera->getPositionWorld().x > _device->getWidthWindow() / 2)
			{
				if (_pos.x <= (_device->getWidthWindow() * 1 / 3))
				{
					// di chuyen camera qua phai va doi player qua trai
					_camera->setPositisonWorld(_camera->getPositionWorld() + Vec3(-DISTANCE_X, 0, 0));

					// posView giam 
					_pos += Vec3(DISTANCE_X, 0, 0);
				}
			}
			else
			{
				_camera->setPositionWorld_X(_device->getWidthWindow() / 2);
			}

		}
		else if (_input->getMapKey()[KEY_D] && !_input->getMapKey()[KEY_A])
		{
			_isFlip = false;

			this->setDx(_speed);

			this->updateAllPos(Vec3(_dx * dt, 0, 0));

			if (_camera->getPositionWorld().x < (_grid->getMapWidth() - _device->getWidthWindow() / 2))
			{
				// Aladin di qua nua man hinh
				if (_pos.x >= (_device->getWidthWindow() * 2 / 3))
				{
					// di chuyen camera qua phai va doi player qua trai
					_camera->setPositisonWorld(_camera->getPositionWorld() + Vec3(DISTANCE_X, 0, 0));

					// posView giam 
					_pos += Vec3(-DISTANCE_X, 0, 0);
				}
			}
			else
			{
				// Cham width thi cam ko di chuyen
				_camera->setPositionWorld_X(_grid->getMapWidth() - _device->getWidthWindow() / 4);
			}
		}
	}break;
	default:
		break;
	}



}

void Aladin::updateAllPos(Vec3 val)
{
	_pos += val;
	_posWorld += val;
}
