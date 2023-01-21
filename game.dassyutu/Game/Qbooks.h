#pragma once
#include "sound/SoundSource.h"

class Game;
class Qtableclock;

class Qbooks :public IGameObject
{
public:
	Qbooks();
	~Qbooks();
	void Update();
	void Render(RenderContext& rc);

	int bookselect = 0;
	int booksave;
	bool clearFlag = true;
	bool bookchange = true;

	Game* game;
	Qtableclock* qtableclock;

	SpriteRender spriteRender;
	SoundSource* bgm;

};