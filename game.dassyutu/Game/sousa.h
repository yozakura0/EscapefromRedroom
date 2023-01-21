#pragma once

class Game;

class sousa :public IGameObject
{
public:
	sousa();
	~sousa();
	void Update();
	void Render(RenderContext& rc);

	Game* game;

	SpriteRender spriteRender;
};