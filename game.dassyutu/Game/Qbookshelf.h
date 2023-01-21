#pragma once

class Game;

class Qbookshelf :public IGameObject
{
public:

	Qbookshelf();
	~Qbookshelf();
	void Update();
	void Render(RenderContext& rc);

	Game* game;

	SpriteRender spriteRender;

};