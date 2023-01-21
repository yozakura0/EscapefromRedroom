#pragma once
#include "sound/SoundSource.h"
class Game;
class Qkeybox;

class Qkeyboxdial2 :public IGameObject
{
public:

	Qkeyboxdial2();
	~Qkeyboxdial2();
	void Update();
	void Render(RenderContext& rc);

	int k2select = 0;
	int k2word;

	Game* game;
	Qkeybox* qkeybox;

	Vector3 positiond2;
	SpriteRender spriteRender;
	//SoundSource* bgm;
};

