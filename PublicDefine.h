#pragma once
#include "cocos2d.h"
using namespace cocos2d;

#define MONSTERMAX 10
#define BATCH 2
#define MAPCOL 18
#define MAPROW 12
#define BLOCKSIZE 80
#define BATCH_INTERNAL 5.0f
enum MonsterType
{
	normal = 1,
	fast,
	slow,
};

enum BulletType
{
	BOTTLE_BULLET=0,
	STAR_BULLET,
	SHIT_BULLET,
};

enum BlockType
{
	ROAD=1,
	TOWER,
	NO_TOWER,
	BARRIER,
};