#include "ScoreHud.h"

ScoreHud::ScoreHud() : GameObject()
{
	_posWorld = Vec3(460, 50, 0);
	_scale = Vec2(2.f, 2.f);
	_numScore = 0;
}

ScoreHud::~ScoreHud()
{
}

void ScoreHud::loadResource()
{
	_listAnimation[0] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_SCORE_00);
	_listAnimation[1] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_SCORE_01);
	_listAnimation[2] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_SCORE_02);
	_listAnimation[3] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_SCORE_03);
	_listAnimation[4] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_SCORE_04);
	_listAnimation[5] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_SCORE_05);
	_listAnimation[6] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_SCORE_06);
	_listAnimation[7] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_SCORE_07);
	_listAnimation[8] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_SCORE_08);
	_listAnimation[9] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_SCORE_09);
}

void ScoreHud::setNumScore(int val)
{
	if (_state == val) return;

	_state = val;
}



void ScoreHud::render()
{
	_listScore.clear();

	if (_numScore < _state) _numScore += 5;
	if (_numScore > _state) _numScore = _state;
	int num = _numScore;

	while (num)
	{
		int i = num % 10;

		Animation cha = _listAnimation[i];

		_listScore.push_back(cha);

		num = num / 10;
	}

	std::reverse(_listScore.begin(), _listScore.end());


	for (size_t i = 0; i < _listScore.size(); i++)
	{
		_listScore[i].setPosition(_posWorld + Vec3(40 * i, 0, 0));
		//_curAnimation.setDrawingBound(true);
		_listScore[i].setScale(_scale);
		_listScore[i].render(_device, _texture);
	}


}

void ScoreHud::reset()
{
	_numScore = 0;
	_state = 0;
}

void ScoreHud::update(float dt)
{
	_curAnimation.update(dt);
}
