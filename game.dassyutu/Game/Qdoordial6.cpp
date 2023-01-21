#include "stdafx.h"
#include "Qdoordial6.h"
#include "Game.h"
#include "Qdoor.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Qdoordial6::Qdoordial6()
{
	spriteRender.Init("Assets/sprite/dial.ri.DDS", 200.0f, 300.0f);
	positiond6.x = 500;
	positiond6.y = 0;

	game = FindGO<Game>("game");
	qdoor = FindGO<Qdoor>("qdoor");

	d6word = d6select;
	qdoor->dclearflag[5] = true;
	spriteRender.SetPosition(positiond6);
	spriteRender.Update();

	//g_soundEngine->ResistWaveFileBank(6, "Assets/sound/pushbutton38.wav");
}

Qdoordial6::~Qdoordial6()
{

}

void Qdoordial6::Update()
{
	//”ÍˆÍ§ŒÀ
	if (d6select >= 4)
	{
		d6select = 0;
	}

	//ƒ_ƒCƒ„ƒ‹Ø‘Ö
	if (d6word != d6select)
	{
		switch (d6select)
		{
		case 0:
			spriteRender.Init("Assets/sprite/dial.ri.DDS", 200.0f, 300.0f);
			d6word = d6select;
			spriteRender.SetPosition(positiond6);
			spriteRender.Update();
			break;
		case 1:
			spriteRender.Init("Assets/sprite/dial.re.DDS", 200.0f, 300.0f);
			d6word = d6select;
			spriteRender.SetPosition(positiond6);
			spriteRender.Update();
			qdoor->dclearflag[5] = true;
			break;
		case 2:
			spriteRender.Init("Assets/sprite/dial.rf.DDS", 200.0f, 300.0f);
			d6word = d6select;
			spriteRender.SetPosition(positiond6);
			spriteRender.Update();
			qdoor->dclearflag[5] = false;
			break;
		case 3:
			spriteRender.Init("Assets/sprite/dial.rr.DDS", 200.0f, 300.0f);
			d6word = d6select;
			spriteRender.SetPosition(positiond6);
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

void Qdoordial6::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}