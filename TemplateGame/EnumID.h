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

enum eIdScene
{
	SE_DUNGEON = 1,
	SE_MENU,
	SE_JAFAR,
	SE_DYING,
	SE_COMPLETE,

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

	SELL = (1 << 14),
	PREPARE = (1 << 15),
	BUY = (1 << 16),
	EXPLODE_ = (1 << 17),
	PUSH = (1 << 18)
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
	BONE,
	PEDDLER,
	COIN,
	SAVE_POINT,
	EXTRA_HEALTH,
	EXIT_DOOR,

	// Static Obj => ko render
	GROUND = 4500,	// Dat
	COLUMN,			// Cot go - sat
	PLANKS,			// Thanh go - sat
	ROPE,			// Day thung
	GROUND_FIRE,

	JAFAR = 5000,
	JAFAR_FLAME,
	JAFAR_STAR,

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
	PEDDLER_TEX,
	JAFAR_TEX,
	MENU_TEX,

	SCENE_DUNGEON_TEX = 70,
	SCENE_ABOVE_DUNG_TEX,
	SCENE_BOSS_TEX,
	SCENE_ABOVE_BOSS_TEX,

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
	BAT_FLY_01,
	BAT_FLY_02,
	BAT_FLY_03,
	BAT_FLY_04,
	BAT_FLY_05,
	BAT_FLY_06,
	BAT_FLY_07,

	BAT_ROTATE_01 = 1590,
	BAT_ROTATE_02,
	BAT_ROTATE_03,
	BAT_ROTATE_04,
	BAT_ROTATE_05,
	BAT_ROTATE_06,
	BAT_ROTATE_07,
	BAT_ROTATE_08,
	BAT_ROTATE_09,

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

	NAHBI_ATTACK_01_ = 1590,
	NAHBI_ATTACK_02_,
	NAHBI_ATTACK_03_,
	NAHBI_ATTACK_04_,
	NAHBI_ATTACK_05_,

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

#pragma region  TEXT COLLECTION 1290
	TEXT_COL_00 = 1290,
	TEXT_COL_01,
	TEXT_COL_02,
	TEXT_COL_03,
	TEXT_COL_04,
	TEXT_COL_05,
	TEXT_COL_06,
	TEXT_COL_07,
	TEXT_COL_08,
	TEXT_COL_09,

#pragma endregion

#pragma region BONE 1300
	BONE_01 = 1300,
	BONE_02,
	BONE_03,
	BONE_04,
#pragma endregion

#pragma region PEDDLER 1310 1390
	PEDDLER_PREPARE_01 = 1310,
	PEDDLER_PREPARE_02,
	PEDDLER_PREPARE_03,
	PEDDLER_PREPARE_04,
	PEDDLER_PREPARE_05,
	PEDDLER_PREPARE_06,
	PEDDLER_PREPARE_07,
	PEDDLER_PREPARE_08,
	PEDDLER_PREPARE_09,
	PEDDLER_PREPARE_10,
	PEDDLER_PREPARE_11,
	PEDDLER_PREPARE_12,
	PEDDLER_PREPARE_13,
	PEDDLER_PREPARE_14,
	PEDDLER_PREPARE_15,
	PEDDLER_PREPARE_16,
	PEDDLER_PREPARE_17,
	PEDDLER_PREPARE_18,
	PEDDLER_PREPARE_19,
	PEDDLER_PREPARE_20,
	PEDDLER_PREPARE_21,
	PEDDLER_PREPARE_22,
	PEDDLER_PREPARE_23,
	PEDDLER_PREPARE_24,
	PEDDLER_PREPARE_25,
	PEDDLER_PREPARE_26,
	PEDDLER_PREPARE_27,
	PEDDLER_PREPARE_28,
	PEDDLER_PREPARE_29,
	PEDDLER_PREPARE_30,

	PEDDLER_IDLE_01 = 1340,
	PEDDLER_IDLE_02,
	PEDDLER_IDLE_03,
	PEDDLER_IDLE_04,
	PEDDLER_IDLE_05,
	PEDDLER_IDLE_06,
	PEDDLER_IDLE_07,
	PEDDLER_IDLE_08,
	PEDDLER_IDLE_09,
	PEDDLER_IDLE_10,
	PEDDLER_IDLE_11,
	PEDDLER_IDLE_12,
	PEDDLER_IDLE_13,
	PEDDLER_IDLE_14,
	PEDDLER_IDLE_15,
	PEDDLER_IDLE_16,
	PEDDLER_IDLE_17,
	PEDDLER_IDLE_18,
	PEDDLER_IDLE_19,
	PEDDLER_IDLE_20,
	PEDDLER_IDLE_21,
	PEDDLER_IDLE_22,
	PEDDLER_IDLE_23,
	PEDDLER_IDLE_24,

