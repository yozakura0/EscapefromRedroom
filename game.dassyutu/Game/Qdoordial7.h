#pragma once
#include "sound/SoundSource.h"
class Game;
class Qdoor;

class Qdoordial7 :public IGameObject
{
public:

	Qdoordial7();
	~Qdoordial7();
	void Update();
	void Render(RenderContext& rc);

	int d7select = 0;
	int d7word;

	Game* game;
	Qdoor* qdoor;

	Vector3 positiond7;

	SpriteRender spriteRender;
	//SoundSource* bgm;
};