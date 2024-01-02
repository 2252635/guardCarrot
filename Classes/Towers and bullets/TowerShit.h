#pragma once
#ifndef _CARROT_TOWER_SHIT_
#define _CARROT_TOWER_SHIT_
#include"TowerBase.h"

class TowerShit :public TowerBase
{
public:
	void setParameter();//设置参数
	bool doUpAction();//升级函数
	void fireAction(Vec2 endPos)override;//发出攻击的动作
};
#endif