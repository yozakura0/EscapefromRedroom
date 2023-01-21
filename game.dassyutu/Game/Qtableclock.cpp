#include "stdafx.h"
#include "Qtableclock.h"
#include "Qbooks.h"
#include "Game.h"

Qtableclock::Qtableclock()
{
	spriteRender.Init("Assets/sprite/room 2-table&clock.DDS", 1920.0f, 1080.0f);

	qbooks = FindGO<Qbooks>("qbooks");
	game = FindGO<Game>("game");
}

void Qtableclock::Update()
{
	game = FindGO<Game>("game");

	//�V�[���̒l�ɂ���Č���ꏊ��ύX
	if (game->sceneB == 2)
	{
		NewGO<Qbooks>(0, "qbooks");
		DeleteGO(this);
	}
	////�ĕ\�������Ȃ������
	//if (game->reshow == true || game->reshowing == true)
	//{
	//	DeleteGO(this);
	//}
}

void Qtableclock::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}