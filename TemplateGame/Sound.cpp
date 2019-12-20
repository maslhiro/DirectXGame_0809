

#include "Sound.h"

Sound* Sound::_instance;

Sound* Sound::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new Sound();
	}
	return _instance;
}

void Sound::loadSound(HWND hWnd)
{
	// Khởi tạo CSoundManager.
	DirectSound_Init(hWnd);

	CSound* sound = nullptr;

	// DYING
	//sound = LoadSound("Resources//Sound//Boxing Bell.wav");
	//_listSound[int::S_BOXING_BELL] = sound;

	//sound = LoadSound("Resources//Sound//Abu Waving.wav");
	//_listSound[int::S_ABU_WAVING] = sound;

	////Thay cho phần ném dao
	//sound = LoadSound("Resources//Sound//Body Crunch.wav");
	//_listSound[int::S_BODY_CRUNCH] = sound;

	//// Menu
	//sound = LoadSound("Resources//Sound//Menu Change.wav");
	//_listSound[int::S_MENU_CHANGE] = sound;

	//sound = LoadSound("Resources//Sound//Menu Select.wav");
	//_listSound[int::S_MENU_SELECT] = sound;

	//sound = LoadSound("Resources//Sound//Menu.wav");
	//_listSound[int::S_MENU] = sound;

	//// Level comple
	//sound = LoadSound("Resources//Sound//LevelComplete.wav");
	//_listSound[int::S_LEVELCOMPLETE] = sound;


	////item
	//sound = LoadSound("Resources//Sound//Apple Collect.wav");
	//_listSound[int::S_APPLE_COLLECT] = sound;

	//sound = LoadSound("Resources//Sound//Clay Pot.wav");
	//_listSound[int::S_CLAY_POT] = sound;

	//sound = LoadSound("Resources//Sound//Wow!.wav");
	//_listSound[int::S_WOW] = sound;

	//sound = LoadSound("Resources//Sound//Guard Beckon.wav");
	//_listSound[int::S_GUARD_BECKON] = sound;

	//sound = LoadSound("Resources//Sound//Gem Collect.wav");
	//_listSound[int::S_GEM_COLLECT] = sound;

	//sound = LoadSound("Resources//Sound//Extra Health.wav");
	//_listSound[int::S_EXTRA_HEALTH] = sound;

	////aladin
	//sound = LoadSound("Resources//Sound//Oooh.wav");
	//_listSound[int::S_OOOH] = sound;

	//sound = LoadSound("Resources//Sound//Low Sword.wav");
	//_listSound[int::S_LOW_SWORD] = sound;

	//sound = LoadSound("Resources//Sound//High Sword.wav");
	//_listSound[int::S_HIGH_SWORD] = sound;

	//sound = LoadSound("Resources//Sound//Object Throw.wav");
	//_listSound[int::S_OBJECT_THROW] = sound;


	//sound = LoadSound("Resources//Sound//Aladdin Hurt.wav");
	//_listSound[int::S_ALADDIN_HURT] = sound;

	//sound = LoadSound("Resources//Sound//Outta Apples.wav");
	//_listSound[int::S_OUTTA_APPLES] = sound;

	////enemy
	//sound = LoadSound("Resources//Sound//Cloud Poof.wav");
	//_listSound[int::S_CLOUD_POOF] = sound;

	//sound = LoadSound("Resources//Sound//Aaah.wav");
	//_listSound[int::S_AAAH] = sound;


	//sound = LoadSound("Resources//Sound//Start Gun.wav");
	//_listSound[int::S_START_GUN] = sound;

	////map object
	//sound = LoadSound("Resources//Sound//Camel Spit.wav");
	//_listSound[int::S_CAMEL_SPIT] = sound;

	//sound = LoadSound("Resources//Sound//Apple Splat.wav");
	//_listSound[int::S_APPLE_SPLAT] = sound;

	//sound = LoadSound("Resources//Sound//Sword Ching.wav");
	//_listSound[int::S_SWORD_CHING] = sound;

	//sound = LoadSound("Resources//Sound//Sword Spinning.wav");
	//_listSound[int::S_SWORD_SPINNING] = sound;

	//sound = LoadSound("Resources//Sound//Wall Hit 2.wav");
	//_listSound[int::S_WALL_HIT_2] = sound;

	//sound = LoadSound("Resources//Sound//Spring Doing 1.wav");
	//_listSound[int::S_SPRING_DOING_1] = sound;

	//sound = LoadSound("Resources//Sound//Spring Doing 2.wav");
	//_listSound[int::S_SPRING_DOING_2] = sound;

	//sound = LoadSound("Resources//Sound//Continue Point.wav");
	//_listSound[int::S_CONTINUE_POINT] = sound;

	//sound = LoadSound("Resources//Sound//Aladdin Push.wav");
	//_listSound[int::S_ALADDIN_PUSH] = sound;

	//sound = LoadSound("Resources//Sound//PrinceAli.wav");
	//_listSound[int::S_PRINCEALI] = sound;

	//sound = LoadSound("Resources//Sound//Fire From Coal.wav");
	//_listSound[int::S_FIRE_FROM_COAL] = sound;

	//// peddler
	//sound = LoadSound("Resources//Sound//Flute Pickup.wav");
	//_listSound[int::S_FLUTE_PICKUP] = sound;

	//sound = LoadSound("Resources//Sound//Honk.wav");
	//_listSound[int::S_HONK] = sound;


	////Boss
	sound = LoadSound("Resource//Sound//Boss Tune.wav");
	_listSound[0] = sound;

	/*
	sound = LoadSound("Resources//Sound//Abu Uh - Oh.wav");
	_listSound[int::S_ABU_UH_OH] = sound;

	sound = LoadSound("Resources//Sound//Aladdin Hurt.wav");
	_listSound[int::S_ALADDIN_HURT] = sound;

	sound = LoadSound("Resources//Sound//Aladdin Oof.wav");
	_listSound[int::S_ALADDIN_OOF] = sound;

	sound = LoadSound("Resources//Sound//Aladdin Push.wav");
	_listSound[int::S_ALADDIN_PUSH] = sound;


	sound = LoadSound("Resources//Sound//AladdinOof.wav");
	_listSound[int::S_ALADDINOOF] = sound;

	sound = LoadSound("Resources//Sound//AladdinPush.wav");
	_listSound[int::S_ALADDINPUSH] = sound;

	sound = LoadSound("Resources//Sound//Apple Collect.wav");
	_listSound[int::S_APPLE_COLLECT] = sound;

	sound = LoadSound("Resources//Sound//Apple Slice.wav");
	_listSound[int::S_APPLE_SLICE] = sound;

	sound = LoadSound("Resources//Sound//Apple Splat.wav");
	_listSound[int::S_APPLE_SPLAT] = sound;

	sound = LoadSound("Resources//Sound//AppleCollect.wav");
	_listSound[int::S_APPLECOLLECT] = sound;

	sound = LoadSound("Resources//Sound//AppleSplat.wav");
	_listSound[int::S_APPLESPLAT] = sound;

	sound = LoadSound("Resources//Sound//Balloon Pop.wav");
	_listSound[int::S_BALLOON_POP] = sound;

	sound = LoadSound("Resources//Sound//Bones Tinkle.wav");
	_listSound[int::S_BONES_TINKLE] = sound;

	sound = LoadSound("Resources//Sound//Camel Spit.wav");
	_listSound[int::S_CAMEL_SPIT] = sound;

	sound = LoadSound("Resources//Sound//Canopy Bounce.wav");
	_listSound[int::S_CANOPY_BOUNCE] = sound;

	sound = LoadSound("Resources//Sound//Cash Register.wav");
	_listSound[int::S_CASH_REGISTER] = sound;

	sound = LoadSound("Resources//Sound//Clay Pot.wav");
	_listSound[int::S_CLAY_POT] = sound;

	sound = LoadSound("Resources//Sound//Cloud Poof.wav");
	_listSound[int::S_CLOUD_POOF] = sound;

	sound = LoadSound("Resources//Sound//Coming Out.wav");
	_listSound[int::S_COMING_OUT] = sound;

	sound = LoadSound("Resources//Sound//Continue Point.wav");
	_listSound[int::S_CONTINUE_POINT] = sound;

	sound = LoadSound("Resources//Sound//Earthquake.wav");
	_listSound[int::S_EARTHQUAKE] = sound;

	sound = LoadSound("Resources//Sound//Eeeh.wav");
	_listSound[int::S_EEEH] = sound;

	sound = LoadSound("Resources//Sound//Extra Health.wav");
	_listSound[int::S_EXTRA_HEALTH] = sound;

	sound = LoadSound("Resources//Sound//Fire From Coal.wav");
	_listSound[int::S_FIRE_FROM_COAL] = sound;

	sound = LoadSound("Resources//Sound//Flagpole.wav");
	_listSound[int::S_FLAGPOLE] = sound;

	sound = LoadSound("Resources//Sound//Flamingo Hey 2.wav");
	_listSound[int::S_FLAMINGO_HEY_2] = sound;

	sound = LoadSound("Resources//Sound//Flamingo Hey!.wav");
	_listSound[int::S_FLAMINGO_HEY] = sound;

	sound = LoadSound("Resources//Sound//Flute Pickup.wav");
	_listSound[int::S_FLUTE_PICKUP] = sound;

	sound = LoadSound("Resources//Sound//Gazeem Hit 1.wav");
	_listSound[int::S_GAZEEM_HIT_1] = sound;

	sound = LoadSound("Resources//Sound//Gazeem Hit 2.wav");
	_listSound[int::S_GAZEEM_HIT_2] = sound;

	sound = LoadSound("Resources//Sound//Gem Collect.wav");
	_listSound[int::S_GEM_COLLECT] = sound;

	sound = LoadSound("Resources//Sound//Genie Fumes.wav");
	_listSound[int::S_GENIE_FUMES] = sound;

	sound = LoadSound("Resources//Sound//Geyser.wav");
	_listSound[int::S_GEYSER] = sound;

	sound = LoadSound("Resources//Sound//Guard Beckon.wav");
	_listSound[int::S_GUARD_BECKON] = sound;

	sound = LoadSound("Resources//Sound//Guard Hit 1.wav");
	_listSound[int::S_GUARD_HIT_1] = sound;

	sound = LoadSound("Resources//Sound//Guard Hit 2.wav");
	_listSound[int::S_GUARD_HIT_2] = sound;

	sound = LoadSound("Resources//Sound//GuardBeckon.wav");
	_listSound[int::S_GUARDBECKON] = sound;

	sound = LoadSound("Resources//Sound//GuardHit1.wav");
	_listSound[int::S_GUARDHIT1] = sound;

	sound = LoadSound("Resources//Sound//GuardHit2.wav");
	_listSound[int::S_GUARD_HIT_2] = sound;

	sound = LoadSound("Resources//Sound//Guard's Pants.wav");
	_listSound[int::S_GUARDS_PANTS] = sound;

	sound = LoadSound("Resources//Sound//Head Bop.wav");
	_listSound[int::S_HEAD_BOP] = sound;

	sound = LoadSound("Resources//Sound//High Sword.wav");
	_listSound[int::S_HIGH_SWORD] = sound;

	sound = LoadSound("Resources//Sound//Honk.wav");
	_listSound[int::S_HONK] = sound;

	sound = LoadSound("Resources//Sound//Honky Thing.wav");
	_listSound[int::S_HONKY_THING] = sound;

	sound = LoadSound("Resources//Sound//Iago Squawk.wav");
	_listSound[int::S_IAGO_SQUAWK] = sound;

	sound = LoadSound("Resources//Sound//Iiee.wav");
	_listSound[int::S_IIEE] = sound;

	sound = LoadSound("Resources//Sound//Jafar Laugh.wav");
	_listSound[int::S_JAFAR_LAUGH] = sound;

	sound = LoadSound("Resources//Sound//Jafar Snake.wav");
	_listSound[int::S_JAFAR_SNAKE] = sound;

	sound = LoadSound("Resources//Sound//Jafar Tractor.wav");
	_listSound[int::S_JAFAR_TRACTOR] = sound;

	sound = LoadSound("Resources//Sound//Low Sword.wav");
	_listSound[int::S_LOW_SWORD] = sound;

	sound = LoadSound("Resources//Sound//Object Throw.wav");
	_listSound[int::S_OBJECT_THROW] = sound;

	sound = LoadSound("Resources//Sound//Oooh.wav");
	_listSound[int::S_OOOH] = sound;

	sound = LoadSound("Resources//Sound//Outta Apples.wav");
	_listSound[int::S_OUTTA_APPLES] = sound;

	sound = LoadSound("Resources//Sound//Peddler Shop.wav");
	_listSound[int::S_PEDDLER_SHOP] = sound;

	sound = LoadSound("Resources//Sound//Ping.wav");
	_listSound[int::S_PING] = sound;

	sound = LoadSound("Resources//Sound//Pole Slide.wav");
	_listSound[int::S_POLE_SLIDE] = sound;

	sound = LoadSound("Resources//Sound//PrinceAli.wav");
	_listSound[int::S_PRINCEALI] = sound;

	sound = LoadSound("Resources//Sound//Rock Bounce.wav");
	_listSound[int::S_ROCK_BOUNCE] = sound;

	sound = LoadSound("Resources//Sound//Rope Appear.wav");
	_listSound[int::S_ROPE_APPEAR] = sound;

	sound = LoadSound("Resources//Sound//Rope Launch.wav");
	_listSound[int::S_ROPE_LAUNCH] = sound;

	sound = LoadSound("Resources//Sound//Scarab Pickup.wav");
	_listSound[int::S_SCARAB_PICKUP] = sound;

	sound = LoadSound("Resources//Sound//Scarab Wow.wav");
	_listSound[int::S_SCARAB_WOW] = sound;

	sound = LoadSound("Resources//Sound//Skeleton.wav");
	_listSound[int::S_SKELETON] = sound;

	sound = LoadSound("Resources//Sound//Splash.wav");
	_listSound[int::S_SPLASH] = sound;

	sound = LoadSound("Resources//Sound//Spring Doing 1.wav");
	_listSound[int::S_SPRING_DOING_1] = sound;

	sound = LoadSound("Resources//Sound//Spring Doing 2.wav");
	_listSound[int::S_SPRING_DOING_2] = sound;

	sound = LoadSound("Resources//Sound//Start Gun.wav");
	_listSound[int::S_START_GUN] = sound;

	sound = LoadSound("Resources//Sound//Stone Rumble.wav");
	_listSound[int::S_STONE_RUMBLE] = sound;

	sound = LoadSound("Resources//Sound//Stones Crumble.wav");
	_listSound[int::S_STONES_CRUMBLE] = sound;

	sound = LoadSound("Resources//Sound//Stopping.wav");
	_listSound[int::S_STOPPING] = sound;

	sound = LoadSound("Resources//Sound//Sword Ching.wav");
	_listSound[int::S_SWORD_CHING] = sound;

	sound = LoadSound("Resources//Sound//Sword Spinning.wav");
	_listSound[int::S_SWORD_SPINNING] = sound;

	sound = LoadSound("Resources//Sound//SwordChing.wav");
	_listSound[int::S_SWORDCHING] = sound;

	sound = LoadSound("Resources//Sound//SwordSpinning.wav");
	_listSound[int::S_SWORDSPINNING] = sound;

	sound = LoadSound("Resources//Sound//Tip Toe.wav");
	_listSound[int::S_TIP_TOE] = sound;

	sound = LoadSound("Resources//Sound//Wall Hit 2.wav");
	_listSound[int::S_WALL_HIT_2] = sound;

	sound = LoadSound("Resources//Sound//Wall Spikes.wav");
	_listSound[int::S_WALL_SPIKES] = sound;

	sound = LoadSound("Resources//Sound//Win a Bonus.wav");
	_listSound[int::S_WIN_A_BONUS] = sound;

	sound = LoadSound("Resources//Sound//Wow!.wav");
	_listSound[int::S_WOW] = sound;

	sound = LoadSound("Resources//Sound//Yeah.wav");
	_listSound[int::S_YEAH] = sound;*/
}

