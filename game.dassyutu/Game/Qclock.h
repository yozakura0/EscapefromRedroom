#pragma once
#include "sound/SoundSource.h"

class Game;

class Qclock :public IGameObject
{
public:

	Qclock();
	~Qclock();
	void Update();
	void Render(RenderContext& rc);

	int large = 0;
	int smoll = 0;
	
	int largesave, smollsave;

	bool playboice = false;

	Game* game;

	SpriteRender spriteRender;
	FontRender fontRender;//フォントレンダー
	//SoundSource* bgm;

};