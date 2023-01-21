#pragma once

#include "sound/SoundSource.h"

class Game;
class Item;
class room4;
class Qbutton;
class Qshelf;
class Qice;
class Qkeyboxdial1;
class Qkeyboxdial2;
class Qkeyboxdial3;
class Qkeyboxdial4;
class Qkeyboxdial5;
class Qkeyboxdial6;
class Qkeybox;
class Qbooks;
class Qsafejedial1;
class Qsafejedial2;
class Qsafejedial3;
class Qsafetadial1;
class Qsafetadial2;
class Qsafetadial3;
class Qsafe;
class Qmoon;
class Qdoordial1;
class Qdoordial2;
class Qdoordial3;
class Qdoordial4;
class Qdoordial5;
class Qdoordial6;
class Qdoordial7;
class Clear;

class cursor : public IGameObject
{
public:
	cursor();
	~cursor();
	void Update();
	void Render(RenderContext& rc);
	Vector3 position;
	
	Game* game;
	Item* item;
	room4* r4;
	Qbutton* qbutton;
	Qshelf* qshelf;
	Qice* qice;
	Qkeyboxdial1* qkeyboxdial1;
	Qkeyboxdial2* qkeyboxdial2;
	Qkeyboxdial3* qkeyboxdial3;
	Qkeyboxdial4* qkeyboxdial4;
	Qkeyboxdial5* qkeyboxdial5;
	Qkeyboxdial6* qkeyboxdial6;
	Qkeybox* qkeybox;
	Qbooks* qbooks;
	Qsafejedial1* qsjedial1;
	Qsafejedial2* qsjedial2;
	Qsafejedial3* qsjedial3;
	Qsafetadial1* qstadial1;
	Qsafetadial2* qstadial2;
	Qsafetadial3* qstadial3;
	Qsafe* qsafe;
	Qmoon* qmoon;
	Qdoordial1* qdoordial1;
	Qdoordial2* qdoordial2;
	Qdoordial3* qdoordial3;
	Qdoordial4* qdoordial4;
	Qdoordial5* qdoordial5;
	Qdoordial6* qdoordial6;
	Qdoordial7* qdoordial7;
	Clear* clear;

//private:
	SpriteRender spriteRender;
	FontRender fontRender;//フォントレンダー
};

