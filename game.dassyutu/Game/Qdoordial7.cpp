#include "stdafx.h"
#include "Qdoordial7.h"
#include "Game.h"
#include "Qdoor.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Qdoordial7::Qdoordial7()
{
	spriteRender.Init("Assets/sprite/dial.ri.DDS", 200.0f, 300.0f);
	positiond7.x = 750;
	positiond7.y = 0;

	game = FindGO<Game>("game");
	qdoor = FindGO<Qdoor>("qdoor");

	d7word = d7select;
	spriteRender.SetPosition(positiond7);
	spriteRender.Update();

	//g_soundEngine->ResistWaveFileBank(7, "Assets/sound/pushbutton38.wav");
}

Qdoordial7::~Qdoordial7()
{

}

void Qdoordial7::Update()
{
	//”ÍˆÍ§ŒÀ
	if (d7select >= 4)
	{
		d7select = 0;
	}

	//ƒ_ƒCƒ„ƒ‹Ø‘Ö
	if (d7word != d7select)
	{
		switch (d7select)
		{
		case 0:
			spriteRender.Init("Assets/sprite/dial.ri.DDS", 200.0f, 300.0f);
			d7word = d7select;
			spriteRender.SetPosition(positiond7);
			spriteRender.Update();
			break;
		case 1:
			spriteRender.Init("Assets/sprite/dial.ra.DDS", 200.0f, 300.0f);
			d7word = d7select;
			spriteRender.SetPosition(positiond7);
			spriteRender.Update();
			break;
		case 2:
			spriteRender.Init("Assets/sprite/dial.rt.DDS", 200.0f, 300.0f);
			d7word = d7select;
			spriteRender.SetPosition(positiond7);
			spriteRender.Update();
			qdoor->dclearflag[6] = true;
			break;
		case 3:
			spriteRender.Init("Assets/sprite/dial.rj.DDS", 200.0f, 300.0f);
			d7word = d7select;
			spriteRender.SetPosition(positiond7);
			spriteRender.Update();
			qdoor->dclearflag[6] = false;
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

void Qdoordial7::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}