#pragma once
#ifndef _CARROT_VICTIM_
#define _CARROT_VICTIM_
#include "Hp.h"
class VictimEntityBase:public Entity
{
protected:
	CC_SYNTHESIZE_PASS_BY_REF(float, beSlowTime, BeSlowTime);
	//CC_SYNTHESIZE_PASS_BY_REF(Vec2, startPosition, StartPosition);
	Hp* myHp;
	bool IsTarget = false;
	bool isDead = false;
	Vec2 position;
	Sprite* victim;
public:
	virtual ~VictimEntityBase();
	virtual bool IsDead() { return isDead; };
	virtual void whenHurt(int atkValue, int slowTime);
	virtual void whenDead();
	virtual void hurtAction() = 0;
	virtual void whenLoacked();
	virtual bool init();
	Sprite* getVictim() { return victim; };
private:
	Sprite* beLocked;
	//CC_SYNTHESIZE_PASS_BY_REF(float, myHp, MyHp);
	Size size;
};
#endif