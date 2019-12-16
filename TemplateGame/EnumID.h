enum eDirection
{
	LEFT = 1,
	TOP,
	RIGHT,
	BOTTOM
};

enum eTypeFixPos
{
	L_BT = 1,
	L_T,
	C_C,
	C_BT,
	R_BT

};


// State bit
enum eIdState
{
	NONE = 0,
	STAND = (1 << 1),
	RUN = (1 << 2),
	JUMP = (1 << 3),
	EXPLODE = (1 << 4),
	ATTACK = (1 << 5),
	WAIT_01 = (1 << 6),
	WAIT_02 = (1 << 7),
	DAMAGE = (1 << 8),
	THROW = (1 << 9),
	SIT = (1 << 10),
	SIT_ = (1 << 11),
	CLIMB = (1 << 12),
	FALL = (1 << 13),
};

// Object >= 4000
enum eIdObject
{
	APPLE = 4000,
	WRECKING_BALL,

	STONE_COLUMN_1,	// Cot da player co the di xuyen qua
	STONE_COLUMN_2,
	STONE_COLUMN_3,
	STONE_COLUMN_4,

	ROCK,
	SPIKE,
	BAT,
	SKELETON,
	NAHBI,
	FAZAL,
	GENIE_HEAD,

	// Static Obj => ko render
	GROUND = 4500,	// Dat
	COLUMN,			// Cot go - sat
	PLANKS,			// Thanh go - sat
	ROPE,			// Day thung

	ALADDIN = 6000,
};

// Texture < 100
enum eIdTexture
{
	BOX_RED_TEX,
	BOX_GRAY_TEX,
	BOX_GREEN_TEX,

	ALADDIN_TEX,
	ITEM_TEX,
	ITEM_MAP_TEX,
	BAT_TEX,
	SKELETON_TEX,
	GUARDS_TEX,

	SCENE_DUNGEON_TEX = 70,
	SCENE_ABOVE_TEX
};

//Sprite > 1000
enum eIdSprite
{
#pragma region APPLE || 1000
	ITEM_APPLE_BIG = 1000,
	ITEM_APPLE,
#pragma endregion

#pragma region WECKING BALL || 1010
	WRECKING_BALL_01 = 1010,
	WRECKING_BALL_02,
	WRECKING_BALL_03,
	WRECKING_BALL_04,
	WRECKING_BALL_05,
	WRECKING_BALL_06,
	WRECKING_BALL_07,
	WRECKING_BALL_08,
	WRECKING_BALL_09,
	WRECKING_BALL_10,
	WRECKING_BALL_11,
	WRECKING_BALL_12,
	WRECKING_BALL_13,
	WRECKING_BALL_14,
	WRECKING_BALL_15,
#pragma endregion

#pragma region STONE COLUMN || 1030

	STONE_COLUMN_01 = 1030,
	STONE_COLUMN_02,
	STONE_COLUMN_03,
	STONE_COLUMN_04,

#pragma endregion

#pragma region APPLE EXPLODE || 1040
	APPLE_EXPLODE_01 = 1040,
	APPLE_EXPLODE_02,
	APPLE_EXPLODE_03,
	APPLE_EXPLODE_04,
	APPLE_EXPLODE_05,
	APPLE_EXPLODE_06,
	APPLE_EXPLODE_07,
	APPLE_EXPLODE_08,
	APPLE_EXPLODE_09,
#pragma endregion

#pragma region ROCK || 1050
	ROCK_01 = 1050,
	ROCK_02,
	ROCK_03,
	ROCK_04,
	ROCK_05,
#pragma endregion

#pragma region SPIKE || 1060
	SPIKE_01 = 1060,
	SPIKE_02,
	SPIKE_03,
	SPIKE_04,
	SPIKE_05,
	SPIKE_06,
#pragma endregion

#pragma region APPLE THROW || 1070
	APPLE_THROW_01 = 1070,
	APPLE_THROW_02,
	APPLE_THROW_03,
	APPLE_THROW_04,
#pragma endregion

#pragma region APPLE THROW EXPLODE || 1080
	APPLE_THROW_EXPLODE_01 = 1080,
	APPLE_THROW_EXPLODE_02,
	APPLE_THROW_EXPLODE_03,
	APPLE_THROW_EXPLODE_04,
	APPLE_THROW_EXPLODE_05,
#pragma endregion

#pragma region SKELETON || 1090
	SKELETON_01 = 1090,
	SKELETON_02,
	SKELETON_03,
	SKELETON_04,
	SKELETON_05,
	SKELETON_06,
	SKELETON_07,
	SKELETON_08,
	SKELETON_09,
	SKELETON_10,
	SKELETON_11,
	SKELETON_12,
	SKELETON_13,
	SKELETON_14,
	SKELETON_15,
	SKELETON_16,
	SKELETON_17,
	SKELETON_18,
	SKELETON_19,
	SKELETON_20,
	SKELETON_21,
#pragma endregion

#pragma region BAT || 1120
	BAT_01 = 1120,
	BAT_02,
	BAT_03,
	BAT_04,
	BAT_05,
	BAT_06,
	BAT_07,
	BAT_08,
	BAT_09,
	BAT_10,
	BAT_11,
#pragma endregion

#pragma region NAHBI || 1140 1160
	NAHBI_STAND_01 = 1140,
	NAHBI_STAND_02,
	NAHBI_STAND_03,
	NAHBI_STAND_04,
	NAHBI_STAND_05,
	NAHBI_STAND_06,

