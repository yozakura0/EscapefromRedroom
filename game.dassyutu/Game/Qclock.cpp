#include "stdafx.h"
#include "Qclock.h"
#include "room2.h"
#include "Game.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Qclock::Qclock()
{
	spriteRender.Init("Assets/sprite/room 2-clock(0,0).DDS", 1920.0f, 1080.0f);

	game = FindGO<Game>("game");

	//説明表示
	wchar_t help[256];
	swprintf_s(help, 256, L"LBボタンで短針を回転、RBボタンで長針を回転");
	//表示するテキストを設定。
	fontRender.SetText(help);
	//フォントの位置を設定。
	fontRender.SetPosition(Vector3(-925.0f, -400.0f, 0.0f));
	//フォントの大きさを設定。
	fontRender.SetScale(2.0f);

	largesave = large;
	smollsave = smoll;

	g_soundEngine->ResistWaveFileBank(9, "Assets/sound/pushbutton31.wav");
	g_soundEngine->ResistWaveFileBank(10, "Assets/sound/clockbell.wav");
}

Qclock::~Qclock()
{

}

void Qclock::Update()
{
	game = FindGO<Game>("game");

	//トリガーが引かれたら針の向き変更
	if (g_pad[0]->IsTrigger(enButtonRB1))
	{
		SoundSource* clockse = NewGO<SoundSource>(0);
		clockse->Init(9);
		clockse->Play(false);
		clockse->SetVolume(3.5f);
		large++;
	}
	if (g_pad[0]->IsTrigger(enButtonLB1))
	{
		SoundSource* clockse = NewGO<SoundSource>(0);
		clockse->Init(9);
		clockse->Play(false);
		clockse->SetVolume(3.5f);
		smoll++;
	}
	/*if (g_pad[0]->IsTrigger(enButtonLB1))
	{
		large--;
	}
	if (g_pad[0]->IsTrigger(enButtonLB2))
	{
		smoll--;
	}*/

	//範囲制限
	if (smoll > 7)
	{
		smoll = 0;
	}
	if (large > 7)
	{
		large = 0;
	}
	/*if (smoll < 0)
	{
		smoll = 7;
	}
	if (large < 0)
	{
		large = 7;
	}*/

	//画像切り替え
	if (largesave != large || smollsave != smoll)
	{
		switch (large)
		{
		case 0:
			switch (smoll)
			{
			case 0:
				spriteRender.Init("Assets/sprite/room 2-clock(0,0).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 1:
				spriteRender.Init("Assets/sprite/room 2-clock(0,1).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 2:
				spriteRender.Init("Assets/sprite/room 2-clock(0,2).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 3:
				spriteRender.Init("Assets/sprite/room 2-clock(0,3).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 4:
				spriteRender.Init("Assets/sprite/room 2-clock(0,4).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 5:
				spriteRender.Init("Assets/sprite/room 2-clock(0,5).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 6:
				spriteRender.Init("Assets/sprite/room 2-clock(0,6).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 7:
				spriteRender.Init("Assets/sprite/room 2-clock(0,7).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			default:
				break;
			}
			break;
		case 1:
			switch (smoll)
			{
			case 0:
				spriteRender.Init("Assets/sprite/room 2-clock(1,0).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 1:
				spriteRender.Init("Assets/sprite/room 2-clock(1,1).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 2:
				spriteRender.Init("Assets/sprite/room 2-clock(1,2).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 3:
				spriteRender.Init("Assets/sprite/room 2-clock(1,3).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 4:
				spriteRender.Init("Assets/sprite/room 2-clock(1,4).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 5:
				spriteRender.Init("Assets/sprite/room 2-clock(1,5).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 6:
				spriteRender.Init("Assets/sprite/room 2-clock(1,6).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;

				//正解時の処理
				playboice = true;

				game->levelb = 3;
				game->sceneB = 0;
				break;
			case 7:
				spriteRender.Init("Assets/sprite/room 2-clock(1,7).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			default:
				break;
			}
			break;
		case 2:
			switch (smoll)
			{
			case 0:
				spriteRender.Init("Assets/sprite/room 2-clock(2,0).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 1:
				spriteRender.Init("Assets/sprite/room 2-clock(2,1).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 2:
				spriteRender.Init("Assets/sprite/room 2-clock(2,2).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 3:
				spriteRender.Init("Assets/sprite/room 2-clock(2,3).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 4:
				spriteRender.Init("Assets/sprite/room 2-clock(2,4).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 5:
				spriteRender.Init("Assets/sprite/room 2-clock(2,5).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 6:
				spriteRender.Init("Assets/sprite/room 2-clock(2,6).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 7:
				spriteRender.Init("Assets/sprite/room 2-clock(2,7).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			default:
				break;
			}
			break;
		case 3:
			switch (smoll)
			{
			case 0:
				spriteRender.Init("Assets/sprite/room 2-clock(3,0).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 1:
				spriteRender.Init("Assets/sprite/room 2-clock(3,1).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 2:
				spriteRender.Init("Assets/sprite/room 2-clock(3,2).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 3:
				spriteRender.Init("Assets/sprite/room 2-clock(3,3).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 4:
				spriteRender.Init("Assets/sprite/room 2-clock(3,4).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 5:
				spriteRender.Init("Assets/sprite/room 2-clock(3,5).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 6:
				spriteRender.Init("Assets/sprite/room 2-clock(3,6).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 7:
				spriteRender.Init("Assets/sprite/room 2-clock(3,7).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			default:
				break;
			}
			break;
		case 4:
			switch (smoll)
			{
			case 0:
				spriteRender.Init("Assets/sprite/room 2-clock(4,0).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 1:
				spriteRender.Init("Assets/sprite/room 2-clock(4,1).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 2:
				spriteRender.Init("Assets/sprite/room 2-clock(4,2).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 3:
				spriteRender.Init("Assets/sprite/room 2-clock(4,3).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 4:
				spriteRender.Init("Assets/sprite/room 2-clock(4,4).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 5:
				spriteRender.Init("Assets/sprite/room 2-clock(4,5).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 6:
				spriteRender.Init("Assets/sprite/room 2-clock(4,6).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 7:
				spriteRender.Init("Assets/sprite/room 2-clock(4,7).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			default:
				break;
			}
			break;
		case 5:
			switch (smoll)
			{
			case 0:
				spriteRender.Init("Assets/sprite/room 2-clock(5,0).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 1:
				spriteRender.Init("Assets/sprite/room 2-clock(5,1).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 2:
				spriteRender.Init("Assets/sprite/room 2-clock(5,2).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 3:
				spriteRender.Init("Assets/sprite/room 2-clock(5,3).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 4:
				spriteRender.Init("Assets/sprite/room 2-clock(5,4).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 5:
				spriteRender.Init("Assets/sprite/room 2-clock(5,5).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 6:
				spriteRender.Init("Assets/sprite/room 2-clock(5,6).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 7:
				spriteRender.Init("Assets/sprite/room 2-clock(5,7).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			default:
				break;
			}
			break;
		case 6:
			switch (smoll)
			{
			case 0:
				spriteRender.Init("Assets/sprite/room 2-clock(6,0).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 1:
				spriteRender.Init("Assets/sprite/room 2-clock(6,1).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 2:
				spriteRender.Init("Assets/sprite/room 2-clock(6,2).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 3:
				spriteRender.Init("Assets/sprite/room 2-clock(6,3).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 4:
				spriteRender.Init("Assets/sprite/room 2-clock(6,4).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 5:
				spriteRender.Init("Assets/sprite/room 2-clock(6,5).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 6:
				spriteRender.Init("Assets/sprite/room 2-clock(6,6).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 7:
				spriteRender.Init("Assets/sprite/room 2-clock(6,7).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			default:
				break;
			}
			break;
		case 7:
			switch (smoll)
			{
			case 0:
				spriteRender.Init("Assets/sprite/room 2-clock(7,0).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 1:
				spriteRender.Init("Assets/sprite/room 2-clock(7,1).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 2:
				spriteRender.Init("Assets/sprite/room 2-clock(7,2).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 3:
				spriteRender.Init("Assets/sprite/room 2-clock(7,3).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 4:
				spriteRender.Init("Assets/sprite/room 2-clock(7,4).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 5:
				spriteRender.Init("Assets/sprite/room 2-clock(7,5).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 6:
				spriteRender.Init("Assets/sprite/room 2-clock(7,6).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			case 7:
				spriteRender.Init("Assets/sprite/room 2-clock(7,7).DDS", 1920.0f, 1080.0f);
				largesave = large;
				smollsave = smoll;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}

	//音を流す処理
	if (playboice == true)
	{
		SoundSource* bellse = NewGO<SoundSource>(0);
		bellse->Init(10);
		bellse->Play(false);
		bellse->SetVolume(3.5f);
	}

	//シーンの値によって見る場所を変更
	if (game->sceneB == 0)
	{
		NewGO<room2>(0, "room2");
		DeleteGO(this);
	}
	////再表示されるなら消える
	//if (game->reshow == true || game->reshowing == true)
	//{
	//	DeleteGO(this);
	//}
}

void Qclock::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
	fontRender.Draw(rc);
}