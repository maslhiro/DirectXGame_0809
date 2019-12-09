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

#pragma region Apple Throw

	Animation _appleThrow;
	_appleThrow.setTimePerFrame(0.07f);
	_appleThrow.setIsLoop(true);
	_appleThrow.setTypeFixPos(eTypeFixPos::C_C);
	_appleThrow.addSprite(eIdSprite::APPLE_THROW_01);
	_appleThrow.addSprite(eIdSprite::APPLE_THROW_02);
	_appleThrow.addSprite(eIdSprite::APPLE_THROW_03);
	_appleThrow.addSprite(eIdSprite::APPLE_THROW_04);

	_listAnimation[eIdAnimation::APPLE_THROW] = _appleThrow;

#pragma endregion

#pragma region Apple Throw Explode
	Animation _appleThrowExplode;
	_appleThrowExplode.setTimePerFrame(0.08f);
	_appleThrowExplode.setIsLoop(false);
	_appleThrowExplode.setTypeFixPos(eTypeFixPos::C_C);
	_appleThrowExplode.setScale(2.0f, 2.0f);
	_appleThrowExplode.addSprite(eIdSprite::APPLE_THROW_EXPLODE_01);
	_appleThrowExplode.addSprite(eIdSprite::APPLE_THROW_EXPLODE_02);
	_appleThrowExplode.addSprite(eIdSprite::APPLE_THROW_EXPLODE_03);
	_appleThrowExplode.addSprite(eIdSprite::APPLE_THROW_EXPLODE_04);
	_appleThrowExplode.addSprite(eIdSprite::APPLE_THROW_EXPLODE_05);

	_listAnimation[eIdAnimation::APPLE_THROW_EXPLODE] = _appleThrowExplode;
#pragma endregion

#pragma region Apple Explode
	Animation _appleExplode;
	_appleExplode.setTimePerFrame(0.08f);
	_appleExplode.setIsLoop(false);
	_appleExplode.setTypeFixPos(eTypeFixPos::C_C);
	_appleExplode.setScale(2.0f, 2.0f);
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
	_wreckingBall.setTypeFixPos(eTypeFixPos::L_T);
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

#pragma region SKELETON
	Animation _skeleton;
	_skeleton.setTimePerFrame(0.08f);
	_skeleton.setIsLoop(true);
	_skeleton.setTypeFixPos(eTypeFixPos::C_BT);
	_skeleton.setScale(2.0f, 2.0f);
	_skeleton.addSprite(eIdSprite::SKELETON_01);
	_skeleton.addSprite(eIdSprite::SKELETON_02);
	_skeleton.addSprite(eIdSprite::SKELETON_03);
	_skeleton.addSprite(eIdSprite::SKELETON_04);
	_skeleton.addSprite(eIdSprite::SKELETON_05);
	_skeleton.addSprite(eIdSprite::SKELETON_06);
	_skeleton.addSprite(eIdSprite::SKELETON_07);
	_skeleton.addSprite(eIdSprite::SKELETON_08);
	_skeleton.addSprite(eIdSprite::SKELETON_09);
	_skeleton.addSprite(eIdSprite::SKELETON_10);
	_skeleton.addSprite(eIdSprite::SKELETON_11);
	_skeleton.addSprite(eIdSprite::SKELETON_12);
	_skeleton.addSprite(eIdSprite::SKELETON_13);
	_skeleton.addSprite(eIdSprite::SKELETON_14);
	_skeleton.addSprite(eIdSprite::SKELETON_15);
	_skeleton.addSprite(eIdSprite::SKELETON_16);
	_skeleton.addSprite(eIdSprite::SKELETON_17);
	_skeleton.addSprite(eIdSprite::SKELETON_18);
	_skeleton.addSprite(eIdSprite::SKELETON_19);
	_skeleton.addSprite(eIdSprite::SKELETON_20);

	_listAnimation[eIdAnimation::SKELETON_VISIBLE] = _skeleton;
#pragma endregion

#pragma region ROCK
	Animation _rock;
	_rock.setTimePerFrame(0.5f);
	_rock.setIsLoop(true);
	_rock.setTypeFixPos(eTypeFixPos::L_T);
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

