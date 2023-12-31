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
	Vector<TowerBase*>& getVec();//��ȡvector�ĺ���
	static Sprite* addTower(TowerType type,Vec2 pos, Sprite* &towerBase);//��ӷ������ĺ���
	bool setTarget(VictimEntityBase* newTarget);//��һ��������Ϊ����Ŀ��
	void destroyTower(TowerBase* targetTower);//�ݻ�һ��������
	~TowerManager();//��������
};
#endif