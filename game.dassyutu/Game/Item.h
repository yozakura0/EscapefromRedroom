#pragma once

class Clear;

class Item :public IGameObject
{
public:
	Item();
	void Update();
	void Render(RenderContext& rc);

	SpriteRender spriteRender;
	Vector3 position;

	int matti = 0;//0で未所持
	int knife = 0;//1で所持
	int paper = 0;//2で使用済み

	bool reset = false;

	int itemselect = 0;
	/*
	0,未選択
	1,マッチ
	2,ナイフ
	3,赤紙
	*/

	Clear* clear;
};