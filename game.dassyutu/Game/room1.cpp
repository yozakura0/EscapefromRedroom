#include "stdafx.h"
#include "room1.h"
#include "room2.h"
#include "room4.h"
#include "Game.h"
#include "Qwindow.h"
#include "Qice.h"
#include "Qbutton.h"

room1::room1()
{

	game = FindGO<Game>("game");

	//�i�s�x�𔻒肵�ĕ\��
	switch (game->levela)
	{
	//0�Ȃ�first
	case 0:
		spriteRender.Init("Assets/sprite/room 1-first.DDS", 1920.0f, 1080.0f);
		break;
	//1�Ȃ�second
	case 1:
		spriteRender.Init("Assets/sprite/room 1-second.DDS", 1920.0f, 1080.0f);
		break;
	//2�Ȃ�third
	case 2:
		spriteRender.Init("Assets/sprite/room 1-third.DDS", 1920.0f, 1080.0f);
		break;
	default:
		break;
	}

	game->siten = 1;
}

room1::~room1()
{

}

void room1::Update()
{
	game = FindGO<Game>("game");
	////�ĕ\�������Ȃ������
	//if (game->reshow == true || game->reshowing == true)
	//{
	//	DeleteGO(this);
	//}

	if (game->sceneA == 1 && game->levela == 0)//1���Â��Ȃ瑋�\��
	{
		NewGO<Qwindow>(0, "qwindow");
		DeleteGO(this);
	}
	if (game->sceneA == 2 && game->levela == 0)//2���Â��Ȃ�{�^���\��
	{
		NewGO<Qbutton>(0, "qbutton");
		DeleteGO(this);
	}
	if (game->sceneA == 3)//3�Ȃ�X�\��
	{
		NewGO<Qice>(0, "qice");
		DeleteGO(this);
	}

	//���E�̃{�^���������ꂽ�王�_�ؑ�
	if (g_pad[0]->IsTrigger(enButtonLeft))
	{
		NewGO<room4>(0, "room4");
		DeleteGO(this);
	}
	if (g_pad[0]->IsTrigger(enButtonRight))
	{
		NewGO<room2>(0, "room2");
		DeleteGO(this);
	}
	
}

void room1::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}