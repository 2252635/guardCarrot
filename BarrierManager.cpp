#include "BarrierManager.h"

BarrierManager::~BarrierManager()
{
	CC_SAFE_DELETE(BarrierVec);
}

bool BarrierManager::init()
{
	BarrierVec = new Vector<BarrierBase*>;
	if (BarrierVec)
		return true;
	else
		return false;
}

void BarrierManager::addBarrier(BarrierBase* pbarrier,BarrierType type)
{
	if (pbarrier) {
		BarrierVec->pushBack(pbarrier);
	}
}

bool BarrierManager::checkTarget()
{
	for (auto currentBarrier : *BarrierVec)
		if (currentBarrier->IsTarget)
			return true;
	return false;
}