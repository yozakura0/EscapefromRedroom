#pragma once
#include "sound/SoundSource.h"

class Game;
class Item;

class Qice :public IGameObject
{
public:

	Qice();
	~Qice();
	void Update();
	void Render(RenderContext& rc);

	Game* game;
	Item* item;

	bool iceselect = false;

	SpriteRender spriteRender;
	//SoundSource* bgm;
};