#include "stdafx.h"
#include "Qkeyboxdial5.h"
#include "Qkeybox.h"
#include "Game.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Qkeyboxdial5::Qkeyboxdial5()
{
	spriteRender.Init("Assets/sprite/dial.gp.DDS", 200.0f, 300.0f);
	positiond5.x = 450;
	positiond5.y = 0;

	k5word = k5select;


	game = FindGO<Game>("game");
	qkeybox = FindGO<Qkeybox>("qkeybox");

	qkeybox->kclearflag[4] = true;

	spriteRender.SetPosition(positiond5);
	spriteRender.Update();

	g_soundEngine->ResistWaveFileBank(5, "Assets/sound/pushbutton38.wav");
}

Qkeyboxdial5::~Qkeyboxdial5()
{

}

void Qkeyboxdial5::Update()
{
	//”ÍˆÍ§ŒÀ
	if (k5select >= 4)
	{
		k5select = 0;
	}

	//ƒ_ƒCƒ„ƒ‹Ø‘Ö
	if (k5word != k5select)
	{
		switch (k5select)
		{
		case 0:
			spriteRender.Init("Assets/sprite/dial.gp.DDS", 200.0f, 300.0f);
			k5word = k5select;
			spriteRender.SetPosition(positiond5);
			spriteRender.Update();
			qkeybox->kclearflag[4] = true;
			break;
		case 1:
			spriteRender.Init("Assets/sprite/dial.gk.DDS", 200.0f, 300.0f);
			k5word = k5select;
			spriteRender.SetPosition(positiond5);
			spriteRender.Update();
			qkeybox->kclearflag[4] = false;
			break;
		case 2:
			spriteRender.Init("Assets/sprite/dial.gu.DDS", 200.0f, 300.0f);
			k5word = k5select;
			spriteRender.SetPosition(positiond5);
			spriteRender.Update();
			break;
		case 3:
			spriteRender.Init("Assets/sprite/dial.gc.DDS", 200.0f, 300.0f);
			k5word = k5select;
			spriteRender.SetPosition(positiond5);
			spriteRender.Update();
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

void Qkeyboxdial5::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}

