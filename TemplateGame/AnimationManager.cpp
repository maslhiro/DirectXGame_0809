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

#pragma region Apple Explode
	Animation _appleExplode;
	_appleExplode.setTimePerFrame(0.08f);
	_appleExplode.setIsLoop(true);
	_appleExplode.setTypeFixPos(3);
	//_apple.setIsReverse(true);
	//_apple.setDrawingBound(true);
	_appleExplode.addSprite(eIdSprite::APPLE_EXPLODE_01);
	_appleExplode.addSprite(eIdSprite::APPLE_EXPLODE_02);
	_appleExplode.addSprite(eIdSprite::APPLE_EXPLODE_03);
	_appleExplode.addSprite(eIdSprite::APPLE_EXPLODE_04);
	_appleExplode.addSprite(eIdSprite::APPLE_EXPLODE_05);
	_appleExplode.addSprite(eIdSprite::APPLE_EXPLODE_06);
	_appleExplode.addSprite(eIdSprite::APPLE_EXPLODE_07);
	_appleExplode.addSprite(eIdSprite::APPLE_EXPLODE_08);
	_appleExplode.addSprite(eIdSprite::APPLE_EXPLODE_09);

	_listAnimation[eIdAnimation::APPLE_EXPLODE] = _appleExplode;
#pragma endregion

#pragma region WreckingBall
	Animation _wreckingBall;
	_wreckingBall.setTimePerFrame(0.08f);
	_wreckingBall.setIsLoop(true);
	_wreckingBall.setTypeFixPos(2);
	//_wreckingBall.setIsReverse(true);
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
	_wreckingBall.addSprite(eIdSprite::WRECKING_BALL_14);
	_wreckingBall.addSprite(eIdSprite::WRECKING_BALL_13);
	_wreckingBall.addSprite(eIdSprite::WRECKING_BALL_12);
	_wreckingBall.addSprite(eIdSprite::WRECKING_BALL_11);
	_wreckingBall.addSprite(eIdSprite::WRECKING_BALL_10);
	_wreckingBall.addSprite(eIdSprite::WRECKING_BALL_09);
	_wreckingBall.addSprite(eIdSprite::WRECKING_BALL_08);
	_wreckingBall.addSprite(eIdSprite::WRECKING_BALL_07);
	_wreckingBall.addSprite(eIdSprite::WRECKING_BALL_06);
	_wreckingBall.addSprite(eIdSprite::WRECKING_BALL_05);
	_wreckingBall.addSprite(eIdSprite::WRECKING_BALL_04);
	_wreckingBall.addSprite(eIdSprite::WRECKING_BALL_03);
	_wreckingBall.addSprite(eIdSprite::WRECKING_BALL_02);

	_listAnimation[eIdAnimation::WRECKING_BALL_VISIBLE] = _wreckingBall;
#pragma endregion

#pragma region ROCK
	Animation _rock;
	_rock.setTimePerFrame(0.5f);
	_rock.setIsLoop(true);
	_rock.setTypeFixPos(2);
	//_rock.setIsReverse(true);
	//_rock.setDrawingBound(true);
	_rock.addSprite(eIdSprite::ROCK_01);
	_rock.addSprite(eIdSprite::ROCK_02);
	_rock.addSprite(eIdSprite::ROCK_03);
	_rock.addSprite(eIdSprite::ROCK_04);
	_rock.addSprite(eIdSprite::ROCK_05);
	_rock.addSprite(eIdSprite::ROCK_04);
	_rock.addSprite(eIdSprite::ROCK_03);
	_rock.addSprite(eIdSprite::ROCK_02);
	_rock.addSprite(eIdSprite::ROCK_01);

	_listAnimation[eIdAnimation::ROCK_VISIBLE] = _rock;
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
	_stand.setIsLoop(false);
	_stand.setTypeFixPos(1);
	_stand.setScale(2.0f, 2.0f);
	_stand.addSprite(eIdSprite::ALADIN_STAND);

	_listAnimation[eIdAnimation::ALADIN_STANDING] = _stand;


	Animation _idle;
	_idle.setTimePerFrame(0.18f);
	_idle.setIsLoop(true);
	_idle.setTypeFixPos(4);
	_idle.setScale(2.0f, 2.0f);
	_idle.addSprite(eIdSprite::ALADIN_IDLE_01);
	_idle.addSprite(eIdSprite::ALADIN_IDLE_02);
	_idle.addSprite(eIdSprite::ALADIN_IDLE_03);
	_idle.addSprite(eIdSprite::ALADIN_IDLE_04);
	_idle.addSprite(eIdSprite::ALADIN_IDLE_05);
	_idle.addSprite(eIdSprite::ALADIN_IDLE_06);
	_idle.addSprite(eIdSprite::ALADIN_IDLE_07);
	_idle.addSprite(eIdSprite::ALADIN_IDLE_08);

	_listAnimation[eIdAnimation::ALADIN_IDLING_01] = _idle;

	Animation _jump;
	_jump.setTimePerFrame(0.092f);
	_jump.setIsLoop(false);
	_jump.setTypeFixPos(1);
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
	_run.setTimePerFrame(0.06f);
	_run.setIsLoop(true);
	_run.setTypeFixPos(1);
	_run.setIndexStart(3);
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

	Animation _damage;
	_damage.setTimePerFrame(0.15f);
	_damage.setIsLoop(true);
	_damage.setTypeFixPos(1);
	_damage.setScale(2.0f, 2.0f);
	_damage.addSprite(eIdSprite::ALADIN_DAMAGE_01);
	_damage.addSprite(eIdSprite::ALADIN_DAMAGE_02);
	_damage.addSprite(eIdSprite::ALADIN_DAMAGE_03);
	_damage.addSprite(eIdSprite::ALADIN_DAMAGE_04);
	_damage.addSprite(eIdSprite::ALADIN_DAMAGE_05);
	_damage.addSprite(eIdSprite::ALADIN_DAMAGE_06);

	_listAnimation[eIdAnimation::ALADIN_DAMAGE] = _damage;

	Animation _runJump;
	_runJump.setTimePerFrame(0.15f);
	_runJump.setIsLoop(false);
	_runJump.setTypeFixPos(1);
	_runJump.setScale(2.0f, 2.0f);
	_runJump.addSprite(eIdSprite::ALADIN_RUN_JUMP_01);
	_runJump.addSprite(eIdSprite::ALADIN_RUN_JUMP_02);
	_runJump.addSprite(eIdSprite::ALADIN_RUN_JUMP_03);
	_runJump.addSprite(eIdSprite::ALADIN_RUN_JUMP_04);
	_runJump.addSprite(eIdSprite::ALADIN_RUN_JUMP_05);
	_runJump.addSprite(eIdSprite::ALADIN_RUN_JUMP_06);
	_runJump.addSprite(eIdSprite::ALADIN_RUN_JUMP_07);

	_listAnimation[eIdAnimation::ALADING_RUN_JUMP] = _runJump;
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