#pragma region SPIKE
	Animation _spike;
	_spike.setTimePerFrame(0.05f);
	_spike.setIsLoop(true);
	_spike.setTypeFixPos(eTypeFixPos::L_T);
	_spike.addSprite(eIdSprite::SPIKE_01);
	_spike.addSprite(eIdSprite::SPIKE_02);
	_spike.addSprite(eIdSprite::SPIKE_03);
	_spike.addSprite(eIdSprite::SPIKE_04);
	_spike.addSprite(eIdSprite::SPIKE_05);
	_spike.addSprite(eIdSprite::SPIKE_06);
	_spike.addSprite(eIdSprite::SPIKE_05);
	_spike.addSprite(eIdSprite::SPIKE_04);
	_spike.addSprite(eIdSprite::SPIKE_03);
	_spike.addSprite(eIdSprite::SPIKE_02);

	_listAnimation[eIdAnimation::SPIKE_VISIBLE] = _spike;
#pragma endregion

#pragma region BAT
	Animation _bat;
	_bat.setTimePerFrame(0.12f);
	_bat.setIsLoop(true);
	_bat.setIndexStart(4);
	_bat.setTypeFixPos(eTypeFixPos::C_C);
	_bat.setScale(2.0f, 2.0f);
	_bat.addSprite(eIdSprite::BAT_01);
	_bat.addSprite(eIdSprite::BAT_02);
	_bat.addSprite(eIdSprite::BAT_03);
	_bat.addSprite(eIdSprite::BAT_04);
	_bat.addSprite(eIdSprite::BAT_05);
	_bat.addSprite(eIdSprite::BAT_06);
	_bat.addSprite(eIdSprite::BAT_07);
	_bat.addSprite(eIdSprite::BAT_08);
	_bat.addSprite(eIdSprite::BAT_09);
	_bat.addSprite(eIdSprite::BAT_10);
	_bat.addSprite(eIdSprite::BAT_11);

	_listAnimation[eIdAnimation::BAT_VISIBLE] = _bat;
#pragma endregion

