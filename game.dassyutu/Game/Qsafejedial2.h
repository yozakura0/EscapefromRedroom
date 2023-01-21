#pragma once
#include "sound/SoundSource.h"
class Game;
class Qsafe;

class Qsafejedial2 :public IGameObject
{
public:

	Qsafejedial2();
	~Qsafejedial2();
	void Update();
	void Render(RenderContext& rc);

	int j2select = 0;
	int j2word;

	Game* game;
	Qsafe* qsafe;

	Vector3 positionjred;

	SpriteRender spriteRender;
	//SoundSource* bgm;
};