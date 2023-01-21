#pragma once
#include "sound/SoundSource.h"

class Game;
class Qsafe;

class Qsafetadial1 :public IGameObject
{
public:

	Qsafetadial1();
	~Qsafetadial1();
	void Update();
	void Render(RenderContext& rc);

	int t1select = 0;
	int t1word;

	Game* game;
	Qsafe* qsafe;

	Vector3 positiontblue;

	SpriteRender spriteRender;
	//SoundSource* bgm;
};