#pragma region Aladin

	Animation _stand;
	_stand.setTimePerFrame(1.0f);
	_stand.setIsLoop(false);
	_stand.setTypeFixPos(eTypeFixPos::L_BT);
	_stand.setScale(2.0f, 2.0f);
	_stand.addSprite(eIdSprite::ALADDIN_STAND_01);

	_listAnimation[eIdAnimation::ALADDIN_STAND] = _stand;


	Animation _idle01;
	_idle01.setTimePerFrame(0.16f);
	_idle01.setIsLoop(true);
	_idle01.setTypeFixPos(eTypeFixPos::C_BT);
	_idle01.setScale(2.0f, 2.0f);
	_idle01.addSprite(eIdSprite::ALADDIN_IDLE_1_01);
	_idle01.addSprite(eIdSprite::ALADDIN_IDLE_1_02);
	_idle01.addSprite(eIdSprite::ALADDIN_IDLE_1_03);
	_idle01.addSprite(eIdSprite::ALADDIN_IDLE_1_04);
	_idle01.addSprite(eIdSprite::ALADDIN_IDLE_1_05);
	_idle01.addSprite(eIdSprite::ALADDIN_IDLE_1_06);
	_idle01.addSprite(eIdSprite::ALADDIN_IDLE_1_07);
	_idle01.addSprite(eIdSprite::ALADDIN_IDLE_1_08);

	_listAnimation[eIdAnimation::ALADDIN_IDLE_01] = _idle01;

	Animation _idle02;
	_idle02.setTimePerFrame(0.08f);
	_idle02.setIsLoop(true);
	_idle02.setIndexStart(18);
	_idle02.setTypeFixPos(eTypeFixPos::L_BT);
	_idle02.setScale(2.0f, 2.0f);
	_idle02.addSprite(eIdSprite::ALADDIN_IDLE_2_01);
	_idle02.addSprite(eIdSprite::ALADDIN_IDLE_2_02);
	_idle02.addSprite(eIdSprite::ALADDIN_IDLE_2_03);
	_idle02.addSprite(eIdSprite::ALADDIN_IDLE_2_04);
	_idle02.addSprite(eIdSprite::ALADDIN_IDLE_2_05);
	_idle02.addSprite(eIdSprite::ALADDIN_IDLE_2_06);
	_idle02.addSprite(eIdSprite::ALADDIN_IDLE_2_07);
	_idle02.addSprite(eIdSprite::ALADDIN_IDLE_2_08);
	_idle02.addSprite(eIdSprite::ALADDIN_IDLE_2_09);
	_idle02.addSprite(eIdSprite::ALADDIN_IDLE_2_10);
	_idle02.addSprite(eIdSprite::ALADDIN_IDLE_2_11);
	_idle02.addSprite(eIdSprite::ALADDIN_IDLE_2_12);
	_idle02.addSprite(eIdSprite::ALADDIN_IDLE_2_13);
	_idle02.addSprite(eIdSprite::ALADDIN_IDLE_2_14);
	_idle02.addSprite(eIdSprite::ALADDIN_IDLE_2_15);
	_idle02.addSprite(eIdSprite::ALADDIN_IDLE_2_16);
	_idle02.addSprite(eIdSprite::ALADDIN_IDLE_2_17);
	_idle02.addSprite(eIdSprite::ALADDIN_IDLE_2_18);

	_idle02.addSprite(eIdSprite::ALADDIN_IDLE_2_19);
	_idle02.addSprite(eIdSprite::ALADDIN_IDLE_2_20);
	_idle02.addSprite(eIdSprite::ALADDIN_IDLE_2_21);
	_idle02.addSprite(eIdSprite::ALADDIN_IDLE_2_22);
	_idle02.addSprite(eIdSprite::ALADDIN_IDLE_2_23);
	_idle02.addSprite(eIdSprite::ALADDIN_IDLE_2_24);
	_idle02.addSprite(eIdSprite::ALADDIN_IDLE_2_25);
	_idle02.addSprite(eIdSprite::ALADDIN_IDLE_2_26);
	_idle02.addSprite(eIdSprite::ALADDIN_IDLE_2_27);
	_idle02.addSprite(eIdSprite::ALADDIN_IDLE_2_28);
	_idle02.addSprite(eIdSprite::ALADDIN_IDLE_2_29);
	_idle02.addSprite(eIdSprite::ALADDIN_IDLE_2_30);
	_idle02.addSprite(eIdSprite::ALADDIN_IDLE_2_31);
	_idle02.addSprite(eIdSprite::ALADDIN_IDLE_2_32);
	_idle02.addSprite(eIdSprite::ALADDIN_IDLE_2_33);
	_idle02.addSprite(eIdSprite::ALADDIN_IDLE_2_34);
	_idle02.addSprite(eIdSprite::ALADDIN_IDLE_2_35);
	_idle02.addSprite(eIdSprite::ALADDIN_IDLE_2_36);

	_listAnimation[eIdAnimation::ALADDIN_IDLE_02] = _idle02;

	Animation _jump;
	_jump.setTimePerFrame(0.092f);
	_jump.setIsLoop(false);
	_jump.setTypeFixPos(eTypeFixPos::L_BT);
	_jump.setScale(2.0f, 2.0f);
	_jump.addSprite(eIdSprite::ALADDIN_JUMP_01);
	_jump.addSprite(eIdSprite::ALADDIN_JUMP_02);
	_jump.addSprite(eIdSprite::ALADDIN_JUMP_03);
	_jump.addSprite(eIdSprite::ALADDIN_JUMP_04);
	_jump.addSprite(eIdSprite::ALADDIN_JUMP_05);
	_jump.addSprite(eIdSprite::ALADDIN_JUMP_06);
	_jump.addSprite(eIdSprite::ALADDIN_JUMP_07);
	_jump.addSprite(eIdSprite::ALADDIN_JUMP_08);
	_jump.addSprite(eIdSprite::ALADDIN_JUMP_09);
	_jump.addSprite(eIdSprite::ALADDIN_JUMP_10);
	_jump.addSprite(eIdSprite::ALADDIN_JUMP_11);
	_jump.addSprite(eIdSprite::ALADDIN_JUMP_12);
	_jump.addSprite(eIdSprite::ALADDIN_JUMP_13);

	_listAnimation[eIdAnimation::ALADDIN_JUMP] = _jump;

	Animation _run;
	_run.setTimePerFrame(0.06f);
	_run.setIsLoop(true);
	_run.setTypeFixPos(eTypeFixPos::L_BT);
	_run.setIndexStart(3);
	_run.setScale(2.0f, 2.0f);
	_run.addSprite(eIdSprite::ALADDIN_RUN_01);
	_run.addSprite(eIdSprite::ALADDIN_RUN_02);
	_run.addSprite(eIdSprite::ALADDIN_RUN_03);
	_run.addSprite(eIdSprite::ALADDIN_RUN_04);
	_run.addSprite(eIdSprite::ALADDIN_RUN_05);
	_run.addSprite(eIdSprite::ALADDIN_RUN_06);
	_run.addSprite(eIdSprite::ALADDIN_RUN_07);
	_run.addSprite(eIdSprite::ALADDIN_RUN_08);
	_run.addSprite(eIdSprite::ALADDIN_RUN_09);
	_run.addSprite(eIdSprite::ALADDIN_RUN_10);
	_run.addSprite(eIdSprite::ALADDIN_RUN_11);
	_run.addSprite(eIdSprite::ALADDIN_RUN_12);
	_run.addSprite(eIdSprite::ALADDIN_RUN_13);

	_listAnimation[eIdAnimation::ALADDIN_RUN] = _run;

	Animation _damage;
	_damage.setTimePerFrame(0.15f);
	_damage.setIsLoop(true);
	_damage.setTypeFixPos(eTypeFixPos::L_BT);
	_damage.setScale(2.0f, 2.0f);
	_damage.addSprite(eIdSprite::ALADDIN_DAMAGE_01);
	_damage.addSprite(eIdSprite::ALADDIN_DAMAGE_02);
	_damage.addSprite(eIdSprite::ALADDIN_DAMAGE_03);
	_damage.addSprite(eIdSprite::ALADDIN_DAMAGE_04);
	_damage.addSprite(eIdSprite::ALADDIN_DAMAGE_05);
	_damage.addSprite(eIdSprite::ALADDIN_DAMAGE_06);

	_listAnimation[eIdAnimation::ALADDIN_DAMAGE] = _damage;

	Animation _runJump;
	_runJump.setTimePerFrame(0.12f);
	_runJump.setIsLoop(false);
	_runJump.setTypeFixPos(eTypeFixPos::L_BT);
	_runJump.setScale(2.0f, 2.0f);
	_runJump.addSprite(eIdSprite::ALADDIN_RUN_JUMP_01);
	_runJump.addSprite(eIdSprite::ALADDIN_RUN_JUMP_02);
	_runJump.addSprite(eIdSprite::ALADDIN_RUN_JUMP_03);
	_runJump.addSprite(eIdSprite::ALADDIN_RUN_JUMP_04);
	_runJump.addSprite(eIdSprite::ALADDIN_RUN_JUMP_05);
	_runJump.addSprite(eIdSprite::ALADDIN_RUN_JUMP_06);
	_runJump.addSprite(eIdSprite::ALADDIN_RUN_JUMP_07);

	_listAnimation[eIdAnimation::ALADDIN_RUN_JUMP] = _runJump;

	Animation _jumpAttack;
	_jumpAttack.setTimePerFrame(0.05f);
	_jumpAttack.setIsLoop(false);
	_jumpAttack.setTypeFixPos(eTypeFixPos::L_BT);
	_jumpAttack.setScale(2.0f, 2.0f);
	_jumpAttack.addSprite(eIdSprite::ALADDIN_JUMP_ATTACK_01);
	_jumpAttack.addSprite(eIdSprite::ALADDIN_JUMP_ATTACK_02);
	_jumpAttack.addSprite(eIdSprite::ALADDIN_JUMP_ATTACK_03);
	_jumpAttack.addSprite(eIdSprite::ALADDIN_JUMP_ATTACK_04);
	_jumpAttack.addSprite(eIdSprite::ALADDIN_JUMP_ATTACK_05);
	_jumpAttack.addSprite(eIdSprite::ALADDIN_JUMP_ATTACK_06);
	_jumpAttack.addSprite(eIdSprite::ALADDIN_JUMP_ATTACK_07);

	_listAnimation[eIdAnimation::ALADDIN_JUMP_ATTACK] = _jumpAttack;

	Animation _attack;
	_attack.setTimePerFrame(0.05f);
	_attack.setIsLoop(false);
	_attack.setTypeFixPos(eTypeFixPos::L_BT);
	_attack.setScale(2.0f, 2.0f);
	_attack.addSprite(eIdSprite::ALADDIN_ATTACK_01);
	_attack.addSprite(eIdSprite::ALADDIN_ATTACK_02);
	_attack.addSprite(eIdSprite::ALADDIN_ATTACK_03);
	_attack.addSprite(eIdSprite::ALADDIN_ATTACK_04);
	_attack.addSprite(eIdSprite::ALADDIN_ATTACK_05);

	_listAnimation[eIdAnimation::ALADDIN_ATTACK] = _attack;

	Animation _runAttack;
	_runAttack.setTimePerFrame(0.05f);
	_runAttack.setIsLoop(false);
	_runAttack.setTypeFixPos(eTypeFixPos::L_BT);
	_runAttack.setScale(2.0f, 2.0f);
	_runAttack.addSprite(eIdSprite::ALADDIN_RUN_ATTACK_01);
	_runAttack.addSprite(eIdSprite::ALADDIN_RUN_ATTACK_02);
	_runAttack.addSprite(eIdSprite::ALADDIN_RUN_ATTACK_03);
	_runAttack.addSprite(eIdSprite::ALADDIN_RUN_ATTACK_04);
	_runAttack.addSprite(eIdSprite::ALADDIN_RUN_ATTACK_05);
	_runAttack.addSprite(eIdSprite::ALADDIN_RUN_ATTACK_06);

	_listAnimation[eIdAnimation::ALADDIN_RUN_ATTACK] = _runAttack;

	Animation _sit;
	_sit.setTimePerFrame(0.05f);
	_sit.setIsLoop(false);
	_sit.setTypeFixPos(eTypeFixPos::L_BT);
	_sit.setScale(2.0f, 2.0f);
	_sit.addSprite(eIdSprite::ALADDIN_SIT_01);
	_sit.addSprite(eIdSprite::ALADDIN_SIT_02);
	_sit.addSprite(eIdSprite::ALADDIN_SIT_03);
	_sit.addSprite(eIdSprite::ALADDIN_SIT_04);

	_listAnimation[eIdAnimation::ALADDIN_SIT] = _sit;

	Animation _sit_;
	_sit_.setTimePerFrame(0.05f);
	_sit_.setIsLoop(false);
	_sit_.setTypeFixPos(eTypeFixPos::L_BT);
	_sit_.setScale(2.0f, 2.0f);
	_sit_.addSprite(eIdSprite::ALADDIN_SIT_04);

	_listAnimation[eIdAnimation::ALADDIN_SIT_] = _sit_;

	Animation _sitAttack;
	_sitAttack.setTimePerFrame(0.05f);
	_sitAttack.setIsLoop(false);
	_sitAttack.setTypeFixPos(eTypeFixPos::L_BT);
	_sitAttack.setScale(2.0f, 2.0f);
	_sitAttack.addSprite(eIdSprite::ALADDIN_SIT_ATTACK_01);
	_sitAttack.addSprite(eIdSprite::ALADDIN_SIT_ATTACK_02);
	_sitAttack.addSprite(eIdSprite::ALADDIN_SIT_ATTACK_03);
	_sitAttack.addSprite(eIdSprite::ALADDIN_SIT_ATTACK_04);
	_sitAttack.addSprite(eIdSprite::ALADDIN_SIT_ATTACK_05);

	_listAnimation[eIdAnimation::ALADDIN_SIT_ATTACK] = _sitAttack;

	Animation _throw;
	_throw.setTimePerFrame(0.05f);
	_throw.setIsLoop(false);
	_throw.setTypeFixPos(eTypeFixPos::L_BT);
	_throw.setScale(2.0f, 2.0f);
	_throw.addSprite(eIdSprite::ALADDIN_THROW_01);
	_throw.addSprite(eIdSprite::ALADDIN_THROW_02);
	_throw.addSprite(eIdSprite::ALADDIN_THROW_03);
	_throw.addSprite(eIdSprite::ALADDIN_THROW_04);
	_throw.addSprite(eIdSprite::ALADDIN_THROW_05);
	_throw.addSprite(eIdSprite::ALADDIN_THROW_06);
	_throw.addSprite(eIdSprite::ALADDIN_THROW_07);

	_listAnimation[eIdAnimation::ALADDIN_THROW] = _throw;

	Animation _sitThrow;
	_sitThrow.setTimePerFrame(0.05f);
	_sitThrow.setIsLoop(false);
	_sitThrow.setTypeFixPos(eTypeFixPos::L_BT);
	_sitThrow.setScale(2.0f, 2.0f);
	_sitThrow.addSprite(eIdSprite::ALADDIN_SIT_THROW_01);
	_sitThrow.addSprite(eIdSprite::ALADDIN_SIT_THROW_02);
	_sitThrow.addSprite(eIdSprite::ALADDIN_SIT_THROW_03);
	_sitThrow.addSprite(eIdSprite::ALADDIN_SIT_THROW_04);
	_sitThrow.addSprite(eIdSprite::ALADDIN_SIT_THROW_05);

	_listAnimation[eIdAnimation::ALADDIN_SIT_THROW] = _sitThrow;

	Animation _jumpThrow;
	_jumpThrow.setTimePerFrame(0.05f);
	_jumpThrow.setIsLoop(false);
	_jumpThrow.setTypeFixPos(eTypeFixPos::L_BT);
	_jumpThrow.setScale(2.0f, 2.0f);
	_jumpThrow.addSprite(eIdSprite::ALADDIN_JUMP_THROW_01);
	_jumpThrow.addSprite(eIdSprite::ALADDIN_JUMP_THROW_02);
	_jumpThrow.addSprite(eIdSprite::ALADDIN_JUMP_THROW_03);
	_jumpThrow.addSprite(eIdSprite::ALADDIN_JUMP_THROW_04);
	_jumpThrow.addSprite(eIdSprite::ALADDIN_JUMP_THROW_05);
	_jumpThrow.addSprite(eIdSprite::ALADDIN_JUMP_THROW_06);
	_jumpThrow.addSprite(eIdSprite::ALADDIN_JUMP_THROW_07);
	_jumpThrow.addSprite(eIdSprite::ALADDIN_JUMP_THROW_08);

	_listAnimation[eIdAnimation::ALADDIN_JUMP_THROW] = _jumpThrow;

	Animation _climb;
	_climb.setTimePerFrame(0.08f);
	_climb.setIsLoop(true);
	_climb.setTypeFixPos(eTypeFixPos::C_C);
	_climb.setScale(2.0f, 2.0f);
	_climb.addSprite(eIdSprite::ALADDIN_CLIMB_01);
	_climb.addSprite(eIdSprite::ALADDIN_CLIMB_02);
	_climb.addSprite(eIdSprite::ALADDIN_CLIMB_03);
	_climb.addSprite(eIdSprite::ALADDIN_CLIMB_04);
	_climb.addSprite(eIdSprite::ALADDIN_CLIMB_05);
	_climb.addSprite(eIdSprite::ALADDIN_CLIMB_06);
	_climb.addSprite(eIdSprite::ALADDIN_CLIMB_07);
	_climb.addSprite(eIdSprite::ALADDIN_CLIMB_08);

	_listAnimation[eIdAnimation::ALADDIN_CLIMB] = _climb;

	Animation _climbJump;
	_climbJump.setTimePerFrame(0.05f);
	_climbJump.setIsLoop(false);
	_climbJump.setTypeFixPos(eTypeFixPos::C_BT);
	_climbJump.setScale(2.0f, 2.0f);
	_climbJump.addSprite(eIdSprite::ALADDIN_CLIMB_JUMP_01);
	_climbJump.addSprite(eIdSprite::ALADDIN_CLIMB_JUMP_02);
	_climbJump.addSprite(eIdSprite::ALADDIN_CLIMB_JUMP_03);
	_climbJump.addSprite(eIdSprite::ALADDIN_CLIMB_JUMP_04);
	_climbJump.addSprite(eIdSprite::ALADDIN_CLIMB_JUMP_05);
	_climbJump.addSprite(eIdSprite::ALADDIN_CLIMB_JUMP_06);
	_climbJump.addSprite(eIdSprite::ALADDIN_CLIMB_JUMP_07);
	_climbJump.addSprite(eIdSprite::ALADDIN_CLIMB_JUMP_08);
	//	_climbJump.addSprite(eIdSprite::ALADDIN_CLIMB_JUMP_09);

	_listAnimation[eIdAnimation::ALADDIN_CLIMB_JUMP] = _climbJump;
