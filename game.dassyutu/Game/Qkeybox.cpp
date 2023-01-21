#include "stdafx.h"
#include "Qkeybox.h"
#include "room3.h"
#include "Game.h"
#include "Item.h"
#include "Qkeyboxdial1.h"
#include "Qkeyboxdial2.h"
#include "Qkeyboxdial3.h"
#include "Qkeyboxdial4.h"
#include "Qkeyboxdial5.h"
#include "Qkeyboxdial6.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Qkeybox::Qkeybox()
{
	game = FindGO<Game>("game");
	item = FindGO<Item>("item");

	if (item->knife != 0)
	{
		knife = 2;
	}
	else
	{
		knife = 1;
	}

	//進行度に応じて表示切替
	if (game->levelc != 0)
	{
		if (game->levelc == 3)
		{
			if (item->knife != 0)
			{
				spriteRender.Init("Assets/sprite/room3 keybox3.DDS", 1920.0f, 1080.0f);
			}
			else
			{
				spriteRender.Init("Assets/sprite/room3 keybox2.DDS", 1920.0f, 1080.0f);
			}
		}
		else
		{
			spriteRender.Init("Assets/sprite/room3 keybox1.DDS", 1920.0f, 1080.0f);
		}
	}

	g_soundEngine->ResistWaveFileBank(6, "Assets/sound/openkey.wav");
	g_soundEngine->ResistWaveFileBank(3, "Assets/sound/piko.wav");
}

Qkeybox::~Qkeybox()
{
	//changeがfalseならリスタート
	if (boxchange == false)
	{
		boxchange = true;
		NewGO<Qkeybox>(0, "qkeybox");
	}
}

void Qkeybox::Update()
{
	game = FindGO<Game>("game");

	//ダイヤル表示処理
	if (game->sceneC == 2 && modedial == false)
	{
		NewGO<Qkeyboxdial1>(1, "qkeyboxdial1");
		NewGO<Qkeyboxdial2>(1, "qkeyboxdial2");
		NewGO<Qkeyboxdial3>(1, "qkeyboxdial3");
		NewGO<Qkeyboxdial4>(1, "qkeyboxdial4");
		NewGO<Qkeyboxdial5>(1, "qkeyboxdial5");
		NewGO<Qkeyboxdial6>(1, "qkeyboxdial6");

		modedial = true;
	}
	else if (game->sceneC == 1)
	{
		modedial = false;
	}

	//ダイアルが全部条件に合ったら
	if (kclearflag[0] == true && kclearflag[1] == true && kclearflag[2] == true
		&& kclearflag[3] == true && kclearflag[4] == true && kclearflag[5] == true)
	{
		SoundSource* keyse = NewGO<SoundSource>(0);
		keyse->Init(6);
		keyse->Play(false);
		keyse->SetVolume(3.5f);

		game->levelc = 3;
		game->sceneC = 1;
		game->openknife = true;

		boxchange = false;
		DeleteGO(this);
	}

	//ナイフ入手処理
	if (knife == 0)
	{
		SoundSource* getse = NewGO<SoundSource>(0);
		getse->Init(3);
		getse->Play(false);
		getse->SetVolume(3.5f);

		item->knife = 1;
		spriteRender.Init("Assets/sprite/room3 keybox3.DDS", 1920.0f, 1080.0f);
		knife = 2;
	}

	//シーンの値によって見る場所を変更
	if (game->sceneC == 0)
	{
		NewGO<room3>(0, "room3");
		DeleteGO(this);
	}
	////再表示されるなら消える
	//if (game->reshow == true || game->reshowing == true)
	//{
	//	game->sceneC = 1;
	//	DeleteGO(this);
	//}
}

void Qkeybox::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}