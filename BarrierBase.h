#pragma once
#ifndef _CARROT_BARRIER_BASE_
#define _CARROT_BARRIER_BASE_
#include "VictimEntityBase.h"

class BarrierBase :public VictimEntityBase
{
protected:
	void hurtAction();
private:
	Sprite* barrier;
public:
	Sprite* setVictim(Vec2 _position);
	void unsetVictim();
	Sprite* getBarrier() { return barrier; };
	bool init();
	void create(Vec2 _pos);
	void whenDead();
};
#endif