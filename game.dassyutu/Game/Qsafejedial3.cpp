#include "stdafx.h"
#include "Qsafejedial3.h"
#include "Game.h"
#include "Qsafe.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Qsafejedial3::Qsafejedial3()
{
	game = FindGO<Game>("game");
	qsafe = FindGO<Qsafe>("qsafe");


	//ダイアルの画像の読み込み
	spriteRender.Init("Assets/sprite/dial.y1.DDS", 200.0f, 300.0f);
	positionjyellow.x = 450;
	positionjyellow.y = 0;

	j3word = j3select;
	qsafe->sclearflag[2] = true;

	spriteRender.SetPosition(positionjyellow);
	spriteRender.Update();
	//g_soundEngine->ResistWaveFileBank(3, "Assets/sound/pushbutton38.wav");
}

Qsafejedial3::~Qsafejedial3()
{

}

void Qsafejedial3::Update()
{
	//範囲制限
	if (j3select > 3)
	{
		j3select = 0;
	}

	//ダイヤル切替
	if (j3word != j3select)
	{
		switch (j3select)
		{
		case 0:
			spriteRender.Init("Assets/sprite/dial.y1.DDS", 200.0f, 300.0f);
			j3word = j3select;
			spriteRender.SetPosition(positionjyellow);
			spriteRender.Update();
			qsafe->sclearflag[2] = true;
			break;
		case 1:
			spriteRender.Init("Assets/sprite/dial.y2.DDS", 200.0f, 300.0f);
			j3word = j3select;
			spriteRender.SetPosition(positionjyellow);
			spriteRender.Update();
			qsafe->sclearflag[2] = false;
			break;
		case 2:
			spriteRender.Init("Assets/sprite/dial.y3.DDS", 200.0f, 300.0f);
			j3word = j3select;
			spriteRender.SetPosition(positionjyellow);
			spriteRender.Update();
			break;
		case 3:
			spriteRender.Init("Assets/sprite/dial.y4.DDS", 200.0f, 300.0f);
			j3word = j3select;
			spriteRender.SetPosition(positionjyellow);
			spriteRender.Update();
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

void Qsafejedial3::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}