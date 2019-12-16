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

	Animation _appleCollection;
	_appleCollection.setTimePerFrame(1.0f);
	_appleCollection.setIsLoop(false);
	_appleCollection.addSprite(eIdSprite::ITEM_APPLE_BIG);

	_listAnimation[eIdAnimation::APPLE_COLLECTION] = _appleCollection;
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

#pragma region Enermy Explode
	Animation _enermyExplode;
	_enermyExplode.setTimePerFrame(0.08f);
	_enermyExplode.setIsLoop(false);
	_enermyExplode.setTypeFixPos(eTypeFixPos::C_BT);
	_enermyExplode.setScale(2.0f, 2.0f);
	_enermyExplode.addSprite(eIdSprite::EMERMY_EXPLODE_01);
	_enermyExplode.addSprite(eIdSprite::EMERMY_EXPLODE_02);
	_enermyExplode.addSprite(eIdSprite::EMERMY_EXPLODE_03);
	_enermyExplode.addSprite(eIdSprite::EMERMY_EXPLODE_04);
	_enermyExplode.addSprite(eIdSprite::EMERMY_EXPLODE_05);
	_enermyExplode.addSprite(eIdSprite::EMERMY_EXPLODE_06);
	_enermyExplode.addSprite(eIdSprite::EMERMY_EXPLODE_07);
	_enermyExplode.addSprite(eIdSprite::EMERMY_EXPLODE_08);
	_enermyExplode.addSprite(eIdSprite::EMERMY_EXPLODE_09);

	_listAnimation[eIdAnimation::ENERMY_EXPLODE] = _enermyExplode;
#pragma endregion

#pragma region WreckingBall
	Animation _wreckingBall;
	_wreckingBall.setTimePerFrame(0.1f);
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
	_rock.setTimePerFrame(0.1f);
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

#pragma region BONE
	Animation _bone;
	_bone.setTimePerFrame(0.03f);
	_bone.setIsLoop(true);
	_bone.setTypeFixPos(eTypeFixPos::C_C);
	//_rock.setIsReverse(true);
	//_rock.setDrawingBound(true);
	_bone.addSprite(eIdSprite::BONE_01);
	_bone.addSprite(eIdSprite::BONE_02);
	_bone.addSprite(eIdSprite::BONE_03);
	_bone.addSprite(eIdSprite::BONE_04);

	_listAnimation[eIdAnimation::BONE_VISIBLE] = _bone;
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
	_jump.setTimePerFrame(0.062f);
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

	Animation _fall;
	_fall.setTimePerFrame(0.062f);
	_fall.setIsLoop(false);
	_fall.setTypeFixPos(eTypeFixPos::L_BT);
	_fall.setScale(2.0f, 2.0f);
	_fall.addSprite(eIdSprite::ALADDIN_JUMP_06);
	_fall.addSprite(eIdSprite::ALADDIN_JUMP_07);
	_fall.addSprite(eIdSprite::ALADDIN_JUMP_08);
	_fall.addSprite(eIdSprite::ALADDIN_JUMP_09);
	_fall.addSprite(eIdSprite::ALADDIN_JUMP_10);
	_fall.addSprite(eIdSprite::ALADDIN_JUMP_11);
	_fall.addSprite(eIdSprite::ALADDIN_JUMP_12);
	_fall.addSprite(eIdSprite::ALADDIN_JUMP_13);

	_listAnimation[eIdAnimation::ALADDIN_FALL] = _fall;

	Animation _run;
	_run.setTimePerFrame(0.064f);
	_run.setIsLoop(true);
	_run.setTypeFixPos(eTypeFixPos::L_BT);
	_run.setIndexStart(4);
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
	_damage.setTimePerFrame(0.05f);
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
	_runJump.setTimePerFrame(0.094f);
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
	_runAttack.setTimePerFrame(0.02f);
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
	_climb.addSprite(eIdSprite::ALADDIN_CLIMB_09);
	_climb.addSprite(eIdSprite::ALADDIN_CLIMB_10);
	_climb.addSprite(eIdSprite::ALADDIN_CLIMB_11);
	_climb.addSprite(eIdSprite::ALADDIN_CLIMB_12);
	_climb.addSprite(eIdSprite::ALADDIN_CLIMB_13);
	_climb.addSprite(eIdSprite::ALADDIN_CLIMB_14);

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
	_climbJump.addSprite(eIdSprite::ALADDIN_JUMP_06);
	_climbJump.addSprite(eIdSprite::ALADDIN_JUMP_07);
	_climbJump.addSprite(eIdSprite::ALADDIN_JUMP_08);
	_climbJump.addSprite(eIdSprite::ALADDIN_JUMP_09);
	_climbJump.addSprite(eIdSprite::ALADDIN_JUMP_10);
	_climbJump.addSprite(eIdSprite::ALADDIN_JUMP_11);
	_climbJump.addSprite(eIdSprite::ALADDIN_JUMP_12);
	_climbJump.addSprite(eIdSprite::ALADDIN_JUMP_13);

	_listAnimation[eIdAnimation::ALADDIN_CLIMB_JUMP] = _climbJump;
