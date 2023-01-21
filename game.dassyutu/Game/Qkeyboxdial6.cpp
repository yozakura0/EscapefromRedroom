#include "stdafx.h"
#include "Qkeyboxdial6.h"
#include "Qkeybox.h"
#include "Game.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Qkeyboxdial6::Qkeyboxdial6()
{
	spriteRender.Init("Assets/sprite/dial.gt.DDS", 200.0f, 300.0f);
	positiond6.x = 750;
	positiond6.y = 0;

	k6word = k6select;


	game = FindGO<Game>("game");
	qkeybox = FindGO<Qkeybox>("qkeybox");

	spriteRender.SetPosition(positiond6);
	spriteRender.Update();

	g_soundEngine->ResistWaveFileBank(5, "Assets/sound/pushbutton38.wav");
}

Qkeyboxdial6::~Qkeyboxdial6()
{

}

void Qkeyboxdial6::Update()
{
	//”ÍˆÍ§ŒÀ
	if (k6select >= 4)
	{
		k6select = 0;
	}

	//ƒ_ƒCƒ„ƒ‹Ø‘Ö
	if (k6word != k6select)
	{
		switch (k6select)
		{
		case 0:
			spriteRender.Init("Assets/sprite/dial.gt.DDS", 200.0f, 300.0f);
			k6word = k6select;
			spriteRender.SetPosition(positiond6);
			spriteRender.Update();
			break;
		case 1:
			spriteRender.Init("Assets/sprite/dial.gy.DDS", 200.0f, 300.0f);
			k6word = k6select;
			spriteRender.SetPosition(positiond6);
			spriteRender.Update();
			qkeybox->kclearflag[5] = true;
			break;
		case 2:
			spriteRender.Init("Assets/sprite/dial.gp.DDS", 200.0f, 300.0f);
			k6word = k6select;
			spriteRender.SetPosition(positiond6);
			spriteRender.Update();
			qkeybox->kclearflag[5] = false;
			break;
		case 3:
			spriteRender.Init("Assets/sprite/dial.gk.DDS", 200.0f, 300.0f);
			k6word = k6select;
			spriteRender.SetPosition(positiond6);
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

void Qkeyboxdial6::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}