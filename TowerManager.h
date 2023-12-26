#pragma once
#ifndef _CARROT_TOWER_MANAGER_
#define _CARROT_TOWER_MANAGER_
#include"PublicDefine.h"
#include"TowerBase.h"

class TowerManager:public Node
{
private:
	Vector<TowerBase*>* towers;

public:
	Vector<TowerBase*>* getVec();//获取vector的函数
	void addTower(TowerType type, Vec2 pos);//添加防御塔的函数
	void destroyTower(TowerBase* targetTower);//摧毁一个防御塔
	~TowerManager();//析构函数
};
#endif