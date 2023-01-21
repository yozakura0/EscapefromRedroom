#include "stdafx.h"
#include "Qkeyboxdial4.h"
#include "Qkeybox.h"
#include "Game.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Qkeyboxdial4::Qkeyboxdial4()
{
	spriteRender.Init("Assets/sprite/dial.gi.DDS", 200.0f, 300.0f);
	positiond4.x = 150;
	positiond4.y = 0;

	k4word = k4select;


	game = FindGO<Game>("game");
	qkeybox = FindGO<Qkeybox>("qkeybox");

	spriteRender.SetPosition(positiond4);
	spriteRender.Update();

	g_soundEngine->ResistWaveFileBank(5, "Assets/sound/pushbutton38.wav");
}

Qkeyboxdial4::~Qkeyboxdial4()
{

}

void Qkeyboxdial4::Update()
{
	//”ÍˆÍ§ŒÀ
	if (k4select >= 4)
	{
		k4select = 0;
	}

	//ƒ_ƒCƒ„ƒ‹Ø‘Ö
	if (k4word != k4select)
	{
		switch (k4select)
		{
		case 0:
			spriteRender.Init("Assets/sprite/dial.gi.DDS", 200.0f, 300.0f);
			k4word = k4select;
			spriteRender.SetPosition(positiond4);
			spriteRender.Update();
			qkeybox->kclearflag[3] = false;
			break;
		case 1:
			spriteRender.Init("Assets/sprite/dial.gc.DDS", 200.0f, 300.0f);
			k4word = k4select;
			spriteRender.SetPosition(positiond4);
			spriteRender.Update();
			break;
		case 2:
			spriteRender.Init("Assets/sprite/dial.ga.DDS", 200.0f, 300.0f);
			k4word = k4select;
			spriteRender.SetPosition(positiond4);
			spriteRender.Update();
			break;
		case 3:
			spriteRender.Init("Assets/sprite/dial.ge.DDS", 200.0f, 300.0f);
			k4word = k4select;
			spriteRender.SetPosition(positiond4);
			spriteRender.Update();
			qkeybox->kclearflag[3] = true;
			break;
		default:
			break;
		}
	}

	if (game->sceneC == 1)
	{
		DeleteGO(this);
	}

	spriteRender.SetPosition(positiond4);
	spriteRender.Update();
}

void Qkeyboxdial4::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}
