#include "stdafx.h"
#include "hint.h"
#include "Game.h"

hint::hint()
{
	game = FindGO<Game>("game");
	
	//ゲームの進行度に応じてヒント切り替え
	switch (game->levelb)
	{
	case 0:
		//ヒント1
		spriteRender.Init("Assets/sprite/hint1.DDS", 1920.0f, 1080.0f);
		break;
	case 1:
		if (game->levela < 2)
		{
			//ヒント2
			spriteRender.Init("Assets/sprite/hint2.DDS", 1920.0f, 1080.0f);
		}
		else if (game->levelc < 3)
		{
			//ヒント3
			spriteRender.Init("Assets/sprite/hint3.DDS", 1920.0f, 1080.0f);
		}
		else if (game->leveld < 2)
		{
			//ヒント4
			spriteRender.Init("Assets/sprite/hint4.DDS", 1920.0f, 1080.0f);
		}
		else
		{
			//ヒント5
			spriteRender.Init("Assets/sprite/hint5.DDS", 1920.0f, 1080.0f);
		}
		break;
	case 2:
		//ヒント6
		spriteRender.Init("Assets/sprite/hint6.DDS", 1920.0f, 1080.0f);
		break;
	case 3:
		if (game->levelc < 3)
		{
			//ヒント3
			spriteRender.Init("Assets/sprite/hint3.DDS", 1920.0f, 1080.0f);
		}
		else if (game->leveld < 2)
		{
			//ヒント4
			spriteRender.Init("Assets/sprite/hint4.DDS", 1920.0f, 1080.0f);
		}
		else if (game->leveld < 4)
		{
			//ヒント7
			spriteRender.Init("Assets/sprite/hint7.DDS", 1920.0f, 1080.0f);
		}
		else
		{
			//ヒント8
			spriteRender.Init("Assets/sprite/hint8.DDS", 1920.0f, 1080.0f);
		}
		break;
	case 4:
		//ヒント9
		spriteRender.Init("Assets/sprite/hint9.DDS", 1920.0f, 1080.0f);
		break;
	}
}

hint::~hint()
{

}

void hint::Update()
{
	game = FindGO<Game>("game");

	//ヒント画面を閉じる
	if (game->givehint == false)
	{
		DeleteGO(this);
	}
}

void hint::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}