#pragma endregion

#pragma region NAHBI
	Animation _nahbiStand;
	_nahbiStand.setTimePerFrame(0.08f);
	_nahbiStand.setIsLoop(true);
	_nahbiStand.setTypeFixPos(eTypeFixPos::R_BT);
	_nahbiStand.setScale(2.0f, 2.0f);
	_nahbiStand.addSprite(eIdSprite::NAHBI_STAND_01);
	_nahbiStand.addSprite(eIdSprite::NAHBI_STAND_02);
	_nahbiStand.addSprite(eIdSprite::NAHBI_STAND_03);
	_nahbiStand.addSprite(eIdSprite::NAHBI_STAND_04);
	_nahbiStand.addSprite(eIdSprite::NAHBI_STAND_05);
	_nahbiStand.addSprite(eIdSprite::NAHBI_STAND_06);

	_listAnimation[eIdAnimation::NAHBI_STAND] = _nahbiStand;

	Animation _nahbiAttack;
	_nahbiAttack.setTimePerFrame(0.08f);
	_nahbiAttack.setIsLoop(true);
	_nahbiAttack.setTypeFixPos(eTypeFixPos::R_BT);
	_nahbiAttack.setScale(2.0f, 2.0f);
	_nahbiAttack.addSprite(eIdSprite::NAHBI_ATTACK_01);
	_nahbiAttack.addSprite(eIdSprite::NAHBI_ATTACK_02);
	_nahbiAttack.addSprite(eIdSprite::NAHBI_ATTACK_03);
	_nahbiAttack.addSprite(eIdSprite::NAHBI_ATTACK_04);
	_nahbiAttack.addSprite(eIdSprite::NAHBI_ATTACK_05);
	_nahbiAttack.addSprite(eIdSprite::NAHBI_ATTACK_06);

	_listAnimation[eIdAnimation::NAHBI_ATTACK] = _nahbiAttack;

	Animation _nahbiRun;
	_nahbiRun.setTimePerFrame(0.08f);
	_nahbiRun.setIsLoop(true);
	_nahbiRun.setTypeFixPos(eTypeFixPos::R_BT);
	_nahbiRun.setScale(2.0f, 2.0f);
	_nahbiRun.addSprite(eIdSprite::NAHBI_RUN_01);
	_nahbiRun.addSprite(eIdSprite::NAHBI_RUN_02);
	_nahbiRun.addSprite(eIdSprite::NAHBI_RUN_03);
	_nahbiRun.addSprite(eIdSprite::NAHBI_RUN_04);
	_nahbiRun.addSprite(eIdSprite::NAHBI_RUN_05);
	_nahbiRun.addSprite(eIdSprite::NAHBI_RUN_06);
	_nahbiRun.addSprite(eIdSprite::NAHBI_RUN_07);
	_nahbiRun.addSprite(eIdSprite::NAHBI_RUN_08);

	_listAnimation[eIdAnimation::NAHBI_RUN] = _nahbiRun;
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
