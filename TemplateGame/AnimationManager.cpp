#include "AnimationManager.h"

AnimationManager* AnimationManager::_instance = nullptr;

AnimationManager::AnimationManager()
{
}

void AnimationManager::load() {

#pragma region Apple

	Animation _apple;
	_apple.setTimePerFrame(1.0f);
	_apple.setIsLoop(false);
	//_apple.setIsReverse(true);
	//_apple.setDrawingBound(true);
	_apple.addSprite(eIdSprite::ITEM_APPLE);

	_listAnimation[eIdAnimation::APPLE_VISIBLE] = _apple;

#pragma endregion

#pragma region WreckingBall
	Animation _wreckingBall;
	_wreckingBall.setTimePerFrame(0.2f);
	_wreckingBall.setIsLoop(true);
	_wreckingBall.setTypeFixPos(2);
	_wreckingBall.setIsReverse(true);
	_wreckingBall.setScale(2.0f, 2.0f);
	_wreckingBall.addSprite(eIdSprite::WRECKING_BALL_01);
	_wreckingBall.addSprite(eIdSprite::WRECKING_BALL_02);
	_wreckingBall.addSprite(eIdSprite::WRECKING_BALL_03);
	_wreckingBall.addSprite(eIdSprite::WRECKING_BALL_04);
	_wreckingBall.addSprite(eIdSprite::WRECKING_BALL_05);
	_wreckingBall.addSprite(eIdSprite::WRECKING_BALL_06);
	_wreckingBall.addSprite(eIdSprite::WRECKING_BALL_07);
	_wreckingBall.addSprite(eIdSprite::WRECKING_BALL_08);
	_wreckingBall.addSprite(eIdSprite::WRECKING_BALL_09);
	_wreckingBall.addSprite(eIdSprite::WRECKING_BALL_10);
	_wreckingBall.addSprite(eIdSprite::WRECKING_BALL_11);
	_wreckingBall.addSprite(eIdSprite::WRECKING_BALL_12);
	_wreckingBall.addSprite(eIdSprite::WRECKING_BALL_13);
	_wreckingBall.addSprite(eIdSprite::WRECKING_BALL_14);
	_wreckingBall.addSprite(eIdSprite::WRECKING_BALL_15);

	_listAnimation[eIdAnimation::WRECKING_BALL_VISIBLE] = _wreckingBall;
#pragma endregion

#pragma region STONE COLUMN
	Animation _column01;
	_column01.setTimePerFrame(1.0f);
	_column01.setIsLoop(false);
	//_column01.setDrawingBound(true);
	_column01.addSprite(eIdSprite::STONE_COLUMN_01);

	_listAnimation[eIdAnimation::STONE_COLUMN_01_VISIBLE] = _column01;

	Animation _column02;
	_column02.setTimePerFrame(1.0f);
	_column02.setIsLoop(false);
	//_column02.setDrawingBound(true);
	_column02.addSprite(eIdSprite::STONE_COLUMN_02);

	_listAnimation[eIdAnimation::STONE_COLUMN_02_VISIBLE] = _column02;

	Animation _column03;
	_column03.setTimePerFrame(1.0f);
	_column03.setIsLoop(false);
	//_column03.setDrawingBound(true);
	_column03.addSprite(eIdSprite::STONE_COLUMN_03);

	_listAnimation[eIdAnimation::STONE_COLUMN_03_VISIBLE] = _column03;

	Animation _column04;
	_column04.setTimePerFrame(1.0f);
	_column04.setIsLoop(false);
	//_column04.setDrawingBound(true);
	_column04.addSprite(eIdSprite::STONE_COLUMN_04);

	_listAnimation[eIdAnimation::STONE_COLUMN_04_VISIBLE] = _column04;

#pragma endregion

#pragma region Aladin

	Animation _stand;
	_stand.setTimePerFrame(1.0f);
	_stand.setIsLoop(true);
	_stand.setTypeFixPos(1);
	_stand.setScale(2.0f, 2.0f);
	_stand.addSprite(eIdSprite::ALADIN_STAND);

	_listAnimation[eIdAnimation::ALADIN_STANDING] = _stand;


	Animation _idle;
	_idle.setTimePerFrame(0.15f);
	_idle.setIsLoop(true);
	_idle.setTypeFixPos(1);
	_idle.setScale(2.0f, 2.0f);
	_idle.addSprite(eIdSprite::ALADIN_IDLE_01);
	_idle.addSprite(eIdSprite::ALADIN_IDLE_02);
	_idle.addSprite(eIdSprite::ALADIN_IDLE_03);
	_idle.addSprite(eIdSprite::ALADIN_IDLE_04);
	_idle.addSprite(eIdSprite::ALADIN_IDLE_05);
	_idle.addSprite(eIdSprite::ALADIN_IDLE_06);
	_idle.addSprite(eIdSprite::ALADIN_IDLE_07);
	_idle.addSprite(eIdSprite::ALADIN_IDLE_08);;

	_listAnimation[eIdAnimation::ALADIN_IDLING_01] = _idle;

	Animation _jump;
	_jump.setTimePerFrame(0.4f);
	_jump.setIsLoop(true);
	_jump.setTypeFixPos(3);
	_jump.setScale(2.0f, 2.0f);
	_jump.addSprite(eIdSprite::ALADIN_JUMP_01);
	_jump.addSprite(eIdSprite::ALADIN_JUMP_02);
	_jump.addSprite(eIdSprite::ALADIN_JUMP_03);
	_jump.addSprite(eIdSprite::ALADIN_JUMP_04);
	_jump.addSprite(eIdSprite::ALADIN_JUMP_05);
	_jump.addSprite(eIdSprite::ALADIN_JUMP_06);
	_jump.addSprite(eIdSprite::ALADIN_JUMP_07);
	_jump.addSprite(eIdSprite::ALADIN_JUMP_08);
	_jump.addSprite(eIdSprite::ALADIN_JUMP_09);
	_jump.addSprite(eIdSprite::ALADIN_JUMP_10);
	_jump.addSprite(eIdSprite::ALADIN_JUMP_11);
	_jump.addSprite(eIdSprite::ALADIN_JUMP_12);
	_jump.addSprite(eIdSprite::ALADIN_JUMP_13);

	_listAnimation[eIdAnimation::ALADIN_JUMPING] = _jump;

	Animation _run;
	_run.setTimePerFrame(0.2f);
	_run.setIsLoop(true);
	_run.setTypeFixPos(3);
	_run.setIndexStart(4);
	_run.setScale(2.0f, 2.0f);
	_run.addSprite(eIdSprite::ALADIN_RUN_01);
	_run.addSprite(eIdSprite::ALADIN_RUN_02);
	_run.addSprite(eIdSprite::ALADIN_RUN_03);
	_run.addSprite(eIdSprite::ALADIN_RUN_04);
	_run.addSprite(eIdSprite::ALADIN_RUN_05);
	_run.addSprite(eIdSprite::ALADIN_RUN_06);
	_run.addSprite(eIdSprite::ALADIN_RUN_07);
	_run.addSprite(eIdSprite::ALADIN_RUN_08);
	_run.addSprite(eIdSprite::ALADIN_RUN_09);
	_run.addSprite(eIdSprite::ALADIN_RUN_10);
	_run.addSprite(eIdSprite::ALADIN_RUN_11);
	_run.addSprite(eIdSprite::ALADIN_RUN_12);
	_run.addSprite(eIdSprite::ALADIN_RUN_13);

	_listAnimation[eIdAnimation::ALADIN_RUNNING] = _run;
#pragma endregion

}

pAnimationManager AnimationManager::getInstance() {
	if (_instance == nullptr) {
		_instance = new AnimationManager();
	}
	return _instance;
}

void AnimationManager::add(eIdAnimation id, Animation animation)
{
	this->_listAnimation[id] = animation;
}

Animation AnimationManager::get(int id)
{
	return this->_listAnimation[id];
}
