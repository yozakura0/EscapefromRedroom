#pragma once
#include "sound/SoundSource.h"

class Game;

class Qdoor :public IGameObject
{
public:

	Qdoor();
	~Qdoor();
	void Update();
	void Render(RenderContext& rc);

	Game* game;

	bool modedial = false;

	bool dclearflag[7];

	SpriteRender spriteRender;
	//SoundSource* bgm;

};