#pragma once
#ifndef _TOWER_MANAGER_
#define _TOWER_MANAGER_

#include "PublicDefine.h"

class TowerManager:public Ref//管理防御塔的引用计数
{
public:
	CREATE_INSTANCE_FUNC(TowerManager);//创建TM实例的函数
	DESTROY_INSTANCE_FUNC();//释放TM实例的函数
	virtual TowerVec& GetTowerVec();//获取当前防御塔Vector的指针
	virtual void SetFuncAddTowerLayer(const std::function<void(Entity*)>& AddTower);//初始化添加塔的函数
	virtual void ClearManager();//清除塔的管理员
	virtual void SetFuncCheckMoney(const std::function<int()>& CheckMoney);
	virtual int GetMoney();//获取当前金币数量
protected:
	friend class Tower;
	virtual void AddNewTower(Tower* NewTower);
	virtual void RecordTowerDead();
	virtual bool Initiate();//初始化
	virtual void RemoveTower(Ref*Sender);
private:
	TowerVec* Towers = nullptr;
	std::function<void(Entity*)> AddTower;
	std::function<int()> CheckMoney;
	TowerManager* Instance;

	TowerManager();//构造函数
	virtual~TowerManager();//析构函数
};
#endif _TOWER_MANAGER_
