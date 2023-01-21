#pragma once

class Game;

class room2 :public IGameObject
{
public:
	room2();
	~room2();
	void Update();
	void Render(RenderContext& rc);

	SpriteRender spriteRender;

	Game* game;

};