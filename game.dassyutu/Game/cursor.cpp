#include "stdafx.h"
#include "cursor.h"
#include "room1.h"
#include "room2.h"
#include "room3.h"
#include "room4.h"
#include "Game.h"
#include "Item.h"
#include "Qbutton.h"
#include "Qshelf.h"
#include "Qice.h"
#include "Qkeyboxdial1.h"
#include "Qkeyboxdial2.h"
#include "Qkeyboxdial3.h"
#include "Qkeyboxdial4.h"
#include "Qkeyboxdial5.h"
#include "Qkeyboxdial6.h"
#include "Qkeybox.h"
#include "Qbooks.h"
#include "Qsafe.h"
#include "Qsafejedial1.h"
#include "Qsafejedial2.h"
#include "Qsafejedial3.h"
#include "Qsafetadial1.h"
#include "Qsafetadial2.h"
#include "Qsafetadial3.h"
#include "Qmoon.h"
#include "Qdoordial1.h"
#include "Qdoordial2.h"
#include "Qdoordial3.h"
#include "Qdoordial4.h"
#include "Qdoordial5.h"
#include "Qdoordial6.h"
#include "Qdoordial7.h"
#include "Clear.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

cursor::cursor()
{
	//画像表示
	spriteRender.Init("Assets/sprite/point.DDS",100.0f,100.0f);

	wchar_t buttonhint[256];
	swprintf_s(buttonhint, 256, L"X＝操作方法、Y＝ヒント");
	//表示するテキストを設定。
	fontRender.SetText(buttonhint);
	//フォントの位置を設定。
	fontRender.SetPosition(Vector3(-950.0f, 525.0f, 0.0f));
	//フォントの大きさを設定。
	fontRender.SetScale(1.0f);

	//一応ダイアル音
	g_soundEngine->ResistWaveFileBank(5, "Assets/sound/pushbutton38.wav");

	//一応ボタン音
	g_soundEngine->ResistWaveFileBank(1, "Assets/sound/pushbutton7.wav");

	//一応本の音
	g_soundEngine->ResistWaveFileBank(8, "Assets/sound/closebook2.wav");

	//一応ドアを叩く音
	g_soundEngine->ResistWaveFileBank(13, "Assets/sound/panchingdoor.wav");
}

cursor::~cursor()
{

}