#pragma endregion

#pragma region NAHBI
	Animation _nahbiStand;
	_nahbiStand.setTimePerFrame(0.08f);
	_nahbiStand.setIsLoop(false);
	_nahbiStand.setTypeFixPos(eTypeFixPos::L_BT);
	_nahbiStand.setScale(2.0f, 2.0f);
	_nahbiStand.addSprite(eIdSprite::NAHBI_STAND_01);

	_listAnimation[eIdAnimation::NAHBI_STAND] = _nahbiStand;

	Animation _nahbiWait;
	_nahbiWait.setTimePerFrame(0.08f);
	_nahbiWait.setIsLoop(true);
	_nahbiWait.setTypeFixPos(eTypeFixPos::L_BT);
	_nahbiWait.setScale(2.0f, 2.0f);
	_nahbiWait.addSprite(eIdSprite::NAHBI_STAND_02);
	_nahbiWait.addSprite(eIdSprite::NAHBI_STAND_03);
	_nahbiWait.addSprite(eIdSprite::NAHBI_STAND_04);
	_nahbiWait.addSprite(eIdSprite::NAHBI_STAND_05);
	_nahbiWait.addSprite(eIdSprite::NAHBI_STAND_06);

	_listAnimation[eIdAnimation::NAHBI_WAIT] = _nahbiWait;

	Animation _nahbiAttack;
	_nahbiAttack.setTimePerFrame(0.08f);
	_nahbiAttack.setIsLoop(true);
	_nahbiAttack.setTypeFixPos(eTypeFixPos::L_BT);
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
	_nahbiRun.setTypeFixPos(eTypeFixPos::L_BT);
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

	Animation _nahbiDamage;
	_nahbiDamage.setTimePerFrame(0.08f);
	_nahbiDamage.setIsLoop(false);
	_nahbiDamage.setTypeFixPos(eTypeFixPos::C_BT);
	_nahbiDamage.setScale(2.0f, 2.0f);
	_nahbiDamage.addSprite(eIdSprite::NAHBI_DAMAGE_01);
	_nahbiDamage.addSprite(eIdSprite::NAHBI_DAMAGE_02);
	_nahbiDamage.addSprite(eIdSprite::NAHBI_DAMAGE_03);
	_nahbiDamage.addSprite(eIdSprite::NAHBI_DAMAGE_04);
	_nahbiDamage.addSprite(eIdSprite::NAHBI_DAMAGE_05);
	_nahbiDamage.addSprite(eIdSprite::NAHBI_DAMAGE_06);

	_listAnimation[eIdAnimation::NAHBI_DAMAGE] = _nahbiDamage;
#pragma endregion

