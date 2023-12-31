#pragma once
#ifndef _CARROT_DYNAMIC_PROPERTY_
#define _CARROT_DYNAMIC_PROPERTY_
#include "Entity.h"
class DynamicProperty :public Entity
{
private:
	static int money;//金钱数量
	static LabelTTF *moneyLabel;
public:
	/*DynamicProperty();*/
	bool init()override;
	static void showMoney();//显示金币数量的函数
	static int getMoney() { return money; };//获取当前金钱数量
	static void monsterDead(int dm);//击杀怪物时金钱的变化量
	static void towerDead(int dm);//拆除防御塔时金钱的变化量
	static void towerBuild(int dm);//建造防御塔时金钱的变化量
	static LabelTTF* getMoneyLabel() { return moneyLabel; };

};
#endif