#include "stdafx.h"
#include "aftersousa.h"
#include "Game.h"

aftersousa::aftersousa()
{
	spriteRender.Init("Assets/sprite/aftersousa.DDS", 1920.0f, 1080.0f);

}

aftersousa::~aftersousa()
{

}

void aftersousa::Update()
{
	game = FindGO<Game>("game");

	//‘€ì•û–@‚ÌÁ‹Ž
	if (game->reshowing == false)
	{
		DeleteGO(this);
	}
}

void aftersousa::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}