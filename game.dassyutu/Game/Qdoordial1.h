#pragma once
#include "sound/SoundSource.h"
class Game;
class Qdoor;

class Qdoordial1:public IGameObject
{
public:

	Qdoordial1();
	~Qdoordial1();
	void Update();
	void Render(RenderContext& rc);

	int d1select = 0;
	int d1word;

	Game* game;
	Qdoor* qdoor;

	Vector3 positiond1;

	SpriteRender spriteRender;
	//SoundSource* bgm;
};

