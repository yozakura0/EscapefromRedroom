#include "stdafx.h"
#include "Item.h"
#include "Clear.h"

Item::Item()
{
	spriteRender.Init("Assets/sprite/NULL.DDS", 200.0f, 200.0f);
	position.x = 850;
	position.y = 430;
}

void Item::Update()
{
	//itemselectの値に応じてアイテム表示
	if (itemselect == 1)
	{
		spriteRender.Init("Assets/sprite/matti.DDS", 200.0f, 200.0f);
		position.x = 850;
		position.y = 430;
	}
	else if (itemselect == 2)
	{
		spriteRender.Init("Assets/sprite/wakeupknife.DDS", 200.0f, 200.0f);
		position.x = 850;
		position.y = 430;
	}
	else if (itemselect == 3)
	{
		spriteRender.Init("Assets/sprite/serohan.DDS", 200.0f, 200.0f);
		position.x = 850;
		position.y = 430;
	}
	else
	{
		spriteRender.Init("Assets/sprite/NULL.DDS", 200.0f, 200.0f);
		position.x = 850;
		position.y = 430;
	}
		
	//アイテム選択のハブ
	if (g_pad[0]->IsTrigger(enButtonUp))
	{
		switch (itemselect)
		{
		case 0:
			if (paper == 1)
			{
				itemselect = 3;
			}
			else if (knife == 1)
			{
				itemselect = 2;
			}
			else if (matti == 1)
			{
				itemselect = 1;
			}
			break;
		case 1:
			itemselect = 0;
			break;
		case 2:
			if (matti == 1)
			{
				itemselect = 1;
			}
			else
			{
				itemselect = 0;
			}
			break;
		case 3:
			if (knife == 1)
			{
				itemselect = 2;
			}
			else if (matti == 1)
			{
				itemselect = 1;
			}
			else
			{
				itemselect = 0;
			}
		default:
			break;
		}
	}

	if (g_pad[0]->IsTrigger(enButtonDown))
	{
		switch (itemselect)
		{
		case 0:
			if (matti == 1)
			{
				itemselect = 1;
			}
			else if (knife == 1)
			{
				itemselect = 2;
			}
			else if (paper == 1)
			{
				itemselect = 3;
			}
			break;
		case 1:
			if (knife == 1)
			{
				itemselect = 2;
			}
			else if (paper == 1)
			{
				itemselect = 3;
			}
			else
			{
				itemselect = 0;
			}
			break;
		case 2:
			if (paper == 1)
			{
				itemselect = 3;
			}
			else
			{
				itemselect = 0;
			}
			break;
		case 3:
			itemselect = 0;
			break;
		default:
			break;
		}
	}

	//clearに応じて消える
	if (clear == NULL)
	{
		clear = FindGO<Clear>("clear");
	}
	else
	{
		DeleteGO(this);
	}

	spriteRender.SetPosition(position);
	spriteRender.Update();
}

void Item::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}