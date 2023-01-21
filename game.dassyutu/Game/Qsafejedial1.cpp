#include "stdafx.h"
#include "Qsafejedial1.h"
#include "Game.h"
#include "Qsafe.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Qsafejedial1::Qsafejedial1()
{
	game = FindGO<Game>("game");
	qsafe = FindGO<Qsafe>("qsafe");

	//ダイアルの画像の読み込み
	spriteRender.Init("Assets/sprite/dial.b1.DDS", 200.0f, 300.0f);
	positionjblue.x = -450;
	positionjblue.y = 0;

	j1word = j1select;

	spriteRender.SetPosition(positionjblue);
	spriteRender.Update();
	//g_soundEngine->ResistWaveFileBank(1, "Assets/sound/pushbutton38.wav");
}

Qsafejedial1::~Qsafejedial1()
{

}

void Qsafejedial1::Update()
{
	//範囲制限
	if (j1select > 3)
	{
		j1select = 0;
	}

	//ダイヤル切替
	if (j1word != j1select)
	{
		switch (j1select)
		{
		case 0:
			spriteRender.Init("Assets/sprite/dial.b1.DDS", 200.0f, 300.0f);
			j1word = j1select;
			spriteRender.SetPosition(positionjblue);
			spriteRender.Update();
			break;
		case 1:
			spriteRender.Init("Assets/sprite/dial.b2.DDS", 200.0f, 300.0f);
			j1word = j1select;
			spriteRender.SetPosition(positionjblue);
			spriteRender.Update();
			qsafe->sclearflag[0] = true;
			break;
		case 2:
			spriteRender.Init("Assets/sprite/dial.b3.DDS", 200.0f, 300.0f);
			j1word = j1select;
			spriteRender.SetPosition(positionjblue);
			spriteRender.Update();
			qsafe->sclearflag[0] = false;
			break;
		case 3:
			spriteRender.Init("Assets/sprite/dial.b4.DDS", 200.0f, 300.0f);
			j1word = j1select;
			spriteRender.SetPosition(positionjblue);
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

void Qsafejedial1::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}
