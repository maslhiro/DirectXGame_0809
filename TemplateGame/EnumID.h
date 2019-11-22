// State bit
enum eIdState
{
	NONE = 0,
	STANDING = 2,
	RUNNING = 4,
	JUMPING = 6,
	EXPLODING = 8,
	DAMAGE = 10,
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

	// Static Obj => ko render
	GROUND = 4500,	// Dat
	PILLAR,			// Cot go - sat
	PLANKS,			// Thanh go - sat
	ROPE,			// Day thung

	ALADIN = 6000,
};

// Texture < 100
enum eIdTexture
{
	BOX_RED_TEX,
	BOX_GRAY_TEX,
	BOX_GREEN_TEX,

	ALADIN_TEX,
	ITEM_TEX,
	ITEM_MAP_TEX,

	SCENE_TEX = 70,

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

#pragma region ALADIN

	ALADIN_IDLE_01 = 2000,
	ALADIN_IDLE_02,
	ALADIN_IDLE_03,
	ALADIN_IDLE_04,
	ALADIN_IDLE_05,
	ALADIN_IDLE_06,
	ALADIN_IDLE_07,
	ALADIN_IDLE_08,

	ALADIN_STAND = 2010,

	ALADIN_JUMP_01 = 2020,
	ALADIN_JUMP_02,
	ALADIN_JUMP_03,
	ALADIN_JUMP_04,
	ALADIN_JUMP_05,
	ALADIN_JUMP_06,
	ALADIN_JUMP_07,
	ALADIN_JUMP_08,
	ALADIN_JUMP_09,
	ALADIN_JUMP_10,
	ALADIN_JUMP_11,
	ALADIN_JUMP_12,
	ALADIN_JUMP_13,

	ALADIN_RUN_01 = 2040,
	ALADIN_RUN_02,
	ALADIN_RUN_03,
	ALADIN_RUN_04,
	ALADIN_RUN_05,
	ALADIN_RUN_06,
	ALADIN_RUN_07,
	ALADIN_RUN_08,
	ALADIN_RUN_09,
	ALADIN_RUN_10,
	ALADIN_RUN_11,
	ALADIN_RUN_12,
	ALADIN_RUN_13,

	ALADIN_DAMAGE_01 = 2060,
	ALADIN_DAMAGE_02,
	ALADIN_DAMAGE_03,
	ALADIN_DAMAGE_04,
	ALADIN_DAMAGE_05,
	ALADIN_DAMAGE_06,

#pragma endregion

};

// Animation 100 - 1000
enum eIdAnimation
{
	APPLE_VISIBLE = 100,
	APPLE_EXPLODE,

	ROCK_VISIBLE,

	WRECKING_BALL_VISIBLE,

	STONE_COLUMN_01_VISIBLE,
	STONE_COLUMN_02_VISIBLE,
	STONE_COLUMN_03_VISIBLE,
	STONE_COLUMN_04_VISIBLE,

	ALADIN_STANDING = 200,
	ALADIN_JUMPING,
	ALADIN_RUNNING,
	ALADIN_DAMAGE,
	ALADIN_IDLING_01,
	ALADIN_IDLING_02
};