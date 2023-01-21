#pragma once
class Game;

class sousa3 :public IGameObject
{
public:
	sousa3();
	~sousa3();
	void Update();
	void Render(RenderContext& rc);

	Game* game;

	SpriteRender spriteRender;
};