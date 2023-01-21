#pragma once
#include "sound/SoundSource.h"
class Game;
class Qkeybox;

class Qkeyboxdial3 :public IGameObject
{
public:

	Qkeyboxdial3();
	~Qkeyboxdial3();
	void Update();
	void Render(RenderContext& rc);

	int k3select = 0;
	int k3word;

	Game* game;
	Qkeybox* qkeybox;

	Vector3 positiond3;

	SpriteRender spriteRender;
	//SoundSource* bgm;
};

