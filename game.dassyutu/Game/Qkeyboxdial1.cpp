#include "stdafx.h"
#include "Qkeyboxdial1.h"
#include "Qkeybox.h"
#include "Game.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Qkeyboxdial1::Qkeyboxdial1()
{
	spriteRender.Init("Assets/sprite/dial.gr.DDS", 200.0f, 300.0f);
	positiond1.x = -750;
	positiond1.y = 0;

	game = FindGO<Game>("game");
	qkeybox = FindGO<Qkeybox>("qkeybox");

	k1word = k1select;

	spriteRender.SetPosition(positiond1);
	spriteRender.Update();

	g_soundEngine->ResistWaveFileBank(5, "Assets/sound/pushbutton38.wav");
}

Qkeyboxdial1::~Qkeyboxdial1()
{

}

void Qkeyboxdial1::Update()
{
	//”ÍˆÍ§ŒÀ
	if (k1select >= 4)
	{
		k1select = 0;
	}

	//ƒ_ƒCƒ„ƒ‹Ø‘Ö
	if (k1word != k1select)
	{
		switch (k1select)
		{
		case 0:
			spriteRender.Init("Assets/sprite/dial.gr.DDS", 200.0f, 300.0f);
			k1word = k1select;
			spriteRender.SetPosition(positiond1);
			spriteRender.Update();
			break;
		case 1:
			spriteRender.Init("Assets/sprite/dial.gs.DDS", 200.0f, 300.0f);
			k1word = k1select;
			spriteRender.SetPosition(positiond1);
			spriteRender.Update();
			qkeybox->kclearflag[0] = true;
			break;
		case 2:
			spriteRender.Init("Assets/sprite/dial.gc.DDS", 200.0f, 300.0f);
			k1word = k1select;
			spriteRender.SetPosition(positiond1);
			spriteRender.Update();
			qkeybox->kclearflag[0] = false;
			break;
		case 3:
			spriteRender.Init("Assets/sprite/dial.gi.DDS", 200.0f, 300.0f);
			k1word = k1select;
			spriteRender.SetPosition(positiond1);
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

void Qkeyboxdial1::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}