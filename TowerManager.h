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
	Vector<TowerBase*>* getVec();//��ȡvector�ĺ���
	void addTower(TowerType type, Vec2 pos);//��ӷ������ĺ���
	void destroyTower(TowerBase* targetTower);//�ݻ�һ��������
	~TowerManager();//��������
};
#endif