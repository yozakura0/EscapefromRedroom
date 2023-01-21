#pragma once

class Game;

class hint :public IGameObject
{
public:
	hint();
	~hint();
	void Update();
	void Render(RenderContext& rc);

	Game* game;

	SpriteRender spriteRender;
};

