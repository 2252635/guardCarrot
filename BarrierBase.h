#pragma once
#include "PublicDefine.h"
#include "VictimEntityBase.h"

class BarrierBase :public VictimEntityBase
{
protected:
	bool init(Vec2 position);
	static BarrierBase* create(Vec2 position);
	void hurtAction();
private:
	Sprite* barrier;
	CC_SYNTHESIZE_PASS_BY_REF(Vec2, putPosition, PutPosition);
public:
	void setBarrier();
	Sprite* setVictim(Vec2 position);
	void unsetVictim();
};