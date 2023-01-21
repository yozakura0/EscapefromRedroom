#pragma once
#include "sound/SoundSource.h"
class Game;
class Qdoor;

class Qdoordial2 :public IGameObject
{
public:

	Qdoordial2();
	~Qdoordial2();
	void Update();
	void Render(RenderContext& rc);

	int d2select = 0;
	int d2word;

	Game* game;
	Qdoor* qdoor;

	Vector3 positiond2;

	SpriteRender spriteRender;
	//SoundSource* bgm;
};