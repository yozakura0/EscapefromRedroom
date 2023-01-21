#pragma once
#include "sound/SoundSource.h"
class Game;
class Qkeybox;

class Qkeyboxdial4 :public IGameObject
{
public:

	Qkeyboxdial4();
	~Qkeyboxdial4();
	void Update();
	void Render(RenderContext& rc);

	int k4select = 0;
	int k4word;

	Game* game;
	Qkeybox* qkeybox;

	Vector3 positiond4;

	SpriteRender spriteRender;
	//SoundSource* bgm;
};

