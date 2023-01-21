#include "stdafx.h"
#include "Qsafetadial2.h"
#include "Game.h"
#include "Qsafe.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Qsafetadial2::Qsafetadial2()
{
	game = FindGO<Game>("game");
	qsafe = FindGO<Qsafe>("qsafe");


	//ダイアルの画像の読み込み
	spriteRender.Init("Assets/sprite/dial.w1.DDS", 200.0f, 300.0f);

	positiontred.x = 0;
	positiontred.y = 0;

	t2word = t2select;

	spriteRender.SetPosition(positiontred);
	spriteRender.Update();
	//g_soundEngine->ResistWaveFileBank(2, "Assets/sound/pushbutton38.wav");
}

Qsafetadial2::~Qsafetadial2()
{

}

void Qsafetadial2::Update()
{
	//範囲制限
	if (t2select > 8)
	{
		t2select = 0;
	}

	//ダイヤル切替
	if (t2word != t2select)
	{
		switch (t2select)
		{
		case 0:
			spriteRender.Init("Assets/sprite/dial.w1.DDS", 200.0f, 300.0f);
			t2word = t2select;
			spriteRender.SetPosition(positiontred);
			spriteRender.Update();
			qsafe->sclearflag[4] = false;
			break;
		case 1:
			spriteRender.Init("Assets/sprite/dial.w2.DDS", 200.0f, 300.0f);
			t2word = t2select;
			spriteRender.SetPosition(positiontred);
			spriteRender.Update();
			break;
		case 2:
			spriteRender.Init("Assets/sprite/dial.w3.DDS", 200.0f, 300.0f);
			t2word = t2select;
			spriteRender.SetPosition(positiontred);
			spriteRender.Update();
			break;
		case 3:
			spriteRender.Init("Assets/sprite/dial.w4.DDS", 200.0f, 300.0f);
			t2word = t2select;
			spriteRender.SetPosition(positiontred);
			spriteRender.Update();
			break;
		case 4:
			spriteRender.Init("Assets/sprite/dial.w5.DDS", 200.0f, 300.0f);
			t2word = t2select;
			spriteRender.SetPosition(positiontred);
			spriteRender.Update();
			break;
		case 5:
			spriteRender.Init("Assets/sprite/dial.w6.DDS", 200.0f, 300.0f);
			t2word = t2select;
			spriteRender.SetPosition(positiontred);
			spriteRender.Update();
			break;
		case 6:
			spriteRender.Init("Assets/sprite/dial.w7.DDS", 200.0f, 300.0f);
			t2word = t2select;
			spriteRender.SetPosition(positiontred);
			spriteRender.Update();
			break;
		case 7:
			spriteRender.Init("Assets/sprite/dial.w8.DDS", 200.0f, 300.0f);
			t2word = t2select;
			spriteRender.SetPosition(positiontred);
			spriteRender.Update();
			break;
		case 8:
			spriteRender.Init("Assets/sprite/dial.w9.DDS", 200.0f, 300.0f);
			t2word = t2select;
			spriteRender.SetPosition(positiontred);
			spriteRender.Update();
			qsafe->sclearflag[4] = true;
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

void Qsafetadial2::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}
