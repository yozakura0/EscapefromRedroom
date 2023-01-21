#include "stdafx.h"
#include "Qdoordial4.h"
#include "Game.h"
#include "Qdoor.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Qdoordial4::Qdoordial4()
{
	spriteRender.Init("Assets/sprite/dial.rr.DDS", 200.0f, 300.0f);
	positiond4.x = 0;
	positiond4.y = 0;

	game = FindGO<Game>("game");
	qdoor = FindGO<Qdoor>("qdoor");

	d4word = d4select;
	qdoor->dclearflag[3] = true;
	spriteRender.SetPosition(positiond4);
	spriteRender.Update();

	//g_soundEngine->ResistWaveFileBank(4, "Assets/sound/pushbutton38.wav");
}

Qdoordial4::~Qdoordial4()
{

}

void Qdoordial4::Update()
{
	//”ÍˆÍ§ŒÀ
	if (d4select >= 4)
	{
		d4select = 0;
	}

	//ƒ_ƒCƒ„ƒ‹Ø‘Ö
	if (d4word != d4select)
	{
		switch (d4select)
		{
		case 0:
			spriteRender.Init("Assets/sprite/dial.rr.DDS", 200.0f, 300.0f);
			qdoor->dclearflag[3] = true;
			d4word = d4select;
			spriteRender.SetPosition(positiond4);
			spriteRender.Update();
			break;
		case 1:
			spriteRender.Init("Assets/sprite/dial.ra.DDS", 200.0f, 300.0f);
			qdoor->dclearflag[3] = false;
			d4word = d4select;
			spriteRender.SetPosition(positiond4);
			spriteRender.Update();
			break;
		case 2:
			spriteRender.Init("Assets/sprite/dial.rn.DDS", 200.0f, 300.0f);
			d4word = d4select;
			spriteRender.SetPosition(positiond4);
			spriteRender.Update();
			break;
		case 3:
			spriteRender.Init("Assets/sprite/dial.rl.DDS", 200.0f, 300.0f);
			d4word = d4select;
			spriteRender.SetPosition(positiond4);
			spriteRender.Update();
			break;
		default:
			break;
		}
	}

	if (game->sceneC == 0 || game->sceneC == 4)
	{
		DeleteGO(this);
	}

}

void Qdoordial4::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}