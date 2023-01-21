#include "stdafx.h"
#include "Qdoordial1.h"
#include "Game.h"
#include "Qdoor.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Qdoordial1::Qdoordial1()
{
	spriteRender.Init("Assets/sprite/dial.rs.DDS", 200.0f, 300.0f);
	positiond1.x = -750;
	positiond1.y = 0;

	game = FindGO<Game>("game");
	qdoor = FindGO<Qdoor>("qdoor");

	d1word = d1select;

	qdoor->dclearflag[0] = true;

	spriteRender.SetPosition(positiond1);
	spriteRender.Update();

	//g_soundEngine->ResistWaveFileBank(1, "Assets/sound/pushbutton38.wav");
}

Qdoordial1::~Qdoordial1()
{

}

void Qdoordial1::Update()
{
	//範囲制限
	if (d1select >= 4)
	{
		d1select = 0;
	}

	//ダイヤル切替
	if (d1word != d1select)
	{
		switch (d1select)
		{
		case 0:
			spriteRender.Init("Assets/sprite/dial.rs.DDS", 200.0f, 300.0f);
			qdoor->dclearflag[0] = true;
			d1word = d1select;
			spriteRender.SetPosition(positiond1);
			spriteRender.Update();
			break;
		case 1:
			spriteRender.Init("Assets/sprite/dial.rl.DDS", 200.0f, 300.0f);
			qdoor->dclearflag[0] = false;
			d1word = d1select;
			spriteRender.SetPosition(positiond1);
			spriteRender.Update();
			break;
		case 2:
			spriteRender.Init("Assets/sprite/dial.rg.DDS", 200.0f, 300.0f);
			d1word = d1select;
			spriteRender.SetPosition(positiond1);
			spriteRender.Update();
			break;
		case 3:
			spriteRender.Init("Assets/sprite/dial.rf.DDS", 200.0f, 300.0f);
			d1word = d1select;
			spriteRender.SetPosition(positiond1);
			spriteRender.Update();
			break;
		default:
			break;
		}
	}

	//シーンに応じて視点切替
	if (game->sceneC == 0|| game->sceneC == 4)
	{
		DeleteGO(this);
	}

	
}

void Qdoordial1::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}