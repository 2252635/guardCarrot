#pragma once
#ifndef _CARROT_DYNAMIC_PROPERTY_
#define _CARROT_DYNAMIC_PROPERTY_
#include"PublicDefine.h"
class DynamicProperty 
{
private:
	int money;//金钱数量
	Label *moneyLabel;
public:
	Label*init();
	void showMoney();//显示金币数量的函数
	int getMoney() { return money; };//获取当前金钱数量
	void monsterDead(int dm);//击杀怪物时金钱的变化量
	void towerDead(int dm);//拆除防御塔时金钱的变化量
	void towerBuild(int dm);//建造防御塔时金钱的变化量

};
#endif