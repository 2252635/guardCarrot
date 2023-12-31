#pragma once

#ifndef _CARROT_MONSTER_MANAGER_
#define _CARROT_MONSTER_MANAGER_
#include "MonsterBase.h"


class MonsterManager:public Node
{
protected:
	~MonsterManager();
private:
	int count = MONSTERMAX;//怪物数量
	static Vector<MonsterBase*>* MonsterVec;
public:
	static Vector<MonsterBase*>& getVec() { return *MonsterVec; };
	bool checkTarget();
	void monsterVecMove(MonsterBase* pmonster, MonsterType type);
	int batch = BATCH;//怪物批次
	bool deadAction();
	bool init()override;
};

#endif