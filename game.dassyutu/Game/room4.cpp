#include "stdafx.h"
#include "room4.h"
#include "room3.h"
#include "room1.h"
#include "Item.h"
#include "Game.h"
#include "Qtarget.h"
#include "Qjewel.h"
#include "Qsafe.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

room4::room4()
{
	game = FindGO<Game>("game");
	item = FindGO<Item>("item");

	//�i�s�x�𔻒肵�ĕ\��
	switch (game->leveld)
	{
		//0�Ȃ�s��
	case 0:
		spriteRender.Init("Assets/sprite/dark.DDS", 1920.0f, 1080.0f);
		break;
		//1�Ȃ�first
	case 1:
		spriteRender.Init("Assets/sprite/room4-first.DDS", 1920.0f, 1080.0f);
		break;
		//2�Ȃ�second
	case 2:
		spriteRender.Init("Assets/sprite/room4-second.DDS", 1920.0f, 1080.0f);
		break;
		//3�Ȃ�third
	case 3:
		spriteRender.Init("Assets/sprite/room4-third.DDS", 1920.0f, 1080.0f);
		break;
		//4�Ȃ�fourth.item
	case 4:
		spriteRender.Init("Assets/sprite/room4-fourth.item.DDS", 1920.0f, 1080.0f);
		break;
		//5�Ȃ�fourth
	case 5:
		spriteRender.Init("Assets/sprite/room4-fourth.DDS", 1920.0f, 1080.0f);
		break;
	default:
		break;
	}

	game->siten = 4;

	g_soundEngine->ResistWaveFileBank(7, "Assets/sound/throwknife.wav");
}

room4::~room4()
{
	if (change == false)
	{
		change = true;
		NewGO<room4>(0, "room4");
	}
}

void room4::Update()
{
	game = FindGO<Game>("game");

	if (throwing == true && item->itemselect == 2)
	{
		//�i�C�t�𓊂��鉹
		SoundSource* knifese = NewGO<SoundSource>(0);
		knifese->Init(7);
		knifese->Play(false);
		knifese->SetVolume(3.5f);
		
		//spriteRender.Init("Assets/sprite/room4-throwknife1.DDS", 1920.0f, 1080.0f);
		//for (int i = 0; i < 60; i++){}

		//spriteRender.Init("Assets/sprite/room4-throwknife2.DDS", 1920.0f, 1080.0f);
		//for (int i = 0; i < 60; i++) {}

		//spriteRender.Init("Assets/sprite/room4-sleeperdown.DDS", 1920.0f, 1080.0f);
		//for (int i = 0; i < 60; i++) {}

		item->knife = 2;
		item->itemselect = 0;
		game->leveld = 2;
		
		if (game->leveld == 2 && game->levelb >= 3)
		{
			game->leveld = 3;
		}

		change = false;
		DeleteGO(this);
	}

	if (game->leveld == 2 && game->levelb >= 3)
	{
		game->leveld = 3;

		change = false;
		DeleteGO(this);
	}

	if (game->sceneD == 1)//1�Ȃ��Ε\��
	{
		NewGO<Qjewel>(0, "qjewel");
		DeleteGO(this);
	}
	if (game->sceneD == 3 && game->leveld >= 2)//3�Ȃ���ɕ\��
	{
		NewGO<Qsafe>(0, "qsafe");
		DeleteGO(this);
	}
	if (game->sceneD == 6)//6�Ȃ�I�\��
	{
		NewGO<Qtarget>(0, "qtarget");
		DeleteGO(this);
	}

	//���E�̃{�^���������ꂽ�王�_�ؑ�
	if (g_pad[0]->IsTrigger(enButtonLeft))
	{
		NewGO<room3>(0, "room3");
		DeleteGO(this);
	}
	if (g_pad[0]->IsTrigger(enButtonRight))
	{
		NewGO<room1>(0, "room1");
		DeleteGO(this);
	}
	////�ĕ\�������Ȃ������
	//if (game->reshow == true || game->reshowing == true)
	//{
	//	DeleteGO(this);
	//}
}

void room4::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}
