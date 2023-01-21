#pragma once
#include "sound/SoundSource.h"

class Game;
class Qsafe;

class Qsafetadial2 :public IGameObject
{
public:

	Qsafetadial2();
	~Qsafetadial2();
	void Update();
	void Render(RenderContext& rc);

	int t2select = 0;
	int t2word;

	Game* game;
	Qsafe* qsafe;

	Vector3 positiontred;

	SpriteRender spriteRender;
	//SoundSource* bgm;
};