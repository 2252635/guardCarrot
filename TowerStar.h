#pragma once
#ifndef _CARROT_TOWER_STAR_
#define _CARROT_TOWER_STAR_
#include "PublicDefine.h"
#include"TowerBase.h"
#include"StarBullet.h"

class TowerStar :public TowerBase
{
public:
	void setParameter();//设置参数
	bool doUpAction();//升级函数
	void fire();//进行攻击的函数
	void fireAction();//发出攻击的动作
};
#endif