#pragma once
#include "sound/SoundSource.h"
class Game;
class Qsafe;

class Qsafejedial3 :public IGameObject
{
public:

	Qsafejedial3();
	~Qsafejedial3();
	void Update();
	void Render(RenderContext& rc);

	int j3select = 0;
	int j3word;

	Game* game;
	Qsafe* qsafe;

	Vector3 positionjyellow;

	SpriteRender spriteRender;
	//SoundSource* bgm;
};