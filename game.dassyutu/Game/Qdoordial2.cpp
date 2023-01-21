#include "stdafx.h"
#include "Qdoordial2.h"
#include "Game.h"
#include "Qdoor.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Qdoordial2::Qdoordial2()
{
	spriteRender.Init("Assets/sprite/dial.rr.DDS", 200.0f, 300.0f);
	positiond2.x = -500;
	positiond2.y = 0;

	game = FindGO<Game>("game");
	qdoor = FindGO<Qdoor>("qdoor");

	d2word = d2select;

	spriteRender.SetPosition(positiond2);
	spriteRender.Update();

	//g_soundEngine->ResistWaveFileBank(2, "Assets/sound/pushbutton38.wav");
}

Qdoordial2::~Qdoordial2()
{

}

void Qdoordial2::Update()
{
	//”ÍˆÍ§ŒÀ
	if (d2select >= 4)
	{
		d2select = 0;
	}

	if (d2word != d2select)
	{
		//ƒ_ƒCƒ„ƒ‹Ø‘Ö
		switch (d2select)
		{
		case 0:
			spriteRender.Init("Assets/sprite/dial.rr.DDS", 200.0f, 300.0f);
			d2word = d2select;
			spriteRender.SetPosition(positiond2);
			spriteRender.Update();
			break;
		case 1:
			spriteRender.Init("Assets/sprite/dial.ru.DDS", 200.0f, 300.0f);
			d2word = d2select;
			spriteRender.SetPosition(positiond2);
			spriteRender.Update();
			break;
		case 2:
			spriteRender.Init("Assets/sprite/dial.rc.DDS", 200.0f, 300.0f);
			d2word = d2select;
			spriteRender.SetPosition(positiond2);
			spriteRender.Update();
			qdoor->dclearflag[1] = true;
			break;
		case 3:
			spriteRender.Init("Assets/sprite/dial.rp.DDS", 200.0f, 300.0f);
			d2word = d2select;
			spriteRender.SetPosition(positiond2);
			spriteRender.Update();
			qdoor->dclearflag[1] = false;
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

void Qdoordial2::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}