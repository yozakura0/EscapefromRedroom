#pragma once

class Game;

class room1 :public IGameObject
{
public:
	room1();
	~room1();
	void Update();
	void Render(RenderContext& rc);

	Game* game;

	SpriteRender spriteRender;

};

