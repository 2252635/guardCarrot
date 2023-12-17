#pragma once
#ifndef _TOWER_MANAGER_
#define _TOWER_MANAGER_

#include "PublicDefine.h"

class TowerManager:public Ref//��������������ü���
{
public:
	CREATE_INSTANCE_FUNC(TowerManager);//����TMʵ���ĺ���
	DESTROY_INSTANCE_FUNC();//�ͷ�TMʵ���ĺ���
	virtual TowerVec& GetTowerVec();//��ȡ��ǰ������Vector��ָ��
	virtual void SetFuncAddTowerLayer(const std::function<void(Entity*)>& AddTower);//��ʼ��������ĺ���
	virtual void ClearManager();//������Ĺ���Ա
	virtual void SetFuncCheckMoney(const std::function<int()>& CheckMoney);
	virtual int GetMoney();//��ȡ��ǰ�������
protected:
	friend class Tower;
	virtual void AddNewTower(Tower* NewTower);
	virtual void RecordTowerDead();
	virtual bool Initiate();//��ʼ��
	virtual void RemoveTower(Ref*Sender);
private:
	TowerVec* Towers = nullptr;
	std::function<void(Entity*)> AddTower;
	std::function<int()> CheckMoney;
	TowerManager* Instance;

	TowerManager();//���캯��
	virtual~TowerManager();//��������
};
#endif _TOWER_MANAGER_
