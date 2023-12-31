#pragma once
#ifndef _CARROT_BARRIER_MANAGER_
#define _CARROT_BARRIER_NAMAGER_
#include "BarrierBase.h"

class BarrierManager:public Node
{
protected:
	~BarrierManager();
private:
	Vector<BarrierBase*>* BarrierVec = nullptr;
public:
	Vector<BarrierBase*>& getVec() { return *BarrierVec; };
	bool checkTarget();
	void addBarrier(BarrierBase* pbarrier, BarrierType type);
	bool init()override;
};
#endif