	NAHBI_RUN_01 = 1150,
	NAHBI_RUN_02,
	NAHBI_RUN_03,
	NAHBI_RUN_04,
	NAHBI_RUN_05,
	NAHBI_RUN_06,
	NAHBI_RUN_07,
	NAHBI_RUN_08,

	NAHBI_ATTACK_01 = 1160,
	NAHBI_ATTACK_02,
	NAHBI_ATTACK_03,
	NAHBI_ATTACK_04,
	NAHBI_ATTACK_05,
	NAHBI_ATTACK_06,

	NAHBI_DAMAGE_01 = 1210,
	NAHBI_DAMAGE_02,
	NAHBI_DAMAGE_03,
	NAHBI_DAMAGE_04,
	NAHBI_DAMAGE_05,
	NAHBI_DAMAGE_06,
#pragma endregion

#pragma region ENERMY EXPLODE || 1170
	EMERMY_EXPLODE_01 = 1170,
	EMERMY_EXPLODE_02,
	EMERMY_EXPLODE_03,
	EMERMY_EXPLODE_04,
	EMERMY_EXPLODE_05,
	EMERMY_EXPLODE_06,
	EMERMY_EXPLODE_07,
	EMERMY_EXPLODE_08,
	EMERMY_EXPLODE_09,
	EMERMY_EXPLODE_10,
#pragma endregion

#pragma region FAZAL || 1180 - 1200
	FAZAL_STAND_01 = 1180,
	FAZAL_STAND_02,
	FAZAL_STAND_03,
	FAZAL_STAND_04,
	FAZAL_STAND_05,
	FAZAL_STAND_06,

	FAZAL_ATTACK_01 = 1190,
	FAZAL_ATTACK_02,
	FAZAL_ATTACK_03,
	FAZAL_ATTACK_04,
	FAZAL_ATTACK_05,
	FAZAL_ATTACK_06,

	FAZAL_DAMAGE_01 = 1200,
	FAZAL_DAMAGE_02,
	FAZAL_DAMAGE_03,
	FAZAL_DAMAGE_04,
	FAZAL_DAMAGE_05,
	FAZAL_DAMAGE_06,
	FAZAL_DAMAGE_07,
	FAZAL_DAMAGE_08,
	FAZAL_DAMAGE_09,

#pragma endregion

#pragma region GENIES HEAD|| 1220 1240
	GENIES_HEAD_01 = 1220,
	GENIES_HEAD_02,
	GENIES_HEAD_03,
	GENIES_HEAD_04,

	GENIES_HEAD_EXPLODE_01 = 1230,
	GENIES_HEAD_EXPLODE_02,
	GENIES_HEAD_EXPLODE_03,
	GENIES_HEAD_EXPLODE_04,
	GENIES_HEAD_EXPLODE_05,
	GENIES_HEAD_EXPLODE_06,
	GENIES_HEAD_EXPLODE_07,
	GENIES_HEAD_EXPLODE_08,
	GENIES_HEAD_EXPLODE_09,
	GENIES_HEAD_EXPLODE_10,
	GENIES_HEAD_EXPLODE_11,
	GENIES_HEAD_EXPLODE_12,
#pragma endregion

#pragma region HEALTH 1250 1280

	HEALTH_01_01 = 1250,
	HEALTH_01_02,
	HEALTH_01_03,
	HEALTH_01_04,

	HEALTH_02_01,
	HEALTH_02_02,
	HEALTH_02_03,
	HEALTH_02_04,

	HEALTH_03_01,
	HEALTH_03_02,
	HEALTH_03_03,
	HEALTH_03_04,

	HEALTH_04_01,
	HEALTH_04_02,
	HEALTH_04_03,
	HEALTH_04_04,

	HEALTH_05_01,
	HEALTH_05_02,
	HEALTH_05_03,
	HEALTH_05_04,

	HEALTH_06_01,
	HEALTH_06_02,
	HEALTH_06_03,
	HEALTH_06_04,

	HEALTH_07_01,
	HEALTH_07_02,
	HEALTH_07_03,
	HEALTH_07_04,

