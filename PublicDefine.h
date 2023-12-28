#pragma once
#include "cocos2d.h"

using namespace cocos2d;

//有关关卡地图
enum BlockType
{
	ROAD,
	TOWER,
	NO_TOWER,
	BARRIER
};
#define MAP_ROW 18
#define MAP_COL 12
#define BLOCK_SIZE 80

//有关场景
enum Scenes
{
	MAP_BLUE_VIEW,
	MAP_PURPLE_VIEW,
	END_WIN,
	END_LOSE,
	MAP_BLUE,
	MAP_PURPLE,
	START
};