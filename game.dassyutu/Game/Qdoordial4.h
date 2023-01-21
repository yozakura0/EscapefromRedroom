#pragma once
#include "sound/SoundSource.h"
class Game;
class Qdoor;

class Qdoordial4 :public IGameObject
{
public:

	Qdoordial4();
	~Qdoordial4();
	void Update();
	void Render(RenderContext& rc);

	int d4select = 0;
	int d4word;

	Game* game;
	Qdoor* qdoor;

	Vector3 positiond4;

	SpriteRender spriteRender;
	//SoundSource* bgm;
};