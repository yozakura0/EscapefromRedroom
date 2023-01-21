#include "stdafx.h"
#include "Qwindow.h"
#include "room1.h"
#include "Game.h"

Qwindow::Qwindow()
{
	spriteRender.Init("Assets/sprite/room 1-window.DDS", 1920.0f, 1080.0f);

	game = FindGO<Game>("game");
}

void Qwindow::Update()
{
	game = FindGO<Game>("game");

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

	spriteRender.Update();
}

void Qwindow::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}