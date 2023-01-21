#pragma once

#include "Level3DRender/LevelRender.h"
class Clear;

class Game : public IGameObject
{
public:
	Game() {}
	~Game() {}
	bool Start();
	void Update();
	Vector3 position;

	int siten;
	int sceneA = 0;
	/*�V�[��A���蓖��
	0,����1
	1.��
	2.�{�^��(����,r,y,w,ry,rw,yw,�S)
	3.�X�A�{�[�h
	*/
	int sceneB = 0;
	/*�V�[��B���蓖��
	0,����2
	1,�{�I(��)
	2,�{(�S,����,�X��,�X��,��,�X,��,��)�A�������v
	4,�������v(�Y�[��)
	6,���v(�Z�j0�`7���ꂼ��ɂ����j0�`7,�v64/��2���z��Ŏd�����H)
	7,�G��(��)
	*/
	int sceneC = 0;
	/*�V�[��C���蓖��
	0,����3
	1,����
	2,�_�C�A��(����)
	3,�_�C�A��(��)
	4,��
	5,�I(�}�b�`)
	6,�I
	*/
	int sceneD = 0;
	/*�V�[��D���蓖��
	0,����4
	1,�W���G��(���F)
	2,�W���G��(��)
	3,����
	4,����(�_�C����:���)
	5,����(�_�C����:�i�C�t)
	6,�I
	7,�I+�i�C�t
	*/
	bool openknife = false;

	int levela = 0;
	int levelb = 0;
	int levelc = 0;
	int leveld = 0;

	Clear* clear;

	bool restart = false;

	bool reshow = false;
	bool reshowing = false;

	bool givehint = false;
};

