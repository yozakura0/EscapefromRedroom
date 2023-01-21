#pragma once

class Clear :public IGameObject
{
public:
	Clear();
	void Update();
	void Render(RenderContext& rc);

	bool finish = false;

	SpriteRender spriteRender;
	Vector3 position;
};