#include "stdafx.h"
#include "sousa.h"
#include "Game.h"
#include "sousa2.h"

sousa::sousa()
{
	spriteRender.Init("Assets/sprite/sousa.DDS", 1920.0f, 1080.0f);
}

sousa::~sousa()
{

}

void sousa::Update()
{
	//ŽŸ‚Ö
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		NewGO<sousa2>(0, "sousa2");
		DeleteGO(this);
	}
}

void sousa::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}