	PEDDLER_SELL_01 = 1370,
	PEDDLER_SELL_02,
	PEDDLER_SELL_03,
	PEDDLER_SELL_04,
	PEDDLER_SELL_05,
	PEDDLER_SELL_06,
	PEDDLER_SELL_07,
	PEDDLER_SELL_08,
	PEDDLER_SELL_09,
	PEDDLER_SELL_10,
	PEDDLER_SELL_11,
	PEDDLER_SELL_12,
	PEDDLER_SELL_13,
	PEDDLER_SELL_14,
	PEDDLER_SELL_15,
	PEDDLER_SELL_16,
	PEDDLER_SELL_17,
	PEDDLER_SELL_18,
	PEDDLER_SELL_19,
	PEDDLER_SELL_20,
	PEDDLER_SELL_21,
	PEDDLER_SELL_22,
	PEDDLER_SELL_23,
	PEDDLER_SELL_24,

#pragma endregion

#pragma region COIN 1400
	COIN_01 = 1400,
	COIN_02,
	COIN_03,
	COIN_04,
	COIN_05,
	COIN_06,
	COIN_07,
	COIN_08,
	COIN_09,
#pragma endregion

#pragma region LIFE 1410
	LIFE_01 = 1410,
#pragma endregion

#pragma region CHAR 1420 1440
	CHAR_01 = 1420,
	CHAR_02,
	CHAR_03,
	CHAR_04,
	CHAR_05,
	CHAR_06,
	CHAR_07,
	CHAR_08,
	CHAR_09,
	CHAR_10,
	CHAR_11,
	CHAR_12,
	CHAR_13,
	CHAR_14,
	CHAR_15,
	CHAR_16,
	CHAR_17,
	CHAR_18,
	CHAR_19,
	CHAR_20,
	CHAR_21,
	CHAR_22,
	CHAR_23,
	CHAR_24,
	CHAR_25,
	CHAR_26,
	CHAR_27,
#pragma endregion

#pragma region SAVE POINT 1450
	SAVE_POINT_01 = 1450,
	SAVE_POINT_02,
	SAVE_POINT_03,
	SAVE_POINT_04,
	SAVE_POINT_05,
	SAVE_POINT_06,
	SAVE_POINT_07,
	SAVE_POINT_08,
	SAVE_POINT_09,
	SAVE_POINT_10,
#pragma endregion

#pragma region EXTRA HEALTH 1460
	EXTRA_HEALTH_01 = 1460,
	EXTRA_HEALTH_02,
	EXTRA_HEALTH_03,
	EXTRA_HEALTH_04,
	EXTRA_HEALTH_05,
	EXTRA_HEALTH_06,
	EXTRA_HEALTH_07,
	EXTRA_HEALTH_08,
#pragma endregion

#pragma region EXIT DOOR 1470
	EXIT_DOOR_01 = 1470,
#pragma endregion

#pragma region  TEXT SCORE 1480
	TEXT_SCO_00 = 1480,
	TEXT_SCO_01,
	TEXT_SCO_02,
	TEXT_SCO_03,
	TEXT_SCO_04,
	TEXT_SCO_05,
	TEXT_SCO_06,
	TEXT_SCO_07,
	TEXT_SCO_08,
	TEXT_SCO_09,

#pragma endregion

#pragma region  JAFAR 1490
	JAFAR_SLASH_01 = 1490,
	JAFAR_SLASH_02,
	JAFAR_SLASH_03,
	JAFAR_SLASH_04,
	JAFAR_SLASH_05,
	JAFAR_SLASH_06,
	JAFAR_SLASH_07,
	JAFAR_SLASH_08,

	JAFAR_THROW_01 = 1500,
	JAFAR_THROW_02,
	JAFAR_THROW_03,
	JAFAR_THROW_04,
	JAFAR_THROW_05,
	JAFAR_THROW_06,
	JAFAR_THROW_07,
	JAFAR_THROW_08,
	JAFAR_THROW_09,
	JAFAR_THROW_10,
	JAFAR_THROW_11,

