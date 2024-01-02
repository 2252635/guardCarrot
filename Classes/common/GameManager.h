#pragma once
#ifndef _CARROT_GAME_MANAGER_
#define _CARROT_GAME_MANAGER_
#include "SceneBlock.h"
#include "BarrierManager.h"
#include "MonsterManager.h"
#include "Carrot.h"
#include"DynamicProperty.h"
#include"TowerMenu.h"
class GameManager:public Node
{
private:
	BarrierManager* barrierManager;
	MonsterManager* monsterManager;
	BarrierBase* nowBTarget=nullptr;
	MonsterBase* nowMTarget=nullptr;
	DynamicProperty property;//管理金钱的变量
	TowerManager* towerManager;//管理塔
	/*TowerMenu* towerMenu;*/
	Carrot* carrot;
	int count = MONSTERMAX;

public:
	bool init()override;
	BlockType judge(Vector<SceneBlock*>& blocks, const Vec2 pos,Vec2&targetPos);
	bool checkTarget();
	BarrierManager* getBarrierVec() { return barrierManager; };
	MonsterManager* getMonsterVec() { return monsterManager; };
	TowerManager* getTowerManager() { return towerManager; };
	bool gameEnd();
	void gameStart(const Vector<SceneBlock*>& road);
	Carrot* getCarrot() { return carrot; };
	/*Menu* getMenu() { return towerMenu->getMenu(); };*/
	int getMoney() { return property.getMoney(); };
	DynamicProperty& getProperty() { return property; };
	/*TowerMenu* getTowerMenu() { return towerMenu; };*/
};
#endif