#pragma once
#include "sound/SoundSource.h"

class Game;
class room4;
class Item;

class Qsafe :public IGameObject
{
public:

	Qsafe();
	~Qsafe();
	void Update();
	void Render(RenderContext& rc);

	bool safechange = true;

	bool modedial = false;
		
	bool sclearflag[6];
	int paper;
	//0�ł���
	//1�ŉ����
	//2�ŉ����


	Game* game;
	room4* r4;
	Item* item;

	SpriteRender spriteRender;
	//SoundSource* bgm;

};