void cursor::Update()
{	
	game = FindGO<Game>("game");
	item = FindGO<Item>("item");

	//スティックの入力量を取得
	Vector3 stickL;
	stickL.x = g_pad[0]->GetLStickXF();
	stickL.y = g_pad[0]->GetLStickYF();

	//positionに加算
	position.x += stickL.x * 25.0f;
	position.y += stickL.y * 25.0f;

	//座標確認用////////////////////////////////////////////
	

		//wchar_t pointx[256];
		//swprintf_s(pointx, 256, L"x座標:%d", int(position.x));
		////表示するテキストを設定。
		//fontRender.SetText(pointx);
		////フォントの位置を設定。
		//fontRender.SetPosition(Vector3(200.0f, 200.0f, 0.0f));
		////フォントの大きさを設定。
		//fontRender.SetScale(2.0f);

		//wchar_t pointy[256];
		//swprintf_s(pointy, 256, L"y座標:%d", int(position.y));
		////表示するテキストを設定。
		//fontRender.SetText(pointy);
		////フォントの位置を設定。
		//fontRender.SetPosition(Vector3(200.0f, 300.0f, 0.0f));
		////フォントの大きさを設定。
		//fontRender.SetScale(2.0f);

	
	//下にも残りあり///////////////////////////////////////


	//カーソルの移動制限
	if (position.x > 950.0)
	{
		position.x = 950;
	}
	else if (position.x < -950.0)
	{
		position.x = -950;
	}

	if (position.y > 500)
	{
		position.y = 500;
	}
	else if (position.y < -500)
	{
		position.y = -500;
	}

	//操作方法とヒントの表示切替処理
	if (game->reshow != true && game->reshowing != true && g_pad[0]->IsTrigger(enButtonX))
	{
		game->reshow = true;
	}
	else if (game->reshowing == true && g_pad[0]->IsTrigger(enButtonX))
	{
		game->reshowing = false;
	}

	if (game->givehint == false && g_pad[0]->IsTrigger(enButtonY))
	{
		game->givehint = true;
	}
	else if (game->givehint == true && g_pad[0]->IsTrigger(enButtonY))
	{
		game->givehint = false;
	}

	//ヒントも操作方法も表示していないとき
	if (game->reshowing == false && game->reshow == false && game->givehint == false)
	{
		//視点切替のハブ
		switch (game->siten)
		{
		case 1:
			if (game->levela == 0 && game->sceneA == 0)//部屋1の進行度0、部屋1を見ている時、
			{
				if (position.x < 100 && position.x > -100 && position.y < 250
					&& position.y > 50 && g_pad[0]->IsTrigger(enButtonA))//窓(0,150)周辺でAが押されたら
				{
					game->sceneA = 1;//窓へ
				}
				if (position.x < 700 && position.x > 500 && position.y < 250
					&& position.y > 50 && g_pad[0]->IsTrigger(enButtonA))//ボタン(600,150)周辺でAが押されたら
				{
					game->sceneA = 2;//ボタンへ
				}
			}
			else if (game->levela >= 1 && game->sceneA == 0)//部屋1の進行度1以上、部屋1を見ている時、
			{
				if (position.x < -403 && position.x > -844 && position.y < 150
					&& position.y > -300 && g_pad[0]->IsTrigger(enButtonA))//氷(-600,-73)周辺でAが押されたら
				{
					game->sceneA = 3;//氷へ
				}
			}
			break;
		case 2:
			if (game->levelb != 0 && game->sceneB == 0)//部屋2の進行度0以外、部屋2を見ている時、
			{
				if (position.x < -350 && position.x > -915 && position.y < 407
					&& position.y > -343 && g_pad[0]->IsTrigger(enButtonA))//本棚(n,n)周辺でAが押されたら
				{
					game->sceneB = 1;//本棚へ
				}
				else if (position.x < 85 && position.x > -85 && position.y < 308
					&& position.y > 83 && g_pad[0]->IsTrigger(enButtonA))//絵画(n,n)周辺でAが押されたら
				{
					game->sceneB = 7;//絵画へ
				}
				else if (position.x < 739 && position.x > 477 && position.y < 310
					&& position.y > -285 && g_pad[0]->IsTrigger(enButtonA))//時計(n,n)周辺でAが押されたら
				{
					game->sceneB = 6;//時計へ
				}
			}
			else if (game->levelb != 0 && game->sceneB == 1)//部屋2の進行度0以外、空き本棚を見ている時、
			{
				if (position.x < -325 && position.x > -916 && position.y < -155
					&& position.y > -525 && g_pad[0]->IsTrigger(enButtonA))//机(n,n)周辺でAが押されたら
				{
					game->sceneB = 2;//机へ
				}
			}
			else if (game->levelb >= 2 && game->sceneB == 2)//部屋2の進行度2以上、机を見ている時、
			{
				if (position.x < 0 && position.x > -660 && position.y < -226
					&& position.y > -525 && g_pad[0]->IsTrigger(enButtonA))//懐中時計(n,n)周辺でAが押されたら
				{
					game->sceneB = 4;//懐中時計へ
				}
			}
			break;
		case 3:
			if (game->levelc != 0 && game->sceneC == 0)//部屋3の進行度0以外、部屋3を見ている時、
			{
				if (position.x < -362 && position.x > -862 && position.y < 174
					&& position.y > 71 && g_pad[0]->IsTrigger(enButtonA))//鍵箱(n,n)周辺でAが押されたら
				{
					game->sceneC = 1;//鍵箱へ
				}
				else if (position.x < 82 && position.x > -112 && position.y < 334
					&& position.y > 253 && g_pad[0]->IsTrigger(enButtonA))//扉(n,n)周辺でAが押されたら
				{
					game->sceneC = 4;//扉へ
				}
				else if (position.x < 706 && position.x > 506 && position.y < 139
					&& position.y > 42 && g_pad[0]->IsTrigger(enButtonA))//棚(n,n)周辺でAが押されたら
				{
					game->sceneC = 5;//棚へ
				}
				else if(position.x < 200 && position.x > -230 && position.y < 250
					&& position.y > -200 && g_pad[0]->IsTrigger(enButtonA))//扉本体(n,n)周辺でAが押されたら
				{
					SoundSource* doorse = NewGO<SoundSource>(0);
					doorse->Init(13);
					doorse->Play(false);
					doorse->SetVolume(3.5f);//扉を殴る
				}
			}
			else if (game->levelc != 0 && game->sceneC == 1)//部屋3の進行度0以外、鍵箱を見ている時、
			{
				if (position.x < 400 && position.x > -517 && position.y < 196
					&& position.y > 114 && g_pad[0]->IsTrigger(enButtonA))//ダイヤル付近でAが押されたら
				{
					game->sceneC = 2;//ダイヤルへ
				}
			}
			else if (game->levelc != 0 && game->sceneC == 4)//部屋3の進行度0以外、扉を見ている時、
			{
				if (position.x < 400 && position.x > -377 && position.y < 125
					&& position.y > -45 && g_pad[0]->IsTrigger(enButtonA))//ダイヤル付近でAが押されたら
				{
					game->sceneC = 3;//ダイヤルへ
				}
			}
			break;
		case 4:
			if (game->leveld != 0 && game->sceneD == 0)//部屋3の進行度0以外、部屋4を見ている時、
			{
				if (position.x < -536 && position.x > -974 && position.y < 272
					&& position.y > -452 && g_pad[0]->IsTrigger(enButtonA))//宝石(n,n)周辺でAが押されたら
				{
					game->sceneD = 1;//宝石へ
				}
				else if (position.x < 892 && position.x > 528 && position.y < 424
					&& position.y > 10 && g_pad[0]->IsTrigger(enButtonA))//的(n,n)周辺でAが押されたら
				{
					game->sceneD = 6;//的へ
				}
			}
			if (game->leveld >= 2 && game->sceneD == 0)
			{
				if (position.x < 188 && position.x > -247 && position.y < 55
					&& position.y > -373 && g_pad[0]->IsTrigger(enButtonA))//金庫(n,n)周辺でAが押されたら
				{
					game->sceneD = 3;//金庫へ
				}
			}
			else if (game->leveld >= 2 && game->leveld < 4 && game->sceneD == 3)
			{
				if (position.x < 375 && position.x > -330 && position.y < 40
					&& position.y > -100 && g_pad[0]->IsTrigger(enButtonA))//宝石側周辺でAが押されたら
				{
					game->sceneD = 4;//宝石側のダイアルへ
				}
				if (position.x < 375 && position.x > -330 && position.y < -260
					&& position.y > -425 && g_pad[0]->IsTrigger(enButtonA))//ナイフ側周辺でAが押されたら
				{
					game->sceneD = 5;//ナイフ側のダイアルへ
				}
			}
			break;
		default:
			break;
		}

		//視点戻しのハブ
		if (g_pad[0]->IsTrigger(enButtonB))
		{
			switch (game->siten)
			{
			case 1:
				//部屋以外なら部屋に
				if (game->sceneA != 0)
				{
					game->sceneA = 0;
				}
				break;
			case 2:
				//懐中時計なら(本の)机に
				if (game->sceneB == 4)
				{
					game->sceneB = 2;
				}
				//本の机なら本棚に
				else if (game->sceneB == 2)
				{
					game->sceneB = 1;
				}
				//これらと部屋以外なら部屋に
				else if (game->sceneB != 0)
				{
					game->sceneB = 0;
				}
				break;
			case 3:
				//鍵箱のダイアル画面なら
				if (game->sceneC == 2)
				{
					//鍵箱へ
					game->sceneC = 1;
				}
				//扉のダイアルなら扉へ
				else if (game->sceneC == 3)
				{
					game->sceneC = 4;
				}
				//これらと部屋以外なら部屋に
				else if (game->sceneC != 0)
				{
					game->sceneC = 0;
				}
				break;
			case 4:
				//ダイヤルなら金庫に
				if (game->sceneD == 4 || game->sceneD == 5)
				{
					game->sceneD = 3;
				}
				//それと部屋以外なら部屋に
				else if (game->sceneD != 0)
				{
					game->sceneD = 0;
				}
				break;
			default:
				break;
			}
		}

		//ボタンの謎
		if (game->sceneA == 2)
		{
			//if (qbutton == NULL)
			//{
			qbutton = FindGO<Qbutton>("qbutton");
		//}

			if (qbutton != NULL && position.x < -322 && position.x > -407 && position.y < 46
				&& position.y > -48 && g_pad[0]->IsTrigger(enButtonA))//赤でAが押されたら
			{
				SoundSource* buttonse = NewGO<SoundSource>(0);
				buttonse->Init(1);
				buttonse->Play(false);
				buttonse->SetVolume(3.5f);

				switch (qbutton->push)
				{
				case 0:
					qbutton->push = 100;
					break;
				case 10:
					qbutton->push = 110;
					break;
				case 1:
					qbutton->push = 101;
					break;
				case 11:
					qbutton->push = 111;
					break;
				default:
					break;
				}

			}
			if (qbutton != NULL && position.x < -24 && position.x > -114 && position.y < 46
				&& position.y > -48 && g_pad[0]->IsTrigger(enButtonA))//黄でAが押されたら
			{
				SoundSource* buttonse = NewGO<SoundSource>(0);
				buttonse->Init(1);
				buttonse->Play(false);
				buttonse->SetVolume(3.5f);

				switch (qbutton->push)
				{
				case 0:
					qbutton->push = 10;
					break;
				case 100:
					qbutton->push = 110;
					break;
				case 1:
					qbutton->push = 11;
					break;
				case 101:
					qbutton->push = 111;
					break;
				default:
					break;
				}
			}
			if (qbutton != NULL && position.x < 267 && position.x > 186 && position.y < 46
				&& position.y > -48 && g_pad[0]->IsTrigger(enButtonA))//白でAが押されたら
			{
				SoundSource* buttonse = NewGO<SoundSource>(0);
				buttonse->Init(1);
				buttonse->Play(false);
				buttonse->SetVolume(3.5f);

				switch (qbutton->push)
				{
				case 0:
					qbutton->push = 1;
					break;
				case 100:
					qbutton->push = 101;
					break;
				case 10:
					qbutton->push = 11;
					break;
				case 110:
					qbutton->push = 111;
					break;
				default:
					break;
				}
			}
		}


		//氷の謎
		//マッチ回収
		if (game->sceneC == 5)
		{
			//if (qshelf == NULL)
			//{
			qshelf = FindGO<Qshelf>("qshelf");
			//}

				//マッチを取ったことがなく、かつマッチ付近でAが押されたら
			if (qshelf != NULL && item->matti == 0 && position.x < 150 && position.x > -280 && position.y < 181
				&& position.y > -142 && g_pad[0]->IsTrigger(enButtonA))
			{
				qshelf->matti = 0;//マッチ回収中に移行
			}
		}

		if (game->sceneA == 3 && qice == NULL)
		{
			qice = FindGO<Qice>("qice");
		}

		//氷を溶かす
		if (game->sceneA == 3 && qice != NULL)
		{
			//if (qice == NULL)
			//{
			//	qice = FindGO<Qice>("qice");
			//}

			if (qice != NULL && position.x < 439 && position.x > -484 && position.y < 437
				&& position.y > -466 && g_pad[0]->IsTrigger(enButtonA))//氷付近でAが押されたら
			{
				qice->iceselect = true;//氷を選んだフラグを立てる
			}
			else
			{
				qice->iceselect = false;//そうでない時フラグを下ろす
			}
		}

		if (game->sceneC == 2/* && qkeyboxdial1 == NULL*/)
		{
			qkeyboxdial1 = FindGO<Qkeyboxdial1>("qkeyboxdial1");
		//}
		//if (game->sceneC == 2/* && qkeyboxdial2 == NULL*/)
		//{
			qkeyboxdial2 = FindGO<Qkeyboxdial2>("qkeyboxdial2");
		//}
		//if (game->sceneC == 2/* && qkeyboxdial3 == NULL*/)
		//{
			qkeyboxdial3 = FindGO<Qkeyboxdial3>("qkeyboxdial3");
		//}
		//if (game->sceneC == 2/* && qkeyboxdial4 == NULL*/)
		//{
			qkeyboxdial4 = FindGO<Qkeyboxdial4>("qkeyboxdial4");
		//}
		//if (game->sceneC == 2/* && qkeyboxdial5 == NULL*/)
		//{
			qkeyboxdial5 = FindGO<Qkeyboxdial5>("qkeyboxdial5");
		//}
		//if (game->sceneC == 2/* && qkeyboxdial6 == NULL*/)
		//{
			qkeyboxdial6 = FindGO<Qkeyboxdial6>("qkeyboxdial6");
		}

		//鍵箱
		if (game->sceneC == 2 && qkeyboxdial1 != NULL && qkeyboxdial2 != NULL && qkeyboxdial3 != NULL
			&& qkeyboxdial4 != NULL && qkeyboxdial5 != NULL && qkeyboxdial6 != NULL)
		{
			if (position.x < -687 && position.x > -824 && position.y < 120
				&& position.y > -117 && g_pad[0]->IsTrigger(enButtonA))//ダイヤル1でAが押されたら
			{
				SoundSource* dialse = NewGO<SoundSource>(0);
				dialse->Init(5);
				dialse->Play(false);
				dialse->SetVolume(3.5f);

				qkeyboxdial1->k1select++;//ダイヤル1を進める
			}
			if (position.x < -378 && position.x > -521 && position.y < 120
				&& position.y > -117 && g_pad[0]->IsTrigger(enButtonA))//ダイヤル2でAが押されたら
			{
				SoundSource* dialse = NewGO<SoundSource>(0);
				dialse->Init(5);
				dialse->Play(false);
				dialse->SetVolume(3.5f);

				qkeyboxdial2->k2select++;//ダイヤル2を進める
			}
			if (position.x < -82 && position.x > -217 && position.y < 120
				&& position.y > -117 && g_pad[0]->IsTrigger(enButtonA))//ダイヤル3でAが押されたら
			{
				SoundSource* dialse = NewGO<SoundSource>(0);
				dialse->Init(5);
				dialse->Play(false);
				dialse->SetVolume(3.5f);

				qkeyboxdial3->k3select++;//ダイヤル3を進める
			}
			if (position.x < 217 && position.x > 82 && position.y < 120
				&& position.y > -117 && g_pad[0]->IsTrigger(enButtonA))//ダイヤル4でAが押されたら
			{
				SoundSource* dialse = NewGO<SoundSource>(0);
				dialse->Init(5);
				dialse->Play(false);
				dialse->SetVolume(3.5f);

				qkeyboxdial4->k4select++;//ダイヤル4を進める
			}
			if (position.x < 521 && position.x > 378 && position.y < 120
				&& position.y > -117 && g_pad[0]->IsTrigger(enButtonA))//ダイヤル5でAが押されたら
			{
				SoundSource* dialse = NewGO<SoundSource>(0);
				dialse->Init(5);
				dialse->Play(false);
				dialse->SetVolume(3.5f);

				qkeyboxdial5->k5select++;//ダイヤル5を進める
			}
			if (position.x < 824 && position.x > 678 && position.y < 120
				&& position.y > -117 && g_pad[0]->IsTrigger(enButtonA))//ダイヤル6でAが押されたら
			{
				SoundSource* dialse = NewGO<SoundSource>(0);
				dialse->Init(5);
				dialse->Play(false);
				dialse->SetVolume(3.5f);

				qkeyboxdial6->k6select++;//ダイヤル6を進める
			}
		}
		//ナイフ.x(3~-21),y(-364~156)
		if (game->sceneC == 1)
		{
			//if (qkeybox == NULL)
			//{
			qkeybox = FindGO<Qkeybox>("qkeybox");
			//}

				//箱が開いていて、ナイフをとっておらず、ナイフ付近でAが押されたら
			if (qkeybox != NULL && game->openknife == true && item->knife == 0 && position.x < 156 && position.x > -364
				&& position.y < 10 && position.y > -30 && g_pad[0]->IsTrigger(enButtonA))
			{
				qkeybox->knife = 0;//ナイフ回収中に移行
			}
		}

		//小さい的.x(-75~21),y(325~420)
		if (game->sceneD == 0 && game->leveld == 1)
		{
			r4 = FindGO<room4>("room4");
		}

		if (game->sceneD == 0 && game->leveld == 1 && r4 != NULL)
		{
			if (position.x < 21 && position.x > -75 && position.y < 420
				&& position.y > 325 && g_pad[0]->IsTrigger(enButtonA))//的付近でAが押されたら
			{
				r4->throwing = true;//的を選んだフラグを立てる
			}
			else
			{
				r4->throwing = false;//そうでない時フラグを下ろす
			}
		}

		//本の整理
		if (game->sceneB == 2 && game->levelb == 1)
		{
			//if (qbooks == NULL)
			//{
			qbooks = FindGO<Qbooks>("qbooks");
		//}

			if (qbooks != NULL && position.x < -394 && position.x > -861 && position.y < 289
				&& position.y > -161 && g_pad[0]->IsTrigger(enButtonA))//氷でAが押されたら
			{
				SoundSource* bookse = NewGO<SoundSource>(0);
				bookse->Init(8);
				bookse->Play(false);
				bookse->SetVolume(3.5f);

				switch (qbooks->bookselect)
				{
				case 0:
					qbooks->bookselect = 100;
					break;
				case 10:
					qbooks->bookselect = 110;
					break;
				case 1:
					qbooks->bookselect = 101;
					break;
				case 11:
					qbooks->bookselect = 111;
					break;
				default:
					break;
				}

			}
			if (qbooks != NULL && position.x < 192 && position.x > -221 && position.y < 289
				&& position.y > -161 && g_pad[0]->IsTrigger(enButtonA))//睡眠でAが押されたら
			{
				SoundSource* bookse = NewGO<SoundSource>(0);
				bookse->Init(8);
				bookse->Play(false);
				bookse->SetVolume(3.5f);

				switch (qbooks->bookselect)
				{
				case 0:
					qbooks->bookselect = 10;
					break;
				case 100:
					qbooks->bookselect = 110;
					break;
				case 1:
					qbooks->bookselect = 11;
					break;
				case 101:
					qbooks->bookselect = 111;
					break;
				default:
					break;
				}
			}
			if (qbooks != NULL && position.x < 839 && position.x > 352 && position.y < 289
				&& position.y > -161 && g_pad[0]->IsTrigger(enButtonA))//暗闇でAが押されたら
			{
				SoundSource* bookse = NewGO<SoundSource>(0);
				bookse->Init(8);
				bookse->Play(false);
				bookse->SetVolume(3.5f);

				switch (qbooks->bookselect)
				{
				case 0:
					qbooks->bookselect = 1;
					break;
				case 100:
					qbooks->bookselect = 101;
					break;
				case 10:
					qbooks->bookselect = 11;
					break;
				case 110:
					qbooks->bookselect = 111;
					break;
				default:
					break;
				}
			}
		}

		if (game->sceneD == 4/* && qsjedial1 == NULL*/)
		{
			qsjedial1 = FindGO<Qsafejedial1>("qsafejedial1");
			//}
			//if (game->sceneD == 4/* && qsjedial2 == NULL*/)
			//{
			qsjedial2 = FindGO<Qsafejedial2>("qsafejedial2");
			//}
			//if (game->sceneD == 4/* && qsjedial3 == NULL*/)
			//{
			qsjedial3 = FindGO<Qsafejedial3>("qsafejedial3");
		}

		//宝石ダイアル
		if (game->sceneD == 4 && qsjedial1 != NULL && qsjedial2 != NULL && qsjedial3 != NULL)
		{
			if (position.x < -350 && position.x > -550 && position.y < 150
				&& position.y > -150 && g_pad[0]->IsTrigger(enButtonA))//ダイヤル1でAが押されたら
			{
				SoundSource* dialse = NewGO<SoundSource>(0);
				dialse->Init(5);
				dialse->Play(false);
				dialse->SetVolume(3.5f);

				qsjedial1->j1select++;//ダイヤル1を進める
			}
			if (position.x < 100 && position.x > -100 && position.y < 150
				&& position.y > -150 && g_pad[0]->IsTrigger(enButtonA))//ダイヤル2でAが押されたら
			{
				SoundSource* dialse = NewGO<SoundSource>(0);
				dialse->Init(5);
				dialse->Play(false);
				dialse->SetVolume(3.5f);

				qsjedial2->j2select++;//ダイヤル2を進める
			}
			if (position.x < 550 && position.x > 350 && position.y < 150
				&& position.y > -150 && g_pad[0]->IsTrigger(enButtonA))//ダイヤル3でAが押されたら
			{
				SoundSource* dialse = NewGO<SoundSource>(0);
				dialse->Init(5);
				dialse->Play(false);
				dialse->SetVolume(3.5f);

				qsjedial3->j3select++;//ダイヤル3を進める
			}
		}


		if (game->sceneD == 5/* && qstadial1 == NULL*/)
		{
			qstadial1 = FindGO<Qsafetadial1>("qsafetadial1");
			//}
			//if (game->sceneD == 5/* && qstadial2 == NULL*/)
			//{
			qstadial2 = FindGO<Qsafetadial2>("qsafetadial2");
			//}
			//if (game->sceneD == 5/* && qstadial3 == NULL*/)
			//{
			qstadial3 = FindGO<Qsafetadial3>("qsafetadial3");
		}


		//ナイフダイアル
		if (game->sceneD == 5 && qstadial1 != NULL && qstadial2 != NULL && qstadial3 != NULL)
		{
			if (position.x < -350 && position.x > -550 && position.y < 150
				&& position.y > -150 && g_pad[0]->IsTrigger(enButtonA))//ダイヤル1でAが押されたら
			{
				SoundSource* dialse = NewGO<SoundSource>(0);
				dialse->Init(5);
				dialse->Play(false);
				dialse->SetVolume(3.5f);

				qstadial1->t1select++;//ダイヤル1を進める
			}
			if (position.x < 100 && position.x > -100 && position.y < 150
				&& position.y > -150 && g_pad[0]->IsTrigger(enButtonA))//ダイヤル2でAが押されたら
			{
				SoundSource* dialse = NewGO<SoundSource>(0);
				dialse->Init(5);
				dialse->Play(false);
				dialse->SetVolume(3.5f);

				qstadial2->t2select++;//ダイヤル2を進める
			}
			if (position.x < 550 && position.x > 350 && position.y < 150
				&& position.y > -150 && g_pad[0]->IsTrigger(enButtonA))//ダイヤル3でAが押されたら
			{
				SoundSource* dialse = NewGO<SoundSource>(0);
				dialse->Init(5);
				dialse->Play(false);
				dialse->SetVolume(3.5f);

				qstadial3->t3select++;//ダイヤル3を進める
			}
		}

		//金庫内のアイテム
		if (game->sceneD == 3)
		{
			//if (qsafe == NULL)
			//{
			qsafe = FindGO<Qsafe>("qsafe");
			//}

				//金庫が開いていて、紙をとっておらず、紙付近でAが押されたら
			if (qsafe != NULL && game->leveld >= 4 && item->paper == 0 && position.x < 410 && position.x > -45
				&& position.y < 0 && position.y > -400 && g_pad[0]->IsTrigger(enButtonA))
			{
				qsafe->paper = 1;//紙回収中に移行
			}
		}

		//月
		if (game->sceneB == 7 && qmoon == NULL)
		{
			qmoon = FindGO<Qmoon>("qmoon");
		}

		if (game->sceneB == 7 && qmoon != NULL)
		{
			//if (qmoon == NULL)
			//{
			//	qmoon = FindGO<Qmoon>("qmoon");
			//}

			if (qmoon != NULL && position.x < 440 && position.x > -310 && position.y < 460
				&& position.y > -460 && g_pad[0]->IsTrigger(enButtonA))//月付近でAが押されたら
			{
				qmoon->mselect = true;//月を選んだフラグを立てる
			}
			else
			{
				qmoon->mselect = false;//そうでない時フラグを下ろす
			}
		}


		//最後の謎
		/*if (game->sceneC == 3 && qdoordial1 == NULL)
		{
			qdoordial1 = FindGO<Qdoordial1>("qdoordial1");
		}
		if (game->sceneC == 3 && qdoordial2 == NULL)
		{
			qdoordial2 = FindGO<Qdoordial2>("qdoordial2");
		}
		if (game->sceneC == 3 && qdoordial3 == NULL)
		{
			qdoordial3 = FindGO<Qdoordial3>("qdoordial3");
		}
		if (game->sceneC == 3 && qdoordial4 == NULL)
		{
			qdoordial4 = FindGO<Qdoordial4>("qdoordial4");
		}
		if (game->sceneC == 3 && qdoordial5 == NULL)
		{
			qdoordial5 = FindGO<Qdoordial5>("qdoordial5");
		}
		if (game->sceneC == 3 && qdoordial6 == NULL)
		{
			qdoordial6 = FindGO<Qdoordial6>("qdoordial6");
		}
		if (game->sceneC == 3 && qdoordial7 == NULL)
		{
			qdoordial7 = FindGO<Qdoordial7>("qdoordial7");
		}*/

		//扉
		if (game->sceneC == 3/* && qdoordial1 != NULL && qdoordial2 != NULL && qdoordial3 != NULL
			&& qdoordial4 != NULL && qdoordial5 != NULL && qdoordial6 != NULL && qdoordial7 != NULL*/)
		{
			
			qdoordial1 = FindGO<Qdoordial1>("qdoordial1");
			qdoordial2 = FindGO<Qdoordial2>("qdoordial2");
			qdoordial3 = FindGO<Qdoordial3>("qdoordial3");
			qdoordial4 = FindGO<Qdoordial4>("qdoordial4");
			qdoordial5 = FindGO<Qdoordial5>("qdoordial5");
			qdoordial6 = FindGO<Qdoordial6>("qdoordial6");
			qdoordial7 = FindGO<Qdoordial7>("qdoordial7");

			if (qdoordial1 != NULL && qdoordial2 != NULL && qdoordial3 != NULL
				&& qdoordial4 != NULL && qdoordial5 != NULL && qdoordial6 != NULL && qdoordial7 != NULL)
			{
				if (position.x < -650 && position.x > -850 && position.y < 175
					&& position.y > -175 && g_pad[0]->IsTrigger(enButtonA))//ダイヤル1でAが押されたら
				{
					SoundSource* dialse = NewGO<SoundSource>(0);
					dialse->Init(5);
					dialse->Play(false);
					dialse->SetVolume(3.5f);

					qdoordial1->d1select++;//ダイヤル1を進める
				}
				if (position.x < -400 && position.x > -600 && position.y < 175
					&& position.y > -175 && g_pad[0]->IsTrigger(enButtonA))//ダイヤル2でAが押されたら
				{
					SoundSource* dialse = NewGO<SoundSource>(0);
					dialse->Init(5);
					dialse->Play(false);
					dialse->SetVolume(3.5f);

					qdoordial2->d2select++;//ダイヤル2を進める
				}
				if (position.x < -150 && position.x > -350 && position.y < 175
					&& position.y > -175 && g_pad[0]->IsTrigger(enButtonA))//ダイヤル3でAが押されたら
				{
					SoundSource* dialse = NewGO<SoundSource>(0);
					dialse->Init(5);
					dialse->Play(false);
					dialse->SetVolume(3.5f);

					qdoordial3->d3select++;//ダイヤル3を進める
				}
				if (position.x < 100 && position.x > -100 && position.y < 175
					&& position.y > -175 && g_pad[0]->IsTrigger(enButtonA))//ダイヤル4でAが押されたら
				{
					SoundSource* dialse = NewGO<SoundSource>(0);
					dialse->Init(5);
					dialse->Play(false);
					dialse->SetVolume(3.5f);

					qdoordial4->d4select++;//ダイヤル4を進める
				}
				if (position.x < 350 && position.x > 150 && position.y < 175
					&& position.y > -175 && g_pad[0]->IsTrigger(enButtonA))//ダイヤル5でAが押されたら
				{
					SoundSource* dialse = NewGO<SoundSource>(0);
					dialse->Init(5);
					dialse->Play(false);
					dialse->SetVolume(3.5f);

					qdoordial5->d5select++;//ダイヤル5を進める
				}
				if (position.x < 600 && position.x > 400 && position.y < 175
					&& position.y > -175 && g_pad[0]->IsTrigger(enButtonA))//ダイヤル6でAが押されたら
				{
					SoundSource* dialse = NewGO<SoundSource>(0);
					dialse->Init(5);
					dialse->Play(false);
					dialse->SetVolume(3.5f);

					qdoordial6->d6select++;//ダイヤル6を進める
				}
				if (position.x < 850 && position.x > 650 && position.y < 175
					&& position.y > -175 && g_pad[0]->IsTrigger(enButtonA))//ダイヤル7でAが押されたら
				{
					SoundSource* dialse = NewGO<SoundSource>(0);
					dialse->Init(5);
					dialse->Play(false);
					dialse->SetVolume(3.5f);

					qdoordial7->d7select++;//ダイヤル7を進める
				}
			}
		}
	}

	//clearがNULLなら探す
	if (clear == NULL)
	{
		clear = FindGO<Clear>("clear");
	}
	//NULLじゃないなら終わる
	else
	{
		DeleteGO(this);
	}

	spriteRender.SetPosition(position);
	spriteRender.Update();
}

void cursor::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
	
	
	fontRender.Draw(rc);
	

	//元確認用
	/*fontRender.Draw(rc);*/
}
