#pragma once
#include "sound/SoundSource.h"

class Game;
class Item;

class Qshelf :public IGameObject
{
public:

	Qshelf();
	~Qshelf();
	void Update();
	void Render(RenderContext& rc);

	int matti;
	//1�ł���
	//0�ŉ����
	//2�ŉ����

	Game* game;
	Item* item;

	SpriteRender spriteRender;
	SoundSource* bgm;

};