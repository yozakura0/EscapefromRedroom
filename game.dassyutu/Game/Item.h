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

	int matti = 0;//0�Ŗ�����
	int knife = 0;//1�ŏ���
	int paper = 0;//2�Ŏg�p�ς�

	bool reset = false;

	int itemselect = 0;
	/*
	0,���I��
	1,�}�b�`
	2,�i�C�t
	3,�Ԏ�
	*/

	Clear* clear;
};