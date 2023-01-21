#include "stdafx.h"
#include "Qbutton.h"
#include "room1.h"
#include "Game.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Qbutton::Qbutton()
{
	spriteRender.Init("Assets/sprite/room 1-button.DDS", 1920.0f, 1080.0f);

	game = FindGO<Game>("game");

	pushsave = push;

	//�����A�s������
	g_soundEngine->ResistWaveFileBank(2, "Assets/sound/seikai.wav");
	g_soundEngine->ResistWaveFileBank(13, "Assets/sound/huseikai.wav");
}

Qbutton::~Qbutton()
{
	//change��false�Ȃ烊�X�^�[�g
	if (buttonchange == false)
	{
		buttonchange = true;
		NewGO<Qbutton>(0, "qbutton");
	}
}

void Qbutton::Update()
{
	game = FindGO<Game>("game");

	//�{�^������
	if (pushsave != push)
	{
		switch (push)
		{
		case 100:
			spriteRender.Init("Assets/sprite/room 1-button.r.DDS", 1920.0f, 1080.0f); 
			pushsave = push;
			break;
		case 10:
			spriteRender.Init("Assets/sprite/room 1-button.y.DDS", 1920.0f, 1080.0f);
			pushsave = push;
			clearFlag = 0;
			break;
		case 1:
			spriteRender.Init("Assets/sprite/room 1-button.w.DDS", 1920.0f, 1080.0f);
			pushsave = push;
			clearFlag = 0;
			break;
		case 110:
			spriteRender.Init("Assets/sprite/room 1-button.ry.DDS", 1920.0f, 1080.0f);
			pushsave = push;
			break;
		case 101:
			spriteRender.Init("Assets/sprite/room 1-button.rw.DDS", 1920.0f, 1080.0f);
			pushsave = push;
			clearFlag = 0;
			break;
		case 11:
			spriteRender.Init("Assets/sprite/room 1-button.yw.DDS", 1920.0f, 1080.0f);
			pushsave = push;
			clearFlag = 0;
			break;
		case 111:
			if (clearFlag == 1)
			{
				spriteRender.Init("Assets/sprite/room 1-button.all.DDS", 1920.0f, 1080.0f);
				//�i�s�x����
				game->levela = 1;
				game->levelb = 1;
				game->levelc = 1;
				game->leveld = 1;

				//��(����)///////////
				SoundSource* seikaise = NewGO<SoundSource>(0);
				seikaise->Init(2);
				seikaise->Play(false);
				seikaise->SetVolume(3.5f);

				//1�b�ҋ@
				//for (int i = 0; i < 30; i++);
				//�Â������\��
				//spriteRender.Init("Assets/sprite/room 1-first.DDS", 1920.0f, 1080.0f);
				//1�b�ҋ@
				//for (int i = 0; i < 30; i++) {};
				//�V�[��A��߂��ĕ���1��
				//�X�C�b�`�̉��H/////////////
				game->sceneA = 0;
			}
			else
			{
				//�s������
				SoundSource* huseikaise = NewGO<SoundSource>(0);
				huseikaise->Init(13);
				huseikaise->Play(false);
				huseikaise->SetVolume(3.5f);

				clearFlag = 1;
				push = 0;
				pushsave = push;
				buttonchange = false;
				DeleteGO(this);
			}
			break;
		default:
			break;
		}
	}
	
	//�V�[���̒l�ɂ���Č���ꏊ��ύX
	if (game->sceneA == 0)
	{
		push = 0;
		NewGO<room1>(0, "room1");
		DeleteGO(this);
	}
	////�ĕ\�������Ȃ������
	//if (game->reshow == true || game->reshowing == true)
	//{
	//	DeleteGO(this);
	//}

}

void Qbutton::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}
