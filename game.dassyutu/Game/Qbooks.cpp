#include "stdafx.h"
#include "Qbooks.h"
#include "Qbookshelf.h"
#include "Qtableclock.h"
#include "Game.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Qbooks::Qbooks()
{
	game = FindGO<Game>("game");

	//�i�s�x�ɉ����ĕ\���ؑ�
	switch (game->levelb)
	{
	case 1:
		spriteRender.Init("Assets/sprite/room 2-book1.DDS", 1920.0f, 1080.0f);
		break;
	case 2:
	case 3:
	case 4:
		spriteRender.Init("Assets/sprite/room 2-book3.DDS", 1920.0f, 1080.0f);
		break;
	default:
		break;
	}

	booksave = bookselect;

	//�������̉��A�s�������̉�
	g_soundEngine->ResistWaveFileBank(2, "Assets/sound/seikai.wav");
	g_soundEngine->ResistWaveFileBank(13, "Assets/sound/huseikai.wav");
}

Qbooks::~Qbooks()
{
	//change��false�Ȃ烊�X�^�[�g
	if (bookchange == false)
	{
		bookchange = true;
		NewGO<Qbooks>(0, "qbooks");
	}
}

void Qbooks::Update()
{
	game = FindGO<Game>("game");

	//�{�̔���
	if (booksave != bookselect)
	{
		switch (bookselect)
		{
		case 100:
			spriteRender.Init("Assets/sprite/room 2-book2(sk).DDS", 1920.0f, 1080.0f);
			booksave = bookselect;
			clearFlag = 0;
			break;
		case 10:
			spriteRender.Init("Assets/sprite/room 2-book2(tk).DDS", 1920.0f, 1080.0f);
			booksave = bookselect;
			clearFlag = 0;
			break;
		case 1:
			spriteRender.Init("Assets/sprite/room 2-book2(ts).DDS", 1920.0f, 1080.0f);
			booksave = bookselect;
			break;
		case 110:
			spriteRender.Init("Assets/sprite/room 2-book2(k).DDS", 1920.0f, 1080.0f);
			booksave = bookselect;
			clearFlag = 0;
			break;
		case 101:
			spriteRender.Init("Assets/sprite/room 2-book2(s).DDS", 1920.0f, 1080.0f);
			booksave = bookselect;
			break;
		case 11:
			spriteRender.Init("Assets/sprite/room 2-book2(t).DDS", 1920.0f, 1080.0f);
			booksave = bookselect;
			clearFlag = 0;
			break;
		case 111:
			if (clearFlag == 1)
			{
				spriteRender.Init("Assets/sprite/room 2-book3.DDS", 1920.0f, 1080.0f);
				//��(����)///////////
				SoundSource* seikaise = NewGO<SoundSource>(0);
				seikaise->Init(2);
				seikaise->Play(false);
				seikaise->SetVolume(3.5f);

				bookselect = 1111;

				game->levelb = 2;
			}
			else
			{
				//�s������
				SoundSource* huseikaise = NewGO<SoundSource>(0);
				huseikaise->Init(13);
				huseikaise->Play(false);
				huseikaise->SetVolume(3.5f);

				clearFlag = 1;
				bookselect = 0;
				booksave = bookselect;
				bookchange = false;
				DeleteGO(this);
			}
			break;
		default:
			break;
		}
	}

	//�V�[���̒l�ɂ���Č���ꏊ��ύX
	if (game->sceneB == 4)
	{
		NewGO<Qtableclock>(0, "qtableclock");
		DeleteGO(this);
	}
	if (game->sceneB == 1)
	{
		NewGO<Qbookshelf>(0, "qbookshelf");
		DeleteGO(this);
	}
	////�ĕ\�������Ȃ������
	//if (game->reshow == true || game->reshowing == true)
	//{
	//	DeleteGO(this);
	//}
}

void Qbooks::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}