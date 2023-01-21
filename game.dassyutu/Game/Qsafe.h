#pragma once
#include "sound/SoundSource.h"

class Game;
class room4;
class Item;

class Qsafe :public IGameObject
{
public:

	Qsafe();
	~Qsafe();
	void Update();
	void Render(RenderContext& rc);

	bool safechange = true;

	bool modedial = false;
		
	bool sclearflag[6];
	int paper;
	//0‚Å‚ ‚é
	//1‚Å‰ñû’†
	//2‚Å‰ñûÏ


	Game* game;
	room4* r4;
	Item* item;

	SpriteRender spriteRender;
	//SoundSource* bgm;

};