#pragma once
#include "sound/SoundSource.h"

class Game;
class Qkeybox;

class Qkeyboxdial1 :public IGameObject
{
public:

	Qkeyboxdial1();
	~Qkeyboxdial1();
	void Update();
	void Render(RenderContext& rc);

	int k1select = 0;
	int k1word;

	Game* game;
	Qkeybox* qkeybox;

	Vector3 positiond1;

	SpriteRender spriteRender;
	//SoundSource* bgm;
};

