#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "sousa.h"

Title::Title()
{
	spriteRender.Init("Assets/sprite/title.DDS",1920.0f,1080.0f);
}

Title::~Title()
{
	
}

void Title::Update()
{
	//‘€ìà–¾‚Ö
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		NewGO<sousa>(0, "sousa");
		DeleteGO(this);
	}
}

void Title::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}
