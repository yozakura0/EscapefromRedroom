#include "stdafx.h"
#include "hint.h"
#include "Game.h"

hint::hint()
{
	game = FindGO<Game>("game");
	
	//ƒQ[ƒ€‚Ìis“x‚É‰ž‚¶‚Äƒqƒ“ƒgØ‚è‘Ö‚¦
	switch (game->levelb)
	{
	case 0:
		spriteRender.Init("Assets/sprite/hint1.DDS", 1920.0f, 1080.0f);
		break;
	case 1:
		if (game->levela < 2)
		{
			spriteRender.Init("Assets/sprite/hint2.DDS", 1920.0f, 1080.0f);
		}
		else if (game->levelc < 3)
		{
			spriteRender.Init("Assets/sprite/hint3.DDS", 1920.0f, 1080.0f);
		}
		else if (game->leveld < 2)
		{
			spriteRender.Init("Assets/sprite/hint4.DDS", 1920.0f, 1080.0f);
		}
		else
		{
			spriteRender.Init("Assets/sprite/hint5.DDS", 1920.0f, 1080.0f);
		}
		break;
	case 2:
		spriteRender.Init("Assets/sprite/hint6.DDS", 1920.0f, 1080.0f);
		break;
	case 3:
		if (game->levelc < 3)
		{
			spriteRender.Init("Assets/sprite/hint3.DDS", 1920.0f, 1080.0f);
		}
		else if (game->leveld < 2)
		{
			spriteRender.Init("Assets/sprite/hint4.DDS", 1920.0f, 1080.0f);
		}
		else if (game->leveld < 4)
		{
			spriteRender.Init("Assets/sprite/hint7.DDS", 1920.0f, 1080.0f);
		}
		else
		{
			spriteRender.Init("Assets/sprite/hint8.DDS", 1920.0f, 1080.0f);
		}
		break;
	case 4:
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

	//ƒqƒ“ƒg‰æ–Ê‚ð•Â‚¶‚é
	if (game->givehint == false)
	{
		DeleteGO(this);
	}
}

void hint::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}