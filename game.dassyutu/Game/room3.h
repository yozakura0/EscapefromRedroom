#pragma once

class Game;

class room3 :public IGameObject
{
public:
	room3();
	~room3();
	void Update();
	void Render(RenderContext& rc);

	Game* game;

	SpriteRender spriteRender;

};
