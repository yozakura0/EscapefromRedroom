#pragma once

class Game;
class room1;

class Qwindow :public IGameObject
{
public:
	Qwindow();
	void Update();
	void Render(RenderContext& rc);

	Game* game;

	room1* r1;
	SpriteRender spriteRender;
};

