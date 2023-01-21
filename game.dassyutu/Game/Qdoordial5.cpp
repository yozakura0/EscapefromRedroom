#include "stdafx.h"
#include "Qdoordial5.h"
#include "Game.h"
#include "Qdoor.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Qdoordial5::Qdoordial5()
{
	spriteRender.Init("Assets/sprite/dial.rp.DDS", 200.0f, 300.0f);
	positiond5.x = 250;
	positiond5.y = 0;

	game = FindGO<Game>("game");
	qdoor = FindGO<Qdoor>("qdoor");

	d5word = d5select;
	spriteRender.SetPosition(positiond5);
	spriteRender.Update();

	//g_soundEngine->ResistWaveFileBank(5, "Assets/sound/pushbutton38.wav");
}

Qdoordial5::~Qdoordial5()
{

}

void Qdoordial5::Update()
{
	//”ÍˆÍ§ŒÀ
	if (d5select >= 4)
	{
		d5select = 0;
	}

	//ƒ_ƒCƒ„ƒ‹Ø‘Ö
	if (d5word != d5select)
	{
		switch (d5select)
		{
		case 0:
			spriteRender.Init("Assets/sprite/dial.rp.DDS", 200.0f, 300.0f);
			qdoor->dclearflag[4] = false;
			d5word = d5select;
			spriteRender.SetPosition(positiond5);
			spriteRender.Update();
			break;
		case 1:
			spriteRender.Init("Assets/sprite/dial.rd.DDS", 200.0f, 300.0f);
			d5word = d5select;
			spriteRender.SetPosition(positiond5);
			spriteRender.Update();
			break;
		case 2:
			spriteRender.Init("Assets/sprite/dial.re.DDS", 200.0f, 300.0f);
			d5word = d5select;
			spriteRender.SetPosition(positiond5);
			spriteRender.Update();
			break;
		case 3:
			spriteRender.Init("Assets/sprite/dial.rl.DDS", 200.0f, 300.0f);
			d5word = d5select;
			qdoor->dclearflag[4] = true;
			spriteRender.SetPosition(positiond5);
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

void Qdoordial5::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}