	HEALTH_08_01,
	HEALTH_08_02,
	HEALTH_08_03,
	HEALTH_08_04,

	HEALTH_09_01,
#pragma endregion

#pragma region ALADDIN || 2000

	ALADDIN_IDLE_1_01 = 2000,
	ALADDIN_IDLE_1_02,
	ALADDIN_IDLE_1_03,
	ALADDIN_IDLE_1_04,
	ALADDIN_IDLE_1_05,
	ALADDIN_IDLE_1_06,
	ALADDIN_IDLE_1_07,
	ALADDIN_IDLE_1_08,

	ALADDIN_STAND_01 = 2010,

	ALADDIN_JUMP_01 = 2020,
	ALADDIN_JUMP_02,
	ALADDIN_JUMP_03,
	ALADDIN_JUMP_04,
	ALADDIN_JUMP_05,
	ALADDIN_JUMP_06,
	ALADDIN_JUMP_07,
	ALADDIN_JUMP_08,
	ALADDIN_JUMP_09,
	ALADDIN_JUMP_10,
	ALADDIN_JUMP_11,
	ALADDIN_JUMP_12,
	ALADDIN_JUMP_13,

	ALADDIN_RUN_01 = 2040,
	ALADDIN_RUN_02,
	ALADDIN_RUN_03,
	ALADDIN_RUN_04,
	ALADDIN_RUN_05,
	ALADDIN_RUN_06,
	ALADDIN_RUN_07,
	ALADDIN_RUN_08,
	ALADDIN_RUN_09,
	ALADDIN_RUN_10,
	ALADDIN_RUN_11,
	ALADDIN_RUN_12,
	ALADDIN_RUN_13,

	ALADDIN_DAMAGE_01 = 2060,
	ALADDIN_DAMAGE_02,
	ALADDIN_DAMAGE_03,
	ALADDIN_DAMAGE_04,
	ALADDIN_DAMAGE_05,
	ALADDIN_DAMAGE_06,

	ALADDIN_RUN_JUMP_01 = 2070,
	ALADDIN_RUN_JUMP_02,
	ALADDIN_RUN_JUMP_03,
	ALADDIN_RUN_JUMP_04,
	ALADDIN_RUN_JUMP_05,
	ALADDIN_RUN_JUMP_06,
	ALADDIN_RUN_JUMP_07,

	ALADDIN_IDLE_2_01 = 2080,
	ALADDIN_IDLE_2_02,
	ALADDIN_IDLE_2_03,
	ALADDIN_IDLE_2_04,
	ALADDIN_IDLE_2_05,
	ALADDIN_IDLE_2_06,
	ALADDIN_IDLE_2_07,
	ALADDIN_IDLE_2_08,
	ALADDIN_IDLE_2_09,
	ALADDIN_IDLE_2_10,
	ALADDIN_IDLE_2_11,
	ALADDIN_IDLE_2_12,
	ALADDIN_IDLE_2_13,
	ALADDIN_IDLE_2_14,
	ALADDIN_IDLE_2_15,
	ALADDIN_IDLE_2_16,
	ALADDIN_IDLE_2_17,
	ALADDIN_IDLE_2_18,

	ALADDIN_IDLE_2_19,
	ALADDIN_IDLE_2_20,
	ALADDIN_IDLE_2_21,
	ALADDIN_IDLE_2_22,
	ALADDIN_IDLE_2_23,
	ALADDIN_IDLE_2_24,
	ALADDIN_IDLE_2_25,
	ALADDIN_IDLE_2_26,
	ALADDIN_IDLE_2_27,
	ALADDIN_IDLE_2_28,
	ALADDIN_IDLE_2_29,
	ALADDIN_IDLE_2_30,
	ALADDIN_IDLE_2_31,
	ALADDIN_IDLE_2_32,
	ALADDIN_IDLE_2_33,
	ALADDIN_IDLE_2_34,
	ALADDIN_IDLE_2_35,
	ALADDIN_IDLE_2_36,

	ALADDIN_ATTACK_01 = 2120,
	ALADDIN_ATTACK_02,
	ALADDIN_ATTACK_03,
	ALADDIN_ATTACK_04,
	ALADDIN_ATTACK_05,

	ALADDIN_JUMP_ATTACK_01 = 2130,
	ALADDIN_JUMP_ATTACK_02,
	ALADDIN_JUMP_ATTACK_03,
	ALADDIN_JUMP_ATTACK_04,
	ALADDIN_JUMP_ATTACK_05,
	ALADDIN_JUMP_ATTACK_06,
	ALADDIN_JUMP_ATTACK_07,

