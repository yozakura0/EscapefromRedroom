#pragma once
#include "sound/SoundSource.h"
class Game;
class Qdoor;

class Qdoordial3 :public IGameObject
{
public:

	Qdoordial3();
	~Qdoordial3();
	void Update();
	void Render(RenderContext& rc);

	int d3select = 0;
	int d3word;

	Game* game;
	Qdoor* qdoor;

	Vector3 positiond3;

	SpriteRender spriteRender;
	//SoundSource* bgm;
};