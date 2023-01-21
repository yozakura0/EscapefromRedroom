#include "stdafx.h"
#include "Qkeyboxdial2.h"
#include "Qkeybox.h"
#include "Game.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Qkeyboxdial2::Qkeyboxdial2()
{
	spriteRender.Init("Assets/sprite/dial.gc.DDS", 200.0f, 300.0f);
	positiond2.x = -450;
	positiond2.y = 0;

	k2word = k2select;

	game = FindGO<Game>("game");
	qkeybox = FindGO<Qkeybox>("qkeybox");

	spriteRender.SetPosition(positiond2);
	spriteRender.Update();

	g_soundEngine->ResistWaveFileBank(5, "Assets/sound/pushbutton38.wav");
}

Qkeyboxdial2::~Qkeyboxdial2()
{

}

void Qkeyboxdial2::Update()
{
	//”ÍˆÍ§ŒÀ
	if (k2select >= 4)
	{
		k2select = 0;
	}

	//ƒ_ƒCƒ„ƒ‹Ø‘Ö
	if (k2word != k2select)
	{
		switch (k2select)
		{
		case 0:
			spriteRender.Init("Assets/sprite/dial.gc.DDS", 200.0f, 300.0f);
			k2word = k2select;
			spriteRender.SetPosition(positiond2);
			spriteRender.Update();
			break;
		case 1:
			spriteRender.Init("Assets/sprite/dial.ge.DDS", 200.0f, 300.0f);
			k2word = k2select;
			spriteRender.SetPosition(positiond2);
			spriteRender.Update();
			break;
		case 2:
			spriteRender.Init("Assets/sprite/dial.gl.DDS", 200.0f, 300.0f);
			k2word = k2select;
			spriteRender.SetPosition(positiond2);
			spriteRender.Update();
			qkeybox->kclearflag[1] = true;
			break;
		case 3:
			spriteRender.Init("Assets/sprite/dial.go.DDS", 200.0f, 300.0f);
			k2word = k2select;
			spriteRender.SetPosition(positiond2);
			spriteRender.Update();
			qkeybox->kclearflag[1] = false;
			break;
		default:
			break;
		}
	}

	if (game->sceneC == 1)
	{
		DeleteGO(this);
	}

}

void Qkeyboxdial2::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}
