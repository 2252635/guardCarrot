#pragma once
#ifndef _CARROT_TOWER_MANAGER_
#define _CARROT_TOWER_MANAGER_
//#include"TowerBase.h"
#include"TowerBottle.h"
#include"TowerStar.h"
#include"TowerShit.h"

class TowerManager:public Node
{
private:
	static Vector<TowerBase*> *towers;
public:
	TowerManager() {towers = new Vector<TowerBase*>; };
	Vector<TowerBase*>& getVec();//获取vector的函数
	static Sprite* addTower(TowerType type,Vec2 pos, Sprite* &towerBase);//添加防御塔的函数
	bool setTarget(VictimEntityBase* newTarget);//将一个怪物设为攻击目标
	void destroyTower(TowerBase* targetTower);//摧毁一个防御塔
	~TowerManager();//析构函数
};
#endif