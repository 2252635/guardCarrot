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
	Vector<TowerBase*>* getVec();//��ȡvector�ĺ���
	void addTower(TowerType type, Vec2 pos);//��ӷ������ĺ���
=======

	Vector<TowerBase*> *towers;
	TowerMenu towerMenu;

public:
	TowerManager() {towers = new Vector<TowerBase*>; };
	Vector<TowerBase*>& getVec();//��ȡvector�ĺ���
	static void addTower(TowerType type,Vec2 pos);//��ӷ������ĺ���
	bool setTarget(VictimEntityBase* newTarget);//��һ��������Ϊ����Ŀ��
>>>>>>> 3cc07b4 (lyy2)
	void destroyTower(TowerBase* targetTower);//�ݻ�һ��������
	~TowerManager();//��������
};
#endif