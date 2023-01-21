#include "stdafx.h"
#include "Game.h"
#include "room1.h"
#include "cursor.h"
#include "Item.h"
#include "Clear.h"
#include "aftersousa.h"
#include "hint.h"


bool Game::Start()
{

	//room1�ǂݍ���
	NewGO<room1>(0, "room1");
	//�A�C�e���ǂݍ���
	NewGO<Item>(1,"item");
	//�J�[�\���ǂݍ���
	NewGO<cursor>(3, "cursor");


	return true;
}

void Game::Update()
{
	clear = FindGO<Clear>("clear");

	//�N���A���̑S��������������
	if (clear != NULL && clear->finish == true)
	{
		openknife = false;

		siten = 0;

		levela = 0;
		levelb = 0;
		levelc = 0;
		leveld = 0;

		sceneA = 0;
		sceneB = 0;
		sceneC = 0;
		sceneD = 0;
	}

	//�ăX�^�[�g����
	if (restart == true)
	{
		restart = false;

		//room1�ǂݍ���
		NewGO<room1>(0, "room1");
		//�A�C�e���ǂݍ���
		NewGO<Item>(1, "item");
		//�J�[�\���ǂݍ���
		NewGO<cursor>(3, "cursor");
	}

	//������@�\������
	if (reshow == true)
	{
		reshow = false;
		reshowing = true;
		NewGO<aftersousa>(4, "aftersousa");
	}
	
	//�q���g�\������
	if (givehint == true)
	{
		NewGO<hint>(4, "hint");
	}

	// g_renderingEngine->DisableRaytracing();
	//m_modelRender.Update();

}