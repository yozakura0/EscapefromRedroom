#include "stdafx.h"
#include "room2.h"
#include "room1.h"
#include "room3.h"
#include "Game.h"
#include "Qbookshelf.h"
#include "Qmoon.h"
#include "Qclock.h"

room2::room2()
{
	game = FindGO<Game>("game");
	

	//�i�s�x�𔻒肵�ĕ\��
	switch (game->levelb)
	{
	//0�Ȃ�s��
	case 0:
		spriteRender.Init("Assets/sprite/dark.DDS", 1920.0f, 1080.0f);
		break;
	//1�Ȃ�first
	case 1:
		spriteRender.Init("Assets/sprite/room 2-first.DDS", 1920.0f, 1080.0f);
		break;
		//2�Ȃ�second
	case 2:
		spriteRender.Init("Assets/sprite/room 2-second.DDS", 1920.0f, 1080.0f);
		break;
		//3�Ȃ�third
	case 3:
		spriteRender.Init("Assets/sprite/room 2-third.DDS", 1920.0f, 1080.0f);
		break;
		//4�Ȃ�fourth
	case 4:
		spriteRender.Init("Assets/sprite/room2-fourth.DDS", 1920.0f, 1080.0f);
	default:
		break;
	}

	
	game->siten = 2;
}

room2::~room2()
{

}

void room2::Update()
{
	game = FindGO<Game>("game");

	if (game->levelb != 0 && game->sceneB == 1 
		|| game->sceneB == 2 || game->sceneB == 4)//���񓚂���1���{�I�֘A�Ȃ�{�I�\��
	{
		NewGO<Qbookshelf>(0, "qbookshelf");
		DeleteGO(this);
	}
	if (game->levelb != 0 && game->levelb < 3 && game->sceneB == 6)//���񓚂���6�Ȃ玞�v�\��
	{
		NewGO<Qclock>(0, "qclock");
		DeleteGO(this);
	}
	if (game->sceneB == 7)//7�Ȃ�G��\��
	{
		NewGO<Qmoon>(0, "qmoon");
		DeleteGO(this);
	}

	//���E�̃{�^���������ꂽ�王�_�ؑ�
	if (g_pad[0]->IsTrigger(enButtonLeft))
	{
		NewGO<room1>(0, "room1");
		DeleteGO(this);
	}
	if (g_pad[0]->IsTrigger(enButtonRight))
	{
		NewGO<room3>(0, "room3");
		DeleteGO(this);
	}
	////�ĕ\�������Ȃ������
	//if (game->reshow == true || game->reshowing == true)
	//{
	//	DeleteGO(this);
	//}
	
}

void room2::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}
