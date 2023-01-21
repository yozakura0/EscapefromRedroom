#include "stdafx.h"
#include "Qtarget.h"
#include "room4.h"
#include "Game.h"

Qtarget::Qtarget()
{
	game = FindGO<Game>("game");

	//進行度に応じて表示切替
	if (game->leveld >= 3 && game->levelb >= 3)
	{
		spriteRender.Init("Assets/sprite/room4-target2.DDS", 1920.0f, 1080.0f);
	}
	else
	{
		spriteRender.Init("Assets/sprite/room4-target.DDS", 1920.0f, 1080.0f);
	}

}

Qtarget::~Qtarget()
{

}

void Qtarget::Update()
{
	game = FindGO<Game>("game");

	//シーンの値によって見る場所を変更
	if (game->sceneD == 0)
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

void Qtarget::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}