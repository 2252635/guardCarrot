#pragma once
#ifndef __Carrot__Carrot__
#define __Carrot__Carrot__

#include "VictimEntityBase.h"

class Carrot:public VictimEntityBase
{
public:
	bool init(Vec2 position);
	Carrot* create(Vec2 position);
	void hurtAction();
	bool levelUp();
	Sprite* getCarrotSprite() { return pcarrot; };
private:
	CC_SYNTHESIZE_PASS_BY_REF(Vec2, carrotPosition, CarrotPosition);
	Sprite* pcarrot;
	CC_SYNTHESIZE_PASS_BY_REF(int, level, Level);
};

#endif