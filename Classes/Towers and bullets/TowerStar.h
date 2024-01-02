#pragma once
#ifndef _CARROT_TOWER_STAR_
#define _CARROT_TOWER_STAR_
#include"TowerBase.h"
#include"StarBullet.h"

class TowerStar :public TowerBase
{
public:
	void setParameter();//设置参数
	bool doUpAction();//升级函数
	void fireAction(Vec2 endPos)override;//发出攻击的动作
};
#endif