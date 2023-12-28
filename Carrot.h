#pragma once
#ifndef __Carrot__Carrot__
#define __Carrot__Carrot__

#include "VictimEntityBase.h"
#include "PublicDefine.h"

class Carrot:public VictimEntityBase
{
public:
	bool init(Vec2 position);
	Carrot* create(Vec2 position);
	void hurtAction();
	void setCarrot();
	bool levelUp();
private:
	CC_SYNTHESIZE_PASS_BY_REF(Vec2, carrotPosition, CarrotPosition);
	Sprite* carrot;
	
};

#endif