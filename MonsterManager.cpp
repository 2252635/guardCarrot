#include "MonsterManager.h"
#include "base/CCScheduler.h"
using namespace cocos2d;
Vector<MonsterBase*>* MonsterManager::MonsterVec;
MonsterManager::~MonsterManager()
{
	CC_SAFE_DELETE(MonsterVec);
}

bool MonsterManager::init()
{
	MonsterVec = new Vector<MonsterBase*>;
	if (MonsterVec)
		return true;
	else
		return false;
}

void MonsterManager::monsterVecMove(MonsterBase* pmonster,MonsterType type)
{
	
}

bool MonsterManager::checkTarget()
{
	for (auto currentMonster : *MonsterVec)
		if (currentMonster->IsTarget)
			return true;
	return false;
}

bool MonsterManager::deadAction()
{
	int icount = 0;
	for (auto currentMonster : *MonsterVec) {
		if (currentMonster->getVictim()==nullptr) {
			icount++;
		}
	}
	if (icount == MONSTERMAX)
		return false;
	else
		return true;
}