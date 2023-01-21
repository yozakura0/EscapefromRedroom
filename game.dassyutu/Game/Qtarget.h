#pragma once

class Game;
class room4;

class Qtarget :public IGameObject
{
public:

	Qtarget();
	~Qtarget();
	void Update();
	void Render(RenderContext& rc);

	Game* game;
	room4* r4;

	SpriteRender spriteRender;

};