#include "stdafx.h"
#include "room2.h"
#include "room1.h"
#include "room3.h"
#include "Game.h"
#include "Qbookshelf.h"
#include "Qmoon.h"
#include "Qclock.h"

room2::room2()
{
	game = FindGO<Game>("game");
	

	//進行度を判定して表示
	switch (game->levelb)
	{
	//0なら不可視
	case 0:
		spriteRender.Init("Assets/sprite/dark.DDS", 1920.0f, 1080.0f);
		break;
	//1ならfirst
	case 1:
		spriteRender.Init("Assets/sprite/room 2-first.DDS", 1920.0f, 1080.0f);
		break;
		//2ならsecond
	case 2:
		spriteRender.Init("Assets/sprite/room 2-second.DDS", 1920.0f, 1080.0f);
		break;
		//3ならthird
	case 3:
		spriteRender.Init("Assets/sprite/room 2-third.DDS", 1920.0f, 1080.0f);
		break;
		//4ならfourth
	case 4:
		spriteRender.Init("Assets/sprite/room2-fourth.DDS", 1920.0f, 1080.0f);
	default:
		break;
	}

	
	game->siten = 2;
}

room2::~room2()
{

}

void room2::Update()
{
	game = FindGO<Game>("game");

	if (game->levelb != 0 && game->sceneB == 1 
		|| game->sceneB == 2 || game->sceneB == 4)//未回答かつ1か本棚関連なら本棚表示
	{
		NewGO<Qbookshelf>(0, "qbookshelf");
		DeleteGO(this);
	}
	if (game->levelb != 0 && game->levelb < 3 && game->sceneB == 6)//未回答かつ6なら時計表示
	{
		NewGO<Qclock>(0, "qclock");
		DeleteGO(this);
	}
	if (game->sceneB == 7)//7なら絵画表示
	{
		NewGO<Qmoon>(0, "qmoon");
		DeleteGO(this);
	}

	//左右のボタンが押されたら視点切替
	if (g_pad[0]->IsTrigger(enButtonLeft))
	{
		NewGO<room1>(0, "room1");
		DeleteGO(this);
	}
	if (g_pad[0]->IsTrigger(enButtonRight))
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

void room2::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}
