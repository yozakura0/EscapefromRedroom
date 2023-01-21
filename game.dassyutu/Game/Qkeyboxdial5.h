#pragma once
#include "sound/SoundSource.h"
class Game;
class Qkeybox;

class Qkeyboxdial5 :public IGameObject
{
public:

	Qkeyboxdial5();
	~Qkeyboxdial5();
	void Update();
	void Render(RenderContext& rc);

	int k5select = 0;
	int k5word;

	Game* game;
	Qkeybox* qkeybox;

	Vector3 positiond5;

	SpriteRender spriteRender;
	//SoundSource* bgm;
};

