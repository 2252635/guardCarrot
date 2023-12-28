#include "MonsterManager.h"
#include "base/CCScheduler.h"
using namespace cocos2d;

MonsterManager::~MonsterManager()
{
	CC_SAFE_DELETE(MonsterVec);
}

bool MonsterManager::init()
{
	MonsterVec = new Vector<MonsterBase*>;
}

void MonsterManager::monsterVecMove(MonsterBase* pmonster)
{
	std::function<void(float)> Addmonster = [this, pmonster](float)
		{
			if (pmonster) {
				pmonster->setMonster();
				MonsterVec->pushBack(pmonster);
			}
			count--;
			if (count == 0)
				this->unschedule("Addmonster");
		};
	this->schedule(Addmonster, 1.0f, "Addmonster");
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
		if (currentMonster->IsDead()) {
			count++;
		}
	}
	if (icount == MONSTERMAX)
		return false;
	else
		return false;
}