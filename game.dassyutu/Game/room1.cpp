#include "stdafx.h"
#include "room1.h"
#include "room2.h"
#include "room4.h"
#include "Game.h"
#include "Qwindow.h"
#include "Qice.h"
#include "Qbutton.h"

room1::room1()
{

	game = FindGO<Game>("game");

	//進行度を判定して表示
	switch (game->levela)
	{
	//0ならfirst
	case 0:
		spriteRender.Init("Assets/sprite/room 1-first.DDS", 1920.0f, 1080.0f);
		break;
	//1ならsecond
	case 1:
		spriteRender.Init("Assets/sprite/room 1-second.DDS", 1920.0f, 1080.0f);
		break;
	//2ならthird
	case 2:
		spriteRender.Init("Assets/sprite/room 1-third.DDS", 1920.0f, 1080.0f);
		break;
	default:
		break;
	}

	game->siten = 1;
}

room1::~room1()
{

}

void room1::Update()
{
	game = FindGO<Game>("game");
	////再表示されるなら消える
	//if (game->reshow == true || game->reshowing == true)
	//{
	//	DeleteGO(this);
	//}

	if (game->sceneA == 1 && game->levela == 0)//1かつ暗いなら窓表示
	{
		NewGO<Qwindow>(0, "qwindow");
		DeleteGO(this);
	}
	if (game->sceneA == 2 && game->levela == 0)//2かつ暗いならボタン表示
	{
		NewGO<Qbutton>(0, "qbutton");
		DeleteGO(this);
	}
	if (game->sceneA == 3)//3なら氷表示
	{
		NewGO<Qice>(0, "qice");
		DeleteGO(this);
	}

	//左右のボタンが押されたら視点切替
	if (g_pad[0]->IsTrigger(enButtonLeft))
	{
		NewGO<room4>(0, "room4");
		DeleteGO(this);
	}
	if (g_pad[0]->IsTrigger(enButtonRight))
	{
		NewGO<room2>(0, "room2");
		DeleteGO(this);
	}
	
}

void room1::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}