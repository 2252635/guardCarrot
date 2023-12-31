#pragma once

#ifndef _CARROT_MONSTER_MANAGER_
#define _CARROT_MONSTER_MANAGER_
#include "MonsterBase.h"


class MonsterManager:public Node
{
protected:
	~MonsterManager();
private:
	int count = MONSTERMAX;//��������
	static Vector<MonsterBase*>* MonsterVec;
public:
	static Vector<MonsterBase*>& getVec() { return *MonsterVec; };
	bool checkTarget();
	void monsterVecMove(MonsterBase* pmonster, MonsterType type);
	int batch = BATCH;//��������
	bool deadAction();
	bool init()override;
};

#endif