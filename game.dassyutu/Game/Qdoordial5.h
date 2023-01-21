#pragma once
#include "sound/SoundSource.h"
class Game;
class Qdoor;

class Qdoordial5 :public IGameObject
{
public:

	Qdoordial5();
	~Qdoordial5();
	void Update();
	void Render(RenderContext& rc);

	int d5select = 0;
	int d5word;

	Game* game;
	Qdoor* qdoor;

	Vector3 positiond5;

	SpriteRender spriteRender;
	//SoundSource* bgm;
};