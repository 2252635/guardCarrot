#pragma once
#ifndef _CARROT_TOWER_MANAGER_
#define _CARROT_TOWER_MANAGER_
#include"PublicDefine.h"
#include"TowerBase.h"
<<<<<<< HEAD
=======
#include"TowerMenu.h"
>>>>>>> 3cc07b4 (lyy2)

class TowerManager:public Node
{
private:
<<<<<<< HEAD
	Vector<TowerBase*>* towers;

public:
	Vector<TowerBase*>* getVec();//获取vector的函数
	void addTower(TowerType type, Vec2 pos);//添加防御塔的函数
=======

	Vector<TowerBase*> *towers;
	TowerMenu towerMenu;

public:
	TowerManager() {towers = new Vector<TowerBase*>; };
	Vector<TowerBase*>& getVec();//获取vector的函数
	static void addTower(TowerType type,Vec2 pos);//添加防御塔的函数
	bool setTarget(VictimEntityBase* newTarget);//将一个怪物设为攻击目标
>>>>>>> 3cc07b4 (lyy2)
	void destroyTower(TowerBase* targetTower);//摧毁一个防御塔
	~TowerManager();//析构函数
};
#endif