#pragma region FAZAL
	Animation _fazalStand;
	_fazalStand.setTimePerFrame(0.08f);
	_fazalStand.setIsLoop(false);
	_fazalStand.setTypeFixPos(eTypeFixPos::L_BT);
	_fazalStand.setScale(2.0f, 2.0f);
	_fazalStand.addSprite(eIdSprite::FAZAL_DAMAGE_01);

	_listAnimation[eIdAnimation::FAZAL_STAND] = _fazalStand;

	Animation _fazalAttack;
	_fazalAttack.setTimePerFrame(0.08f);
	_fazalAttack.setIsLoop(true);
	_fazalAttack.setTypeFixPos(eTypeFixPos::L_BT);
	_fazalAttack.setScale(2.0f, 2.0f);
	_fazalAttack.addSprite(eIdSprite::FAZAL_ATTACK_01);
	_fazalAttack.addSprite(eIdSprite::FAZAL_ATTACK_02);
	_fazalAttack.addSprite(eIdSprite::FAZAL_ATTACK_03);
	_fazalAttack.addSprite(eIdSprite::FAZAL_ATTACK_04);
	_fazalAttack.addSprite(eIdSprite::FAZAL_ATTACK_05);
	_fazalAttack.addSprite(eIdSprite::FAZAL_ATTACK_06);

	_listAnimation[eIdAnimation::FAZAL_ATTACK] = _fazalAttack;

	Animation _fazalDamage;
	_fazalDamage.setTimePerFrame(0.08f);
	_fazalDamage.setIsLoop(false);
	_fazalDamage.setTypeFixPos(eTypeFixPos::C_BT);
	_fazalDamage.setScale(2.0f, 2.0f);
	_fazalDamage.addSprite(eIdSprite::FAZAL_DAMAGE_01);
	_fazalDamage.addSprite(eIdSprite::FAZAL_DAMAGE_02);
	_fazalDamage.addSprite(eIdSprite::FAZAL_DAMAGE_03);
	_fazalDamage.addSprite(eIdSprite::FAZAL_DAMAGE_04);
	_fazalDamage.addSprite(eIdSprite::FAZAL_DAMAGE_05);
	_fazalDamage.addSprite(eIdSprite::FAZAL_DAMAGE_06);
	_fazalDamage.addSprite(eIdSprite::FAZAL_DAMAGE_07);
	_fazalDamage.addSprite(eIdSprite::FAZAL_DAMAGE_08);
	_fazalDamage.addSprite(eIdSprite::FAZAL_DAMAGE_09);

	_listAnimation[eIdAnimation::FAZAL_DAMAGE] = _fazalDamage;
#pragma endregion

#pragma region GENIE HEAD
	Animation _genieHead;
	_genieHead.setTimePerFrame(0.08f);
	_genieHead.setIsLoop(true);
	_genieHead.setTypeFixPos(eTypeFixPos::L_BT);
	_genieHead.setScale(2.0f, 2.0f);
	_genieHead.addSprite(eIdSprite::GENIES_HEAD_01);

	_listAnimation[eIdAnimation::GENIE_HEAD_VISIBLE] = _genieHead;

	Animation _genieHeadExplode;
	_genieHeadExplode.setTimePerFrame(0.08f);
	_genieHeadExplode.setIsLoop(false);
	_genieHeadExplode.setTypeFixPos(eTypeFixPos::C_C);
	_genieHeadExplode.setScale(2.0f, 2.0f);
	_genieHeadExplode.addSprite(eIdSprite::GENIES_HEAD_02);
	_genieHeadExplode.addSprite(eIdSprite::GENIES_HEAD_03);
	_genieHeadExplode.addSprite(eIdSprite::GENIES_HEAD_04);
	_genieHeadExplode.addSprite(eIdSprite::GENIES_HEAD_EXPLODE_01);
	_genieHeadExplode.addSprite(eIdSprite::GENIES_HEAD_EXPLODE_02);
	_genieHeadExplode.addSprite(eIdSprite::GENIES_HEAD_EXPLODE_03);
	_genieHeadExplode.addSprite(eIdSprite::GENIES_HEAD_EXPLODE_04);
	_genieHeadExplode.addSprite(eIdSprite::GENIES_HEAD_EXPLODE_05);
	_genieHeadExplode.addSprite(eIdSprite::GENIES_HEAD_EXPLODE_06);
	_genieHeadExplode.addSprite(eIdSprite::GENIES_HEAD_EXPLODE_07);
	_genieHeadExplode.addSprite(eIdSprite::GENIES_HEAD_EXPLODE_08);
	_genieHeadExplode.addSprite(eIdSprite::GENIES_HEAD_EXPLODE_09);
	_genieHeadExplode.addSprite(eIdSprite::GENIES_HEAD_EXPLODE_10);
	_genieHeadExplode.addSprite(eIdSprite::GENIES_HEAD_EXPLODE_11);
	_genieHeadExplode.addSprite(eIdSprite::GENIES_HEAD_EXPLODE_12);

	_listAnimation[eIdAnimation::GENIE_HEAD_EXPLODE] = _genieHeadExplode;
