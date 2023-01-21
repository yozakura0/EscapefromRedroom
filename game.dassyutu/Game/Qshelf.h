#pragma once
#include "sound/SoundSource.h"

class Game;
class Item;

class Qshelf :public IGameObject
{
public:

	Qshelf();
	~Qshelf();
	void Update();
	void Render(RenderContext& rc);

	int matti;
	//1‚Å‚ ‚è
	//0‚Å‰ñû’†
	//2‚Å‰ñûÏ

	Game* game;
	Item* item;

	SpriteRender spriteRender;
	SoundSource* bgm;

};