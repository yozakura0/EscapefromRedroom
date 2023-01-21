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

	//room1読み込み
	NewGO<room1>(0, "room1");
	//アイテム読み込み
	NewGO<Item>(1,"item");
	//カーソル読み込み
	NewGO<cursor>(3, "cursor");


	return true;
}

void Game::Update()
{
	clear = FindGO<Clear>("clear");

	//クリア時の全部屋初期化処理
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

	//再スタート処理
	if (restart == true)
	{
		restart = false;

		//room1読み込み
		NewGO<room1>(0, "room1");
		//アイテム読み込み
		NewGO<Item>(1, "item");
		//カーソル読み込み
		NewGO<cursor>(3, "cursor");
	}

	//操作方法表示処理
	if (reshow == true)
	{
		reshow = false;
		reshowing = true;
		NewGO<aftersousa>(4, "aftersousa");
	}
	
	//ヒント表示処理
	if (givehint == true)
	{
		NewGO<hint>(4, "hint");
	}

	// g_renderingEngine->DisableRaytracing();
	//m_modelRender.Update();

}