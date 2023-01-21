#include "stdafx.h"
#include "Qice.h"
#include "room1.h"
#include "Game.h"
#include "Item.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Qice::Qice()
{
	game = FindGO<Game>("game");
	item = FindGO<Item>("item");

	//進行度に応じて表示切替
	if (game->levela == 1)
	{
		spriteRender.Init("Assets/sprite/room 1-ice1.DDS", 1920.0f, 1080.0f);
	}
	else if (game->levela > 1)
	{
		spriteRender.Init("Assets/sprite/room 1-ice4.DDS", 1920.0f, 1080.0f);
	}

	g_soundEngine->ResistWaveFileBank(4, "Assets/sound/burnfire.wav");
}

Qice::~Qice()
{

}

void Qice::Update()
{
	game = FindGO<Game>("game");

	if (item->itemselect == 1 && iceselect == true)
	{
		//正解音
		SoundSource* firese = NewGO<SoundSource>(0);
		firese->Init(4);
		firese->Play(false);
		firese->SetVolume(3.5f);


		/*spriteRender.Init("Assets/sprite/room 1-ice2.DDS", 1920.0f, 1080.0f);
		for (int i = 0; i < 60; i++) {};

		spriteRender.Init("Assets/sprite/room 1-ice3.DDS", 1920.0f, 1080.0f);
		for (int i = 0; i < 180; i++) {};*/

		spriteRender.Init("Assets/sprite/room 1-ice4.DDS", 1920.0f, 1080.0f);
		game->levela = 2;
		item->itemselect = 0;
		item->matti = 2;
	}

	//シーンの値によって見る場所を変更
	if (game->sceneA == 0)
	{
		NewGO<room1>(0, "room1");
		DeleteGO(this);
	}
	////再表示されるなら消える
	//if (game->reshow == true || game->reshowing == true)
	//{
	//	DeleteGO(this);
	//}
}

void Qice::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}