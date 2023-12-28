#pragma once
#include "PublicDefine.h"
#include "MonsterBase.h"


class MonsterManager:public Node
{
protected:
	~MonsterManager();
	bool init();
private:
	int count = MONSTERMAX;//��������
	Vector<MonsterBase*> *MonsterVec=nullptr;
public:
	Vector<MonsterBase*>& getVec() { return *MonsterVec; };
	bool checkTarget();
	void monsterVecMove(MonsterBase* pmonster);
	int batch = BATCH;//��������
	bool deadAction();
};