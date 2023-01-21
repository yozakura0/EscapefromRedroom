#pragma once

class Game;
class Qbooks;

class Qtableclock :public IGameObject
{
public:
	Qtableclock();
	void Update();
	void Render(RenderContext& rc);

	SpriteRender spriteRender;
	
	Game* game;
	Qbooks* qbooks;
};

