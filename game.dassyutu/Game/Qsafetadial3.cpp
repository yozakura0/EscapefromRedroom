#include "stdafx.h"
#include "Qsafetadial3.h"
#include "Game.h"
#include "Qsafe.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Qsafetadial3::Qsafetadial3()
{
	game = FindGO<Game>("game");
	qsafe = FindGO<Qsafe>("qsafe");


	//ダイアルの画像の読み込み
	spriteRender.Init("Assets/sprite/dial.w1.DDS", 200.0f, 300.0f);
	positiontyellow.x = 450;
	positiontyellow.y = 0;

	t3word = t3select;

	spriteRender.SetPosition(positiontyellow);
	spriteRender.Update();
	//g_soundEngine->ResistWaveFileBank(3, "Assets/sound/pushbutton38.wav");
}

Qsafetadial3::~Qsafetadial3()
{

}

void Qsafetadial3::Update()
{
	//範囲制限
	if (t3select > 8)
	{
		t3select = 0;
	}

	//ダイヤル切替
	if (t3word != t3select)
	{
		switch (t3select)
		{
		case 0:
			spriteRender.Init("Assets/sprite/dial.w1.DDS", 200.0f, 300.0f);
			t3word = t3select;
			spriteRender.SetPosition(positiontyellow);
			spriteRender.Update();
			break;
		case 1:
			spriteRender.Init("Assets/sprite/dial.w2.DDS", 200.0f, 300.0f);
			t3word = t3select;
			spriteRender.SetPosition(positiontyellow);
			spriteRender.Update();
			break;
		case 2:
			spriteRender.Init("Assets/sprite/dial.w3.DDS", 200.0f, 300.0f);
			t3word = t3select;
			spriteRender.SetPosition(positiontyellow);
			spriteRender.Update();
			break;
		case 3:
			spriteRender.Init("Assets/sprite/dial.w4.DDS", 200.0f, 300.0f);
			t3word = t3select;
			spriteRender.SetPosition(positiontyellow);
			spriteRender.Update();
			break;
		case 4:
			spriteRender.Init("Assets/sprite/dial.w5.DDS", 200.0f, 300.0f);
			t3word = t3select;
			spriteRender.SetPosition(positiontyellow);
			spriteRender.Update();
			break;
		case 5:
			spriteRender.Init("Assets/sprite/dial.w6.DDS", 200.0f, 300.0f);
			t3word = t3select;
			spriteRender.SetPosition(positiontyellow);
			spriteRender.Update();
			break;
		case 6:
			spriteRender.Init("Assets/sprite/dial.w7.DDS", 200.0f, 300.0f);
			t3word = t3select;
			spriteRender.SetPosition(positiontyellow);
			spriteRender.Update();
			break;
		case 7:
			spriteRender.Init("Assets/sprite/dial.w8.DDS", 200.0f, 300.0f);
			t3word = t3select;
			spriteRender.SetPosition(positiontyellow);
			spriteRender.Update();
			qsafe->sclearflag[5] = true;
			break;
		case 8:
			spriteRender.Init("Assets/sprite/dial.w9.DDS", 200.0f, 300.0f);
			t3word = t3select;
			spriteRender.SetPosition(positiontyellow);
			spriteRender.Update();
			qsafe->sclearflag[5] = false;
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

void Qsafetadial3::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}