	ALADDIN_RUN_ATTACK_01 = 2140,
	ALADDIN_RUN_ATTACK_02,
	ALADDIN_RUN_ATTACK_03,
	ALADDIN_RUN_ATTACK_04,
	ALADDIN_RUN_ATTACK_05,
	ALADDIN_RUN_ATTACK_06,

	ALADDIN_SIT_01 = 2150,
	ALADDIN_SIT_02,
	ALADDIN_SIT_03,
	ALADDIN_SIT_04,

	ALADDIN_SIT_ATTACK_01 = 2160,
	ALADDIN_SIT_ATTACK_02,
	ALADDIN_SIT_ATTACK_03,
	ALADDIN_SIT_ATTACK_04,
	ALADDIN_SIT_ATTACK_05,

	ALADDIN_THROW_01 = 2170,
	ALADDIN_THROW_02,
	ALADDIN_THROW_03,
	ALADDIN_THROW_04,
	ALADDIN_THROW_05,
	ALADDIN_THROW_06,
	ALADDIN_THROW_07,

	ALADDIN_SIT_THROW_01 = 2180,
	ALADDIN_SIT_THROW_02,
	ALADDIN_SIT_THROW_03,
	ALADDIN_SIT_THROW_04,
	ALADDIN_SIT_THROW_05,

	ALADDIN_JUMP_THROW_01 = 2190,
	ALADDIN_JUMP_THROW_02,
	ALADDIN_JUMP_THROW_03,
	ALADDIN_JUMP_THROW_04,
	ALADDIN_JUMP_THROW_05,
	ALADDIN_JUMP_THROW_06,
	ALADDIN_JUMP_THROW_07,
	ALADDIN_JUMP_THROW_08,

	ALADDIN_CLIMB_01 = 2200,
	ALADDIN_CLIMB_02,
	ALADDIN_CLIMB_03,
	ALADDIN_CLIMB_04,
	ALADDIN_CLIMB_05,
	ALADDIN_CLIMB_06,
	ALADDIN_CLIMB_07,
	ALADDIN_CLIMB_08,
	ALADDIN_CLIMB_09,
	ALADDIN_CLIMB_10,
	ALADDIN_CLIMB_11,
	ALADDIN_CLIMB_12,
	ALADDIN_CLIMB_13,
	ALADDIN_CLIMB_14,

	ALADDIN_CLIMB_JUMP_01 = 2220,
	ALADDIN_CLIMB_JUMP_02,
	ALADDIN_CLIMB_JUMP_03,
	ALADDIN_CLIMB_JUMP_04,
	ALADDIN_CLIMB_JUMP_05,
	ALADDIN_CLIMB_JUMP_06,
	ALADDIN_CLIMB_JUMP_07,
	ALADDIN_CLIMB_JUMP_08,
	ALADDIN_CLIMB_JUMP_09,
#pragma endregion

};

// Animation 100 - 1000
enum eIdAnimation
{
	APPLE_VISIBLE = 100,
	APPLE_THROW,
	APPLE_THROW_EXPLODE,
	APPLE_EXPLODE,

	SKELETON_VISIBLE,
	BAT_VISIBLE,
	ROCK_VISIBLE,
	SPIKE_VISIBLE,

	WRECKING_BALL_VISIBLE,

	STONE_COLUMN_01_VISIBLE,
	STONE_COLUMN_02_VISIBLE,
	STONE_COLUMN_03_VISIBLE,
	STONE_COLUMN_04_VISIBLE,

	ALADDIN_STAND = 200,
	ALADDIN_JUMP,
	ALADDIN_FALL,
	ALADDIN_SIT,
	ALADDIN_SIT_,
	ALADDIN_THROW,
	ALADDIN_CLIMB_JUMP,
	ALADDIN_CLIMB,
	ALADDIN_ATTACK,
	ALADDIN_RUN,
	ALADDIN_DAMAGE,
	ALADDIN_IDLE_01,
	ALADDIN_IDLE_02,
	ALADDIN_RUN_JUMP,
	ALADDIN_JUMP_ATTACK,
	ALADDIN_JUMP_THROW,
	ALADDIN_RUN_ATTACK,
	ALADDIN_SIT_ATTACK,
	ALADDIN_SIT_THROW,

	NAHBI_STAND,
	NAHBI_WAIT,
	NAHBI_RUN,
	NAHBI_ATTACK,
	ENERMY_EXPLODE,

	NAHBI_DAMAGE,
	FAZAL_STAND,
	FAZAL_ATTACK,
	FAZAL_DAMAGE,

	GENIE_HEAD_VISIBLE,
	GENIE_HEAD_EXPLODE,

	HEALTH_01,
	HEALTH_02,
	HEALTH_03,
	HEALTH_04,
	HEALTH_05,
	HEALTH_06,
	HEALTH_07,
	HEALTH_08,
	HEALTH_09,
};