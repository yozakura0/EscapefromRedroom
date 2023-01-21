#include "stdafx.h"
#include "Qdoor.h"
#include "room3.h"
#include "Game.h"
#include "Clear.h"
#include "Qdoordial1.h"
#include "Qdoordial2.h"
#include "Qdoordial3.h"
#include "Qdoordial4.h"
#include "Qdoordial5.h"
#include "Qdoordial6.h"
#include "Qdoordial7.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Qdoor::Qdoor()
{
	spriteRender.Init("Assets/sprite/room3-door.DDS", 1920.0f, 1080.0f);

	game = FindGO<Game>("game");

	//ドアの音
	g_soundEngine->ResistWaveFileBank(12, "Assets/sound/opendoor3.wav");
}

Qdoor::~Qdoor()
{

}

void Qdoor::Update()
{
	game = FindGO<Game>("game");

	//clearflagが全てtrueになったら
	if (dclearflag[0] == true&& dclearflag[1] == true && dclearflag[2] == true && dclearflag[3] == true &&
		dclearflag[4] == true && dclearflag[5] == true && dclearflag[6] == true)
	{
		//ドアを開ける音
		SoundSource* doorse = NewGO<SoundSource>(0);
		doorse->Init(12);
		doorse->Play(false);
		doorse->SetVolume(3.5f);

		game->sceneC = 4;
		NewGO<Clear>(0,"clear");
		DeleteGO(this);
	}

	if (game->sceneC == 0)
	{
		//シーンの値によって見る場所を変更
		NewGO<room3>(0, "room3");
		DeleteGO(this);
	}
	if (game->sceneC == 3 && modedial == false)
	{
		NewGO<Qdoordial1>(1, "qdoordial1");
		NewGO<Qdoordial2>(1, "qdoordial2");
		NewGO<Qdoordial3>(1, "qdoordial3");
		NewGO<Qdoordial4>(1, "qdoordial4");
		NewGO<Qdoordial5>(1, "qdoordial5");
		NewGO<Qdoordial6>(1, "qdoordial6");
		NewGO<Qdoordial7>(1, "qdoordial7");

		modedial = true;
	}
	if (game->sceneC == 4)
	{
		modedial = false;
	}
	////再表示されるなら消える
	//if (game->reshow == true || game->reshowing == true)
	//{
	//	game->sceneC = 4;
	//	DeleteGO(this);
	//}
}

void Qdoor::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}