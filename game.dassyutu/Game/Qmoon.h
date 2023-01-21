#pragma once
#include "sound/SoundSource.h"

class Game;
class Item;

class Qmoon :public IGameObject
{
public:

	Qmoon();
	~Qmoon();
	void Update();
	void Render(RenderContext& rc);

	bool mselect = false;

	Game* game;
	Item* item;

	SpriteRender spriteRender;
	//SoundSource* bgm;

};