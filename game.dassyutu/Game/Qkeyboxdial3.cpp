#include "stdafx.h"
#include "Qkeyboxdial3.h"
#include "Qkeybox.h"
#include "Game.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Qkeyboxdial3::Qkeyboxdial3()
{
	spriteRender.Init("Assets/sprite/dial.go.DDS", 200.0f, 300.0f);
	positiond3.x = -150;
	positiond3.y = 0;

	k3word = k3select;


	game = FindGO<Game>("game");
	qkeybox = FindGO<Qkeybox>("qkeybox");

	spriteRender.SetPosition(positiond3);
	spriteRender.Update();

	g_soundEngine->ResistWaveFileBank(5, "Assets/sound/pushbutton38.wav");
}

Qkeyboxdial3::~Qkeyboxdial3()
{

}

void Qkeyboxdial3::Update()
{
	//”ÍˆÍ§ŒÀ
	if (k3select >= 4)
	{
		k3select = 0;
	}

	//ƒ_ƒCƒ„ƒ‹Ø‘Ö
	if (k3word != k3select)
	{
		switch (k3select)
		{
		case 0:
			spriteRender.Init("Assets/sprite/dial.go.DDS", 200.0f, 300.0f);
			k3word = k3select;
			spriteRender.SetPosition(positiond3);
			spriteRender.Update();
			break;
		case 1:
			spriteRender.Init("Assets/sprite/dial.ge.DDS", 200.0f, 300.0f);
			k3word = k3select;
			spriteRender.SetPosition(positiond3);
			spriteRender.Update();
			qkeybox->kclearflag[2] = true;
			break;
		case 2:
			spriteRender.Init("Assets/sprite/dial.gs.DDS", 200.0f, 300.0f);
			k3word = k3select;
			spriteRender.SetPosition(positiond3);
			spriteRender.Update();
			qkeybox->kclearflag[2] = false;
			break;
		case 3:
			spriteRender.Init("Assets/sprite/dial.gu.DDS", 200.0f, 300.0f);
			k3word = k3select;
			spriteRender.SetPosition(positiond3);
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

void Qkeyboxdial3::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}
