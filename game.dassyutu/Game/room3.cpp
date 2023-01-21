#include "stdafx.h"
#include "room3.h"
#include "room2.h"
#include "room4.h"
#include "Game.h"
#include "Qkeybox.h"
#include "Qdoor.h"
#include "Qshelf.h"

room3::room3()
{

	game = FindGO<Game>("game");

	//�i�s�x�𔻒肵�ĕ\��
	switch (game->levelc)
	{
	//0�Ȃ�s��
	case 0:
		spriteRender.Init("Assets/sprite/dark.DDS", 1920.0f, 1080.0f);
		break;
	//1�Ȃ�first
	case 1:
		spriteRender.Init("Assets/sprite/room3-first.DDS", 1920.0f, 1080.0f);
		break;
		//2�Ȃ�second
	case 2:
		spriteRender.Init("Assets/sprite/room3-second.DDS", 1920.0f, 1080.0f);
		break;
		//3�Ȃ�third
	case 3:
		spriteRender.Init("Assets/sprite/room3-third.DDS", 1920.0f, 1080.0f);
		break;
	default:
		break;
	}

	game->siten = 3;
}

room3::~room3()
{

}

void room3::Update()
{
	game = FindGO<Game>("game");

	if (game->sceneC == 1)//1�Ȃ甠�\��
	{
		NewGO<Qkeybox>(0, "qkeybox");
		DeleteGO(this);
	}
	if (game->sceneC == 4)//4�Ȃ���\��
	{
		NewGO<Qdoor>(0, "qdoor");
		DeleteGO(this);
	}
	if (game->sceneC == 5)//5�Ȃ�I�\��
	{
		NewGO<Qshelf>(0, "qshelf");
		DeleteGO(this);
	}

	//���E�̃{�^���������ꂽ�王�_�ؑ�
	if (g_pad[0]->IsTrigger(enButtonLeft))
	{
		NewGO<room2>(0, "room2");
		DeleteGO(this);
	}
	if (g_pad[0]->IsTrigger(enButtonRight))
	{
		NewGO<room4>(0, "room4");
		DeleteGO(this);
	}
	////�ĕ\�������Ȃ������
	//if (game->reshow == true || game->reshowing == true)
	//{
	//	DeleteGO(this);
	//}
}

void room3::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}
