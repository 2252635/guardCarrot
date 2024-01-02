#pragma once
#ifndef _CARROT_TOWER_BOTTLE_
#define _CARROT_TOWER_BOTTLE_
#include "TowerBase.h"
class TowerBottle:public TowerBase
{
public:
	void setParameter();//设置参数
	bool checkMoney();//检查金钱
	bool doUpAction();//升级函数
	void rotate();//进行旋转的函数
	void fireAction(Vec2 endPos)override;//发出攻击的动作
};
#endif