#pragma endregion

#pragma region HEATH HUD
	Animation _health01;
	_health01.setTimePerFrame(0.05f);
	_health01.setIsLoop(true);
	_health01.setTypeFixPos(eTypeFixPos::L_BT);
	_health01.addSprite(eIdSprite::HEALTH_01_01);
	_health01.addSprite(eIdSprite::HEALTH_01_02);
	_health01.addSprite(eIdSprite::HEALTH_01_03);
	_health01.addSprite(eIdSprite::HEALTH_01_04);

	_listAnimation[eIdAnimation::HEALTH_01] = _health01;

	Animation _health02;
	_health02.setTimePerFrame(0.05f);
	_health02.setIsLoop(true);
	_health02.setTypeFixPos(eTypeFixPos::L_BT);
	_health02.addSprite(eIdSprite::HEALTH_02_01);
	_health02.addSprite(eIdSprite::HEALTH_02_02);
	_health02.addSprite(eIdSprite::HEALTH_02_03);
	_health02.addSprite(eIdSprite::HEALTH_02_04);

	_listAnimation[eIdAnimation::HEALTH_02] = _health02;

	Animation _health03;
	_health03.setTimePerFrame(0.05f);
	_health03.setIsLoop(true);
	_health03.setTypeFixPos(eTypeFixPos::L_BT);
	_health03.addSprite(eIdSprite::HEALTH_03_01);
	_health03.addSprite(eIdSprite::HEALTH_03_02);
	_health03.addSprite(eIdSprite::HEALTH_03_03);
	_health03.addSprite(eIdSprite::HEALTH_03_04);

	_listAnimation[eIdAnimation::HEALTH_03] = _health03;

	Animation _health04;
	_health04.setTimePerFrame(0.05f);
	_health04.setIsLoop(true);
	_health04.setTypeFixPos(eTypeFixPos::L_BT);
	_health04.addSprite(eIdSprite::HEALTH_04_01);
	_health04.addSprite(eIdSprite::HEALTH_04_02);
	_health04.addSprite(eIdSprite::HEALTH_04_03);
	_health04.addSprite(eIdSprite::HEALTH_04_04);

	_listAnimation[eIdAnimation::HEALTH_04] = _health04;


	Animation _health05;
	_health05.setTimePerFrame(0.05f);
	_health05.setIsLoop(true);
	_health05.setTypeFixPos(eTypeFixPos::L_BT);
	_health05.addSprite(eIdSprite::HEALTH_05_01);
	_health05.addSprite(eIdSprite::HEALTH_05_02);
	_health05.addSprite(eIdSprite::HEALTH_05_03);
	_health05.addSprite(eIdSprite::HEALTH_05_04);

	_listAnimation[eIdAnimation::HEALTH_05] = _health05;

	Animation _health06;
	_health06.setTimePerFrame(0.05f);
	_health06.setIsLoop(true);
	_health06.setTypeFixPos(eTypeFixPos::L_BT);
	_health06.addSprite(eIdSprite::HEALTH_06_01);
	_health06.addSprite(eIdSprite::HEALTH_06_02);
	_health06.addSprite(eIdSprite::HEALTH_06_03);
	_health06.addSprite(eIdSprite::HEALTH_06_04);

	_listAnimation[eIdAnimation::HEALTH_06] = _health06;

	Animation _health07;
	_health07.setTimePerFrame(0.05f);
	_health07.setIsLoop(true);
	_health07.setTypeFixPos(eTypeFixPos::L_BT);
	_health07.addSprite(eIdSprite::HEALTH_07_01);
	_health07.addSprite(eIdSprite::HEALTH_07_02);
	_health07.addSprite(eIdSprite::HEALTH_07_03);
	_health07.addSprite(eIdSprite::HEALTH_07_04);

	_listAnimation[eIdAnimation::HEALTH_07] = _health07;

	Animation _health08;
	_health08.setTimePerFrame(0.05f);
	_health08.setIsLoop(true);
	_health08.setTypeFixPos(eTypeFixPos::L_BT);
	_health08.addSprite(eIdSprite::HEALTH_08_01);
	_health08.addSprite(eIdSprite::HEALTH_08_02);
	_health08.addSprite(eIdSprite::HEALTH_08_03);
	_health08.addSprite(eIdSprite::HEALTH_08_04);

	_listAnimation[eIdAnimation::HEALTH_08] = _health08;

	Animation _health09;
	_health09.setTimePerFrame(0.05f);
	_health09.setIsLoop(true);
	_health09.setTypeFixPos(eTypeFixPos::L_BT);
	_health09.addSprite(eIdSprite::HEALTH_09_01);

	_listAnimation[eIdAnimation::HEALTH_09] = _health09;

