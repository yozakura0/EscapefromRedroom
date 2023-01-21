#include "stdafx.h"
#include "Qshelf.h"
#include "room3.h"
#include "Game.h"
#include "Item.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Qshelf::Qshelf()
{
	game = FindGO<Game>("game");
	item = FindGO<Item>("item");

	//進行度に応じて表示切替
	if (game->levelc == 1)
	{
		matti = 1;
	}
	else
	{
		matti = 2;
	}

	if (matti == 2)
	{
		spriteRender.Init("Assets/sprite/room3-tana.DDS", 1920.0f, 1080.0f);
	}
	else
	{
		spriteRender.Init("Assets/sprite/room3-matti.DDS", 1920.0f, 1080.0f);
	}

	g_soundEngine->ResistWaveFileBank(3, "Assets/sound/piko.wav");
}

Qshelf::~Qshelf()
{

}

void Qshelf::Update()
{
	game = FindGO<Game>("game");

	//アイテム回収処理
	if (matti == 0)
	{
		SoundSource* getse = NewGO<SoundSource>(0);
		getse->Init(3);
		getse->Play(false);
		getse->SetVolume(3.5f);

		item->matti = 1;
		spriteRender.Init("Assets/sprite/room3-tana.DDS", 1920.0f, 1080.0f);
		game->levelc = 2;
		matti = 2;
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
	//	DeleteGO(this);
	//}
}

void Qshelf::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}