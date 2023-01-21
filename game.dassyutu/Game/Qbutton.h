#pragma once
#include "sound/SoundSource.h"

class Game;

class Qbutton :public IGameObject
{
public:

	Qbutton();
	~Qbutton();
	void Update();
	void Render(RenderContext& rc);

	int pushsave;

	Game* game;

	SpriteRender spriteRender;
	int push = 0;
	//SoundSource* bgm;

private:
	int clearFlag = 1;
	bool buttonchange = true;
};