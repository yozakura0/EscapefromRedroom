#pragma once

#include "sound/SoundSource.h"

class Game;
class Item;

class room4 :public IGameObject
{
public:
	room4();
	~room4();
	void Update();
	void Render(RenderContext& rc);

	Game* game;
	Item* item;

	bool throwing = false;
	bool change = true;

	SpriteRender spriteRender;

};

