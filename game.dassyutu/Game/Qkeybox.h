#pragma once
#include "sound/SoundSource.h"

class Game;
class Item;

class Qkeybox :public IGameObject
{
public:

	Qkeybox();
	~Qkeybox();
	void Update();
	void Render(RenderContext& rc);

	int knife;
	//1‚Å‚ ‚é
	//0‚Å‰ñû’†
	//2‚Å‰ñûÏ
	bool kclearflag[6];
	bool modedial = false;

	bool boxchange = true;

	Game* game;
	Item* item;

	SpriteRender spriteRender;
	//SoundSource* bgm;

};