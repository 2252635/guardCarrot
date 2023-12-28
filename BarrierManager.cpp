#include "BarrierManager.h"


BarrierManager::~BarrierManager()
{
	CC_SAFE_DELETE(BarrierVec);
}

bool BarrierManager::init()
{
	BarrierVec = new Vector<BarrierBase*>;
}

void BarrierManager::addBarrier(BarrierBase* pbarrier)
{
	if (pbarrier) {
		pbarrier->setBarrier();
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