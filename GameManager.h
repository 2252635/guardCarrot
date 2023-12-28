#pragma once
#pragma once
#ifndef _CARROT_GAME_MANAGER_
#define _CARROT_GAME_MANAGER_
#include "TowerManager.h"
#include "SceneBlock.h"
#include "BarrierManager.h"
#include "MonsterManager.h"
#include "Carrot.h"
class GameManager
{
private:
	TowerMenu* towerMenu;
	BarrierManager* barrierManager;
	MonsterManager* monsterManager;
	BarrierBase* nowBTarget = nullptr;
	MonsterBase* nowMTarget = nullptr;
	Carrot* carrot;
	DynamicProperty property;//管理金钱的变量
	TowerManager* towerManager;//管理塔

public:
	void judge(const Vector<SceneBlock*>& blocks, const Vec2 pos);
	void produceMonster(const Vector<SceneBlock*>& road);
	bool checkTarget();
	BarrierManager* getBarrierVec() { return barrierManager; };
	MonsterManager* getMonsterVec() { return monsterManager; };
	bool gameEnd();
	void gameStart(const Vector<SceneBlock*>& road);
};

#endif