bool Sound::IsPlaying(int soundid)
{
	auto sound = _listSound[soundid];
	if (sound != nullptr)
	{
		return sound->IsSoundPlaying();
	}
	return false;
}

void Sound::setVolume(int vol)
{
	_volume = vol;
}

void Sound::setMute(bool mute)
{
	_mute = mute;
}

bool Sound::getMute()
{
	return _mute;
}

void Sound::Play(int soundid)
{
	auto sound = _listSound[soundid];
	if (sound != nullptr && _mute == false)
	{
		PlaySound(sound, _volume);
	}
}
void Sound::PlayNew(int soundid)
{
	auto sound = _listSound[soundid];
	if (sound != nullptr && _mute == false)
	{
		auto newSound = new CSound(*sound);
		PlaySound(newSound);
	}
}
void Sound::PlayLoop(int soundid)
{
	auto sound = _listSound[soundid];
	if (sound != nullptr)
	{
		sound->Play(0, DSBPLAY_LOOPING);
	}
}
void Sound::Stop(int soundid)
{
	auto sound = _listSound[soundid];
	if (sound != nullptr && _mute == false)
	{
		StopSound(sound);
	}
}

void Sound::StopAll()
{
	for (auto sound : _listSound)
	{
		if (sound.second->IsSoundPlaying())
		{
			this->Stop(sound.first);
		}
	}
}

Sound::Sound()
{
	_mute = false;
	_volume = 5;
}

Sound::~Sound()
{
}