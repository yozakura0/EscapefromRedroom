#pragma once

#include "Level3DRender/LevelRender.h"
class Clear;

class Game : public IGameObject
{
public:
	Game() {}
	~Game() {}
	bool Start();
	void Update();
	Vector3 position;

	int siten;
	int sceneA = 0;
	/*シーンA割り当て
	0,部屋1
	1.窓
	2.ボタン(無し,r,y,w,ry,rw,yw,全)
	3.氷、ボード
	*/
	int sceneB = 0;
	/*シーンB割り当て
	0,部屋2
	1,本棚(空き)
	2,本(全,睡暗,氷暗,氷睡,暗,氷,睡,無)、懐中時計
	4,懐中時計(ズーム)
	6,時計(短針0～7それぞれにつき長針0～7,計64/尚2次配列で仕分け？)
	7,絵画(月)
	*/
	int sceneC = 0;
	/*シーンC割り当て
	0,部屋3
	1,鍵箱
	2,ダイアル(鍵箱)
	3,ダイアル(扉)
	4,扉
	5,棚(マッチ)
	6,棚
	*/
	int sceneD = 0;
	/*シーンD割り当て
	0,部屋4
	1,ジュエル(無色)
	2,ジュエル(光)
	3,金庫
	4,金庫(ダイヤル:宝石)
	5,金庫(ダイヤル:ナイフ)
	6,的
	7,的+ナイフ
	*/
	bool openknife = false;

	int levela = 0;
	int levelb = 0;
	int levelc = 0;
	int leveld = 0;

	Clear* clear;

	bool restart = false;

	bool reshow = false;
	bool reshowing = false;

	bool givehint = false;
};