	FIRE_THROW_JAFAR_01 = 1520,
	FIRE_THROW_JAFAR_02,
	FIRE_THROW_JAFAR_03,
	FIRE_THROW_JAFAR_04,
	FIRE_THROW_JAFAR_05,
	FIRE_THROW_JAFAR_06,
	FIRE_THROW_JAFAR_07,
	FIRE_THROW_JAFAR_08,

	APPLE_THROW_EXPLODEz_01 = 1530,
	APPLE_THROW_EXPLODEz_02,
	APPLE_THROW_EXPLODEz_03,
	APPLE_THROW_EXPLODEz_04,
	APPLE_THROW_EXPLODEz_05,
	APPLE_THROW_EXPLODEz_06,
	APPLE_THROW_EXPLODEz_07,
	APPLE_THROW_EXPLODEz_08,
	APPLE_THROW_EXPLODEz_09,
	APPLE_THROW_EXPLODEz_10,
	APPLE_THROW_EXPLODEz_11,
	APPLE_THROW_EXPLODEz_12,
	APPLE_THROW_EXPLODEz_13,
	APPLE_THROW_EXPLODEz_14,
	APPLE_THROW_EXPLODEz_15,
	APPLE_THROW_EXPLODEz_16,
	APPLE_THROW_EXPLODEz_17,
	APPLE_THROW_EXPLODEz_18,
	APPLE_THROW_EXPLODEz_19,

	GROUND_FIRE_01 = 1550,
	GROUND_FIRE_02,
	GROUND_FIRE_03,
	GROUND_FIRE_04,
	GROUND_FIRE_05,

	JAFAR_FLAME_01 = 1560,
	JAFAR_FLAME_02,
	JAFAR_FLAME_03,
	JAFAR_FLAME_04,
	JAFAR_FLAME_05,
	JAFAR_FLAME_06,
	JAFAR_FLAME_07,
	JAFAR_FLAME_08,

	JAFAR_STAR_01 = 1570,
	JAFAR_STAR_02,
	JAFAR_STAR_03,

	JAFAR_STAR_EXPLODE_01 = 1580,
	JAFAR_STAR_EXPLODE_02,
	JAFAR_STAR_EXPLODE_03,
	JAFAR_STAR_EXPLODE_04,
	JAFAR_STAR_EXPLODE_05,

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

	ALADDIN_DIE_01 = 2230,
	ALADDIN_DIE_02,
	ALADDIN_DIE_03,
	ALADDIN_DIE_04,
	ALADDIN_DIE_05,
	ALADDIN_DIE_06,
	ALADDIN_DIE_07,
	ALADDIN_DIE_08,
	ALADDIN_DIE_09,

	ALADDIN_MASSAGE_01 = 2240,
	ALADDIN_MASSAGE_02,
	ALADDIN_MASSAGE_03,
	ALADDIN_MASSAGE_04,
	ALADDIN_MASSAGE_05,
	ALADDIN_MASSAGE_06,
	ALADDIN_MASSAGE_07,
	ALADDIN_MASSAGE_08,
	ALADDIN_MASSAGE_09,
	ALADDIN_MASSAGE_10,
	ALADDIN_MASSAGE_11,
	ALADDIN_MASSAGE_12,
	ALADDIN_MASSAGE_13,
	ALADDIN_MASSAGE_14,
	ALADDIN_MASSAGE_15,
	ALADDIN_MASSAGE_16,
	ALADDIN_MASSAGE_17,
	ALADDIN_MASSAGE_18,
	ALADDIN_MASSAGE_19,

	ABU_MASSAGE_01 = 2260,
	ABU_MASSAGE_02,
	ABU_MASSAGE_03,
	ABU_MASSAGE_04,
	ABU_MASSAGE_05,
	ABU_MASSAGE_06,

	ALADDIN_PUSH_01 = 2270,
	ALADDIN_PUSH_02,
	ALADDIN_PUSH_03,
	ALADDIN_PUSH_04,
	ALADDIN_PUSH_05,
	ALADDIN_PUSH_06,
	ALADDIN_PUSH_07,
	ALADDIN_PUSH_08,
	ALADDIN_PUSH_09,
	ALADDIN_PUSH_10,

