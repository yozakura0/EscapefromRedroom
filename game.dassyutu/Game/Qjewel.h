#pragma once

class Game;

class Qjewel :public IGameObject
{
public:

	Qjewel();
	~Qjewel();
	void Update();
	void Render(RenderContext& rc);

	Game* game;

	SpriteRender spriteRender;

};