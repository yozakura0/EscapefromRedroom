#include "stdafx.h"
#include "Qjewel.h"
#include "room4.h"
#include "Game.h"

Qjewel::Qjewel()
{
	game = FindGO<Game>("game");

	//�i�s�x�ɉ����ĕ\���ؑ�
	if (game->levelb >= 2 && game->leveld >= 2)
	{
		spriteRender.Init("Assets/sprite/room4-jewel.DDS", 1920.0f, 1080.0f);
	}
	else
	{
		spriteRender.Init("Assets/sprite/room4-jewel.n.DDS", 1920.0f, 1080.0f);
	}
}

Qjewel::~Qjewel()
{

}

void Qjewel::Update()
{
	game = FindGO<Game>("game");

	//�V�[���̒l�ɂ���Č���ꏊ��ύX
	if (game->sceneD == 0)
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

void Qjewel::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}