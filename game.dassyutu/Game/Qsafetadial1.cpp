#include "stdafx.h"
#include "Qsafetadial1.h"
#include "Game.h"
#include "Qsafe.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Qsafetadial1::Qsafetadial1()
{
	game = FindGO<Game>("game");
	qsafe = FindGO<Qsafe>("qsafe");


	//ダイアルの画像の読み込み
	spriteRender.Init("Assets/sprite/dial.w1.DDS", 200.0f, 300.0f);
	positiontblue.x = -450;
	positiontblue.y = 0;

	t1word = t1select;

	spriteRender.SetPosition(positiontblue);
	spriteRender.Update();
	//g_soundEngine->ResistWaveFileBank(1, "Assets/sound/pushbutton38.wav");
}

Qsafetadial1::~Qsafetadial1()
{

}

void Qsafetadial1::Update()
{
	//範囲制限
	if (t1select > 8)
	{
		t1select = 0;
	}

	//ダイヤル切替
	if (t1word != t1select)
	{
		switch (t1select)
		{
		case 0:
			spriteRender.Init("Assets/sprite/dial.w1.DDS", 200.0f, 300.0f);
			t1word = t1select;
			spriteRender.SetPosition(positiontblue);
			spriteRender.Update();
			break;
		case 1:
			spriteRender.Init("Assets/sprite/dial.w2.DDS", 200.0f, 300.0f);
			t1word = t1select;
			spriteRender.SetPosition(positiontblue);
			spriteRender.Update();
			break;
		case 2:
			spriteRender.Init("Assets/sprite/dial.w3.DDS", 200.0f, 300.0f);
			t1word = t1select;
			spriteRender.SetPosition(positiontblue);
			spriteRender.Update();
			qsafe->sclearflag[3] = true;
			break;
		case 3:
			spriteRender.Init("Assets/sprite/dial.w4.DDS", 200.0f, 300.0f);
			t1word = t1select;
			spriteRender.SetPosition(positiontblue);
			spriteRender.Update();
			qsafe->sclearflag[3] = false;
			break;
		case 4:
			spriteRender.Init("Assets/sprite/dial.w5.DDS", 200.0f, 300.0f);
			t1word = t1select;
			spriteRender.SetPosition(positiontblue);
			spriteRender.Update();
			break;
		case 5:
			spriteRender.Init("Assets/sprite/dial.w6.DDS", 200.0f, 300.0f);
			t1word = t1select;
			spriteRender.SetPosition(positiontblue);
			spriteRender.Update();
			break;
		case 6:
			spriteRender.Init("Assets/sprite/dial.w7.DDS", 200.0f, 300.0f);
			t1word = t1select;
			spriteRender.SetPosition(positiontblue);
			spriteRender.Update();
			break;
		case 7:
			spriteRender.Init("Assets/sprite/dial.w8.DDS", 200.0f, 300.0f);
			t1word = t1select;
			spriteRender.SetPosition(positiontblue);
			spriteRender.Update();
			break;
		case 8:
			spriteRender.Init("Assets/sprite/dial.w9.DDS", 200.0f, 300.0f);
			t1word = t1select;
			spriteRender.SetPosition(positiontblue);
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

void Qsafetadial1::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}