#include "stdafx.h"
#include "room3.h"
#include "room2.h"
#include "room4.h"
#include "Game.h"
#include "Qkeybox.h"
#include "Qdoor.h"
#include "Qshelf.h"

room3::room3()
{

	game = FindGO<Game>("game");

	//進行度を判定して表示
	switch (game->levelc)
	{
	//0なら不可視
	case 0:
		spriteRender.Init("Assets/sprite/dark.DDS", 1920.0f, 1080.0f);
		break;
	//1ならfirst
	case 1:
		spriteRender.Init("Assets/sprite/room3-first.DDS", 1920.0f, 1080.0f);
		break;
		//2ならsecond
	case 2:
		spriteRender.Init("Assets/sprite/room3-second.DDS", 1920.0f, 1080.0f);
		break;
		//3ならthird
	case 3:
		spriteRender.Init("Assets/sprite/room3-third.DDS", 1920.0f, 1080.0f);
		break;
	default:
		break;
	}

	game->siten = 3;
}

room3::~room3()
{

}

void room3::Update()
{
	game = FindGO<Game>("game");

	if (game->sceneC == 1)//1なら箱表示
	{
		NewGO<Qkeybox>(0, "qkeybox");
		DeleteGO(this);
	}
	if (game->sceneC == 4)//4なら扉表示
	{
		NewGO<Qdoor>(0, "qdoor");
		DeleteGO(this);
	}
	if (game->sceneC == 5)//5なら棚表示
	{
		NewGO<Qshelf>(0, "qshelf");
		DeleteGO(this);
	}

	//左右のボタンが押されたら視点切替
	if (g_pad[0]->IsTrigger(enButtonLeft))
	{
		NewGO<room2>(0, "room2");
		DeleteGO(this);
	}
	if (g_pad[0]->IsTrigger(enButtonRight))
	{
		NewGO<room4>(0, "room4");
		DeleteGO(this);
	}
	////再表示されるなら消える
	//if (game->reshow == true || game->reshowing == true)
	//{
	//	DeleteGO(this);
	//}
}

void room3::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}
