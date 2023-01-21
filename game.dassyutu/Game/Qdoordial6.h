#pragma once
#include "sound/SoundSource.h"
class Game;
class Qdoor;

class Qdoordial6 :public IGameObject
{
public:

	Qdoordial6();
	~Qdoordial6();
	void Update();
	void Render(RenderContext& rc);

	int d6select = 0;
	int d6word;

	Game* game;
	Qdoor* qdoor;

	Vector3 positiond6;

	SpriteRender spriteRender;
	//SoundSource* bgm;
};