#pragma endregion

#pragma region TEXT COLLECTION
	Animation _textCol00;
	_textCol00.setTimePerFrame(1.0f);
	_textCol00.setIsLoop(false);
	_textCol00.addSprite(eIdSprite::TEXT_COL_00);

	_listAnimation[eIdAnimation::TEXT_COLLECTION_00] = _textCol00;

	Animation _textCol01;
	_textCol01.setTimePerFrame(1.0f);
	_textCol01.setIsLoop(false);
	_textCol01.addSprite(eIdSprite::TEXT_COL_01);

	_listAnimation[eIdAnimation::TEXT_COLLECTION_01] = _textCol01;

	Animation _textCol02;
	_textCol02.setTimePerFrame(1.0f);
	_textCol02.setIsLoop(false);
	_textCol02.addSprite(eIdSprite::TEXT_COL_02);

	_listAnimation[eIdAnimation::TEXT_COLLECTION_02] = _textCol02;

	Animation _textCol03;
	_textCol03.setTimePerFrame(1.0f);
	_textCol03.setIsLoop(false);
	_textCol03.addSprite(eIdSprite::TEXT_COL_03);

	_listAnimation[eIdAnimation::TEXT_COLLECTION_03] = _textCol03;

	Animation _textCol04;
	_textCol04.setTimePerFrame(1.0f);
	_textCol04.setIsLoop(false);
	_textCol04.addSprite(eIdSprite::TEXT_COL_04);

	_listAnimation[eIdAnimation::TEXT_COLLECTION_04] = _textCol04;

	Animation _textCol05;
	_textCol05.setTimePerFrame(1.0f);
	_textCol05.setIsLoop(false);
	_textCol05.addSprite(eIdSprite::TEXT_COL_05);

	_listAnimation[eIdAnimation::TEXT_COLLECTION_05] = _textCol05;

	Animation _textCol06;
	_textCol06.setTimePerFrame(1.0f);
	_textCol06.setIsLoop(false);
	_textCol06.addSprite(eIdSprite::TEXT_COL_06);

	_listAnimation[eIdAnimation::TEXT_COLLECTION_06] = _textCol06;

	Animation _textCol07;
	_textCol07.setTimePerFrame(1.0f);
	_textCol07.setIsLoop(false);
	_textCol07.addSprite(eIdSprite::TEXT_COL_07);

	_listAnimation[eIdAnimation::TEXT_COLLECTION_07] = _textCol07;

	Animation _textCol08;
	_textCol08.setTimePerFrame(1.0f);
	_textCol08.setIsLoop(false);
	_textCol08.addSprite(eIdSprite::TEXT_COL_08);

	_listAnimation[eIdAnimation::TEXT_COLLECTION_08] = _textCol08;

	Animation _textCol09;
	_textCol09.setTimePerFrame(1.0f);
	_textCol09.setIsLoop(false);
	_textCol09.addSprite(eIdSprite::TEXT_COL_09);

	_listAnimation[eIdAnimation::TEXT_COLLECTION_09] = _textCol09;
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
