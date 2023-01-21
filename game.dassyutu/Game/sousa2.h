#pragma once

class Game;

class sousa2 :public IGameObject
{
public:
	sousa2();
	~sousa2();
	void Update();
	void Render(RenderContext& rc);

	Game* game;

	SpriteRender spriteRender;
};