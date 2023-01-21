#pragma once

class Game;

class aftersousa :public IGameObject
{
public:
	aftersousa();
	~aftersousa();
	void Update();
	void Render(RenderContext& rc);

	Game* game;

	SpriteRender spriteRender;
};