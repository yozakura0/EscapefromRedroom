#include "stdafx.h"
#include "clear.h"
#include "Title.h"

Clear::Clear()
{
	//spriteRender.Init("Assets/sprite/room3-door.open1.DDS", 1920.0f, 1080.0f);
	finish = true;
}

void Clear::Update()
{
	//for (int i = 0; i < 30; i++) {}

	//spriteRender.Init("Assets/sprite/room3-door.open2.DDS", 1920.0f, 1080.0f);

	//for (int i = 0; i < 30; i++) {}

	spriteRender.Init("Assets/sprite/clear.DDS", 1920.0f, 1080.0f);

	//ƒ^ƒCƒgƒ‹‚Ö
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		NewGO<Title>(0, "title");
		DeleteGO(this);
	}
}

void Clear::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}