	ALADDIN_REBORN_01 = 2280,
	ALADDIN_REBORN_02,
	ALADDIN_REBORN_03,
	ALADDIN_REBORN_04,
	ALADDIN_REBORN_05,
	ALADDIN_REBORN_06,
	ALADDIN_REBORN_07,
	ALADDIN_REBORN_08,
	ALADDIN_REBORN_09,
	ALADDIN_REBORN_10,
	ALADDIN_REBORN_11,
	ALADDIN_REBORN_12,
	ALADDIN_REBORN_13,
	ALADDIN_REBORN_14,

	ALADDIN_DANCE_01 = 2300,
	ALADDIN_DANCE_02,
	ALADDIN_DANCE_03,
	ALADDIN_DANCE_04,
	ALADDIN_DANCE_05,
	ALADDIN_DANCE_06,
	ALADDIN_DANCE_07,
	ALADDIN_DANCE_08,
	ALADDIN_DANCE_09,
	ALADDIN_DANCE_10,

	ABU_RUN_01 = 2310,
	ABU_RUN_02,
	ABU_RUN_03,
	ABU_RUN_04,
	ABU_RUN_05,
	ABU_RUN_06,
	ABU_RUN_07,
	ABU_RUN_08,
#pragma endregion

};

// Animation 100 - 1000
enum eIdAnimation
{
	APPLE_VISIBLE = 100,
	APPLE_THROW,
	APPLE_THROW_EXPLODE,
	APPLE_THROW_EXPLODE_,
	ITEM_EXPLODE,

	SKELETON_VISIBLE,
	BAT_VISIBLE,
	BAT_FLY,
	BAT_ROTATE,
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
	ALADDIN_REBORN,
	ALADDIN_DIE,
	ALADDIN_MASSAGE,
	ALADDIN_PUSH,
	ALADDIN_DANCE,
	ABU_MASSAGE,
	ABU_RUN,

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

	APPLE_COLLECTION,
	TEXT_COLLECTION_00,
	TEXT_COLLECTION_01,
	TEXT_COLLECTION_02,
	TEXT_COLLECTION_03,
	TEXT_COLLECTION_04,
	TEXT_COLLECTION_05,
	TEXT_COLLECTION_06,
	TEXT_COLLECTION_07,
	TEXT_COLLECTION_08,
	TEXT_COLLECTION_09,

	TEXT_SCORE_00,
	TEXT_SCORE_01,
	TEXT_SCORE_02,
	TEXT_SCORE_03,
	TEXT_SCORE_04,
	TEXT_SCORE_05,
	TEXT_SCORE_06,
	TEXT_SCORE_07,
	TEXT_SCORE_08,
	TEXT_SCORE_09,

	BONE_VISIBLE,
	PEDDLER_PREPARE,
	PEDDLER_SELL,
	PEDDLER_IDLE,

	COIN_COLLECTION,
	COIN_VISIBLE,

	LIFE_COLLECTION,
	TEXT_PEDDLER_01,
	TEXT_PEDDLER_02,
	TEXT_PEDDLER_03,
	TEXT_PEDDLER_04,
	TEXT_PEDDLER_05,
	TEXT_PEDDLER_06,
	TEXT_PEDDLER_07,
	TEXT_PEDDLER_08,
	TEXT_PEDDLER_09,
	TEXT_PEDDLER_10,
	TEXT_PEDDLER_11,
	TEXT_PEDDLER_12,
	TEXT_PEDDLER_13,
	TEXT_PEDDLER_14,
	TEXT_PEDDLER_15,
	TEXT_PEDDLER_16,
	TEXT_PEDDLER_17,
	TEXT_PEDDLER_18,
	TEXT_PEDDLER_19,
	TEXT_PEDDLER_20,
	TEXT_PEDDLER_21,
	TEXT_PEDDLER_22,
	TEXT_PEDDLER_23,
	TEXT_PEDDLER_24,
	TEXT_PEDDLER_25,
	TEXT_PEDDLER_26,
	TEXT_PEDDLER_27,

	SAVE_POINT_VISIBLE,
	EXTRA_HEALTH_VISIBLE,
	EXIT_DOOR_VISIBLE,

	JAFAR_SLASH,
	JAFAR_THROW,
	JAFAR_FLAME_THROW,
	JAFAR_STAR_THROW,
	JAFAR_STAR_THROW_EXPLODE,
	GROUND_FIRE_VISIBLE,


};