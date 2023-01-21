#include "stdafx.h"
#include "sousa2.h"
#include "Game.h"
#include "sousa3.h"

sousa2::sousa2()
{
	spriteRender.Init("Assets/sprite/sousa2.DDS", 1920.0f, 1080.0f);
}

sousa2::~sousa2()
{

}

void sousa2::Update()
{
	//ŽŸ‚Ö
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		NewGO<sousa3>(0, "sousa3");
		DeleteGO(this);
	}
}

void sousa2::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}