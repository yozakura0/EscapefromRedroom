#pragma once
#include "sound/SoundSource.h"
class Game;
class Qsafe;

class Qsafejedial1 :public IGameObject
{
public:

	Qsafejedial1();
	~Qsafejedial1();
	void Update();
	void Render(RenderContext& rc);

	int j1select = 0;
	int j1word;

	Game* game;
	Qsafe* qsafe;

	Vector3 positionjblue;

	SpriteRender spriteRender;
	//SoundSource* bgm;
};