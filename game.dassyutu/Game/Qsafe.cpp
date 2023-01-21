#include "stdafx.h"
#include "Qsafe.h"
#include "room4.h"
#include "Qsafetadial1.h"
#include "Qsafetadial2.h"
#include "Qsafetadial3.h"
#include "Qsafejedial1.h"
#include "Qsafejedial2.h"
#include "Qsafejedial3.h"
#include "Game.h"
#include "Item.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Qsafe::Qsafe()
{
	game = FindGO<Game>("game");

	//�i�s�x�ɉ����ĕ\���ؑ�
	if (game->leveld == 5)
	{
		spriteRender.Init("Assets/sprite/room4-kinko.open.DDS", 1920.0f, 1080.0f);
	}
	else if (game->leveld == 4)
	{
		spriteRender.Init("Assets/sprite/room4-kinko.open.item.DDS", 1920.0f, 1080.0f);
	}
	else
	{
		spriteRender.Init("Assets/sprite/room4-kinko.DDS", 1920.0f, 1080.0f);
	}

	g_soundEngine->ResistWaveFileBank(6, "Assets/sound/openkey.wav");
	g_soundEngine->ResistWaveFileBank(3, "Assets/sound/piko.wav");
}

Qsafe::~Qsafe()
{
	//�ĕ\��
	if (safechange == false)
	{
		safechange = true;
		NewGO<Qsafe>(0, "qsafe");
	}
}

void Qsafe::Update()
{
	item = FindGO<Item>("item");
	game = FindGO<Game>("game");

	//������3�������炱���ɖ߂鏈��
	if (game->sceneD == 4 && sclearflag[0] == true && sclearflag[1] == true && sclearflag[2] == true)
	{
		game->sceneD = 3;
	}
	if (game->sceneD == 5 && sclearflag[3] == true && sclearflag[4] == true && sclearflag[5] == true)
	{
		game->sceneD = 3;
	}

	//��𖾏���
	if (sclearflag[0] == true && sclearflag[1] == true && sclearflag[2] == true
		&& sclearflag[3] == true && sclearflag[4] == true && sclearflag[5] == true)
	{

		SoundSource* keyse = NewGO<SoundSource>(0);
		keyse->Init(6);
		keyse->Play(false);
		keyse->SetVolume(3.5f);

		game->leveld = 4;
		safechange = false;
		DeleteGO(this);
	}

	//�A�C�e���������
	if (game->leveld == 4 && paper == 1)
	{
		SoundSource* getse = NewGO<SoundSource>(0);
		getse->Init(3);
		getse->Play(false);
		getse->SetVolume(3.5f);

		item->paper = 1;
		paper = 2;
		game->leveld = 5;
		safechange = false;
		DeleteGO(this);
	}

	//�V�[���̒l�ɂ���Č���ꏊ��ύX
	if (game->sceneD == 0)
	{
		NewGO<room4>(0, "room4");
		DeleteGO(this);
	}
	if (game->sceneD == 4 && modedial == false)
	{
		if(sclearflag[0] != true || sclearflag[1] != true || sclearflag[2] != true) 
		{
			NewGO<Qsafejedial1>(1, "qsafejedial1");
			NewGO<Qsafejedial2>(1, "qsafejedial2");
			NewGO<Qsafejedial3>(1, "qsafejedial3");

			modedial = true;
		}
	}
	if (game->sceneD == 5 && modedial == false)
	{
		if(sclearflag[3] != true || sclearflag[4] != true || sclearflag[5] != true) 
		{
			NewGO<Qsafetadial1>(1, "qsafetadial1");
			NewGO<Qsafetadial2>(1, "qsafetadial2");
			NewGO<Qsafetadial3>(1, "qsafetadial3");

			modedial = true;
		}
	}
	if (game->sceneD == 3)
	{
		modedial = false;
	}
	////�ĕ\�������Ȃ������
	//if (game->reshow == true || game->reshowing == true)
	//{
	//	game->sceneD = 3;
	//	DeleteGO(this);
	//}
}

void Qsafe::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}