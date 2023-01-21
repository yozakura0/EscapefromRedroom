#include "stdafx.h"
#include "Qsafejedial2.h"
#include "Game.h"
#include "Qsafe.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Qsafejedial2::Qsafejedial2()
{
	game = FindGO<Game>("game");
	qsafe = FindGO<Qsafe>("qsafe");


	//ダイアルの画像の読み込み
	spriteRender.Init("Assets/sprite/dial.r1.DDS", 200.0f, 300.0f);
	positionjred.x = 0;
	positionjred.y = 0;

	j2word = j2select;

	//g_soundEngine->ResistWaveFileBank(2, "Assets/sound/pushbutton38.wav");
}

Qsafejedial2::~Qsafejedial2()
{

}

void Qsafejedial2::Update()
{
	//範囲制限
	if (j2select > 3)
	{
		j2select = 0;
	}

	//ダイヤル切替
	if (j2word != j2select)
	{
		switch (j2select)
		{
		case 0:
			spriteRender.Init("Assets/sprite/dial.r1.DDS", 200.0f, 300.0f);
			j2word = j2select;
			spriteRender.SetPosition(positionjred);
			spriteRender.Update();
			break;
		case 1:
			spriteRender.Init("Assets/sprite/dial.r2.DDS", 200.0f, 300.0f);
			j2word = j2select;
			spriteRender.SetPosition(positionjred);
			spriteRender.Update();
			break;
		case 2:
			spriteRender.Init("Assets/sprite/dial.r3.DDS", 200.0f, 300.0f);
			j2word = j2select;
			spriteRender.SetPosition(positionjred);
			spriteRender.Update();
			qsafe->sclearflag[1] = true;
			break;
		case 3:
			spriteRender.Init("Assets/sprite/dial.r4.DDS", 200.0f, 300.0f);
			j2word = j2select;
			spriteRender.SetPosition(positionjred);
			spriteRender.Update();
			qsafe->sclearflag[1] = false;
			break;
		default:
			break;
		}
	}

	if (game->sceneD == 3)
	{
		DeleteGO(this);
	}

}

void Qsafejedial2::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}