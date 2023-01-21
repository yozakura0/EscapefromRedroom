#include "stdafx.h"
#include "Qmoon.h"
#include "room2.h"
#include "Game.h"
#include "Item.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Qmoon::Qmoon()
{
	game = FindGO<Game>("game");
	item = FindGO<Item>("item");

	//�i�s�x�ɉ����ĕ\���ؑ�
	if (game->levelb != 0)
	{
		if (game->levelb == 4)
		{
			spriteRender.Init("Assets/sprite/room2-redmoon.DDS", 1920.0f, 1080.0f);
		}
		else
		{
			spriteRender.Init("Assets/sprite/room 2-moon.DDS", 1920.0f, 1080.0f);
		}
	}

	g_soundEngine->ResistWaveFileBank(11, "Assets/sound/takecard.wav");
}

Qmoon::~Qmoon()
{

}

void Qmoon::Update()
{
	game = FindGO<Game>("game");

	//�\���ؑ�
	if (item->itemselect == 3 && mselect == true)
	{
		SoundSource* paperse = NewGO<SoundSource>(0);
		paperse->Init(11);
		paperse->Play(false);
		paperse->SetVolume(3.5f);

		game->levelb = 4;
		spriteRender.Init("Assets/sprite/room2-redmoon.DDS", 1920.0f, 1080.0f);
		item->paper = 2;
		item->itemselect = 0;

	}

	//�V�[���̒l�ɂ���Č���ꏊ��ύX
	if (game->sceneB == 0)
	{
		NewGO<room2>(0, "room2");
		DeleteGO(this);
	}
	////�ĕ\�������Ȃ������
	//if (game->reshow == true || game->reshowing == true)
	//{
	//	DeleteGO(this);
	//}
}

void Qmoon::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}