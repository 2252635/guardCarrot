#pragma once
#ifndef _PUBLIC_DEFINE_
#define _PUBLIC_DEFINE_
//头文件
#include "cocos2d.h"

using namespace cocos2d;

//防御塔宏定义
#define TOWER_MAX_GRADE 3//防御塔最多可以升三级

//瓶子塔
#define BOTTLE_DEFAULT_UP_COST//防御塔的默认升级花费
#define BOTTLE_DEFAULT_ATTACK 5//默认攻击力
#define BOTTLE_DEFAULT_ATTACK_RANGE//默认攻击范围
#define BOTTLE_PRICE//防御塔价格

#define BOTTLE_DEFAULT_DATTACK//默认攻击力
#define BOTTLE_DEFAULT_DATTACK_RANGE//默认攻击范围

#define BOTTLE_EVERY_ATTACK_RANGE 20//瓶子塔每升一级攻击范围的增量
#define BOTTLE_EVERY_ATTACK 10//瓶子塔的攻击力上升值
#define BOTTLE_EVERY_UP_COST//瓶子塔的升级花费上升值

//星星塔
#define STAR_DEFAULT_UP_COST//防御塔的默认升级花费
#define STAR_DEFAULT_ATTACK 10//默认攻击力
#define STAR_DEFAULT_ATTACK_RANGE//默认攻击范围
#define STAR_PRICE

#define STAR_DEFAULT_DATTACK1 //默认攻击力
#define STAR_DEFAULT_DATTACK_RANGE//默认攻击范围

#define STAR_EVERY_ATTACK_RANGE 20//瓶子塔每升一级攻击范围的增量
#define STAR_EVERY_ATTACK 10//瓶子塔的攻击力上升值
#define STAR_EVERY_UP_COST//瓶子塔的升级花费上升值

//屎塔
#define SHIT_DEFAULT_UP_COST//防御塔的默认升级花费
#define SHIT_DEFAULT_ATTACK 5//默认攻击力
#define SHIT_DEFAULT_ATTACK_RANGE//默认攻击范围
#define SHIT_PRICE

#define SHIT_DEFAULT_DATTACK//默认攻击力
#define SHIT_DEFAULT_DATTACK_RANGE//默认攻击范围

#define SHIT_EVERY_ATTACK_RANGE 20//瓶子塔每升一级攻击范围的增量
#define SHIT_EVERY_ATTACK 10//瓶子塔的攻击力上升值
#define SHIT_EVERY_UP_COST//瓶子塔的升级花费上升值



enum TowerType
{
	BOTTLE,
	STAR,
	SHIT
};//三种类型的塔
enum BulletType
{
	BOTTLE_BULLET,
	STAR_BULLET,
	SHIT_BULLET
};//三种类型的子弹
#endif