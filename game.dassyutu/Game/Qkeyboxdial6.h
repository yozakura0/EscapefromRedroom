#pragma once
#include "sound/SoundSource.h"
class Game;
class Qkeybox;

class Qkeyboxdial6 :public IGameObject
{
public:

	Qkeyboxdial6();
	~Qkeyboxdial6();
	void Update();
	void Render(RenderContext& rc);

	int k6select = 0;
	int k6word;

	Game* game;
	Qkeybox* qkeybox;

	Vector3 positiond6;

	SpriteRender spriteRender;
	//SoundSource* bgm;
};

