#pragma once
#ifndef _CARROT_PUBLIC_
#define _CARROT_PUBLIC_
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
using namespace cocos2d;

//防御塔宏定义
#define TOWER_MAX_GRADE 3//防御塔最多可以升三级

//瓶子塔
#define BOTTLE_DEFAULT_UP_COST 40//防御塔的默认升级花费
#define BOTTLE_DEFAULT_ATTACK 30//默认攻击力
#define BOTTLE_DEFAULT_ATTACK_RANGE 120//默认攻击范围
#define BOTTLE_PRICE 50//防御塔价格

#define BOTTLE_DEFAULT_DATTACK 10//默认攻击力
#define BOTTLE_DEFAULT_DATTACK_RANGE 20//默认攻击范围

#define BOTTLE_EVERY_ATTACK_RANGE 20//瓶子塔每升一级攻击范围的增量
#define BOTTLE_EVERY_ATTACK 10//瓶子塔的攻击力上升值
#define BOTTLE_EVERY_UP_COST 10//瓶子塔的升级花费上升值

//星星塔
#define STAR_DEFAULT_UP_COST 60//防御塔的默认升级花费
#define STAR_DEFAULT_ATTACK 10//默认攻击力
#define STAR_DEFAULT_ATTACK_RANGE 120//默认攻击范围
#define STAR_PRICE 120

#define STAR_DEFAULT_DATTACK 20//默认攻击力
#define STAR_DEFAULT_DATTACK_RANGE 20//默认攻击范围

#define STAR_EVERY_ATTACK_RANGE 20//瓶子塔每升一级攻击范围的增量
#define STAR_EVERY_ATTACK 20//瓶子塔的攻击力上升值
#define STAR_EVERY_UP_COST 15//瓶子塔的升级花费上升值

//屎塔
#define SHIT_DEFAULT_UP_COST 40//防御塔的默认升级花费
#define SHIT_DEFAULT_ATTACK 30//默认攻击力
#define SHIT_DEFAULT_ATTACK_RANGE 120//默认攻击范围
#define SHIT_PRICE 80

#define SHIT_DEFAULT_DATTACK 10//默认攻击力
#define SHIT_DEFAULT_DATTACK_RANGE 20//默认攻击范围

#define SHIT_EVERY_ATTACK_RANGE 20//瓶子塔每升一级攻击范围的增量
#define SHIT_EVERY_ATTACK 10//瓶子塔的攻击力上升值
#define SHIT_EVERY_UP_COST 10//瓶子塔的升级花费上升值

//金钱
#define DEFAULT_MONEY 200//开局时的默认金币数量

//地图
#define MAP_ROW 18
#define MAP_COL 12

#define BLOCK_SIZE 80

enum BulletType
{
	BOTTLE_BULLET,
	STAR_BULLET,
	SHIT_BULLET
};//三种类型的子弹
enum TowerType
{
	BOTTLE,
	STAR,
	SHIT
};//三种类型的塔
//std::map<TowerType, std::string> TowerTypeName = {
//	{BOTTLE, "BottleTower"},
//	{STAR, "StarTower"},
//	{SHIT, "ShitTower"}
//};
enum BlockType
{
	ROAD,
	TOWER,
	NO_TOWER,
	BARRIER
};

//有关场景
enum Scenes
{
	MAP_BLUE_VIEW,
	MAP_PURPLE_VIEW,
	END_WIN,
	END_LOSE,
	MAP_BLUE,
	MAP_PURPLE,
	START,
	HELP
};

//产生怪物
#define MONSTERMAX 10//单次个数
#define BATCH 2//怪物批次
#define BATCH_INTERNAL 5.0f//批次间隔

enum MonsterType
{
	NORMAL = 1,
	FAST,
	SLOW,
};

enum BarrierType
{
	BALL_ONE,
	BALL_TWO,
	CLOUD_BLUE,
	CLOUD_PURPLE,
};


#endif