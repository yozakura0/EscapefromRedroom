#include "stdafx.h"
#include "Qbookshelf.h"
#include "room2.h"
#include "Qbooks.h"
#include "Game.h"

Qbookshelf::Qbookshelf()
{
	game = FindGO<Game>("game");

	//�i�s�x�ɉ����ĕ\���ؑ�
	if (game->levelb >= 2)
	{
		spriteRender.Init("Assets/sprite/room 2-bookshelf2.DDS", 1920.0f, 1080.0f);
	}
	else
	{
		spriteRender.Init("Assets/sprite/room 2-bookshelf1.DDS", 1920.0f, 1080.0f);
	}
	
}

Qbookshelf::~Qbookshelf()
{

}

void Qbookshelf::Update()
{
	game = FindGO<Game>("game");

	//�V�[���̒l�ɂ���Č���ꏊ��ύX
	if (game->sceneB == 2)//2�Ȃ�{�\��
	{
		NewGO<Qbooks>(0, "qbooks");
		DeleteGO(this);
	}
	if (game->sceneB == 0)//0�Ȃ畔���\��
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

void Qbookshelf::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}
