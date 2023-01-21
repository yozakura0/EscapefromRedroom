#include "stdafx.h"
#include "sousa3.h"
#include "Game.h"

sousa3::sousa3()
{
	spriteRender.Init("Assets/sprite/sousa3.DDS", 1920.0f, 1080.0f);
}

sousa3::~sousa3()
{

}

void sousa3::Update()
{
	if (game == NULL)
	{
		game = FindGO<Game>("game");
	}

	//gemeがNULLならgameの起動
	if (game == NULL && g_pad[0]->IsTrigger(enButtonA))
	{
		NewGO<Game>(0, "game");
		DeleteGO(this);
	}
	//gameがNULLじゃないならリスタートオン
	else if (game != NULL && g_pad[0]->IsTrigger(enButtonA))
	{
		game->restart = true;
		DeleteGO(this);
	}
}

void sousa3::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}