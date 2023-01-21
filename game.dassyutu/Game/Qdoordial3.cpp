#include "stdafx.h"
#include "Qdoordial3.h"
#include "Game.h"
#include "Qdoor.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Qdoordial3::Qdoordial3()
{
	spriteRender.Init("Assets/sprite/dial.ra.DDS", 200.0f, 300.0f);
	positiond3.x = -250;
	positiond3.y = 0;

	game = FindGO<Game>("game");
	qdoor = FindGO<Qdoor>("qdoor");

	d3word = d3select;
	qdoor->dclearflag[2] = true;

	spriteRender.SetPosition(positiond3);
	spriteRender.Update();

	//g_soundEngine->ResistWaveFileBank(3, "Assets/sound/pushbutton38.wav");
}

Qdoordial3::~Qdoordial3()
{

}

void Qdoordial3::Update()
{
	//”ÍˆÍ§ŒÀ
	if (d3select >= 4)
	{
		d3select = 0;
	}

	//ƒ_ƒCƒ„ƒ‹Ø‘Ö
	if (d3word != d3select)
	{
		switch (d3select)
		{
		case 0:
			spriteRender.Init("Assets/sprite/dial.ra.DDS", 200.0f, 300.0f);
			qdoor->dclearflag[2] = true;
			d3word = d3select;
			spriteRender.SetPosition(positiond3);
			spriteRender.Update();
			break;
		case 1:
			spriteRender.Init("Assets/sprite/dial.re.DDS", 200.0f, 300.0f);
			qdoor->dclearflag[2] = false;
			d3word = d3select;
			spriteRender.SetPosition(positiond3);
			spriteRender.Update();
			break;
		case 2:
			spriteRender.Init("Assets/sprite/dial.rl.DDS", 200.0f, 300.0f);
			d3word = d3select;
			spriteRender.SetPosition(positiond3);
			spriteRender.Update();
			break;
		case 3:
			spriteRender.Init("Assets/sprite/dial.rn.DDS", 200.0f, 300.0f);
			d3word = d3select;
			spriteRender.SetPosition(positiond3);
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

void Qdoordial3::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}