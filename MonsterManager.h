#pragma once
#include "PublicDefine.h"
#include "MonsterBase.h"


class MonsterManager:public Node
{
protected:
	~MonsterManager();
	bool init();
private:
	int count = MONSTERMAX;//怪物数量
	Vector<MonsterBase*> *MonsterVec=nullptr;
public:
	Vector<MonsterBase*>& getVec() { return *MonsterVec; };
	bool checkTarget();
	void monsterVecMove(MonsterBase* pmonster);
	int batch = BATCH;//怪物批次
	bool deadAction();
};