#pragma once
#include "PublicDefine.h"
#include "BarrierBase.h"

class BarrierManager:public Node
{
protected:
	~BarrierManager();
	bool init();
private:
	Vector<BarrierBase*>* BarrierVec = nullptr;
public:
	Vector<BarrierBase*>& getVec() { return *BarrierVec; };
	bool checkTarget();
	void addBarrier(BarrierBase* pbarrier);
};