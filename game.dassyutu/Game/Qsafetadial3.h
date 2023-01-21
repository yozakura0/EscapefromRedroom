#pragma once
#include "sound/SoundSource.h"

class Game;
class Qsafe;

class Qsafetadial3 :public IGameObject
{
public:

	Qsafetadial3();
	~Qsafetadial3();
	void Update();
	void Render(RenderContext& rc);

	int t3select = 0;
	int t3word;

	Game* game;
	Qsafe* qsafe;

	Vector3 positiontyellow;

	SpriteRender spriteRender;
	//SoundSource* bgm;
};