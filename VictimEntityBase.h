#pragma once
#include "PublicDefine.h"
#include"Hp.h"

class VictimEntityBase:public Node
{
protected:
	virtual bool init();
	virtual void whenHurt(int atkValue, int slowTime);
	virtual void whenDead();
	virtual void hurtAction()=0;
	virtual void whenLoacked();
	virtual Sprite* setVictim(Vec2 _positon);
	CC_SYNTHESIZE_PASS_BY_REF(float, beSlowTime, BeSlowTime);
	//CC_SYNTHESIZE_PASS_BY_REF(Vec2, startPosition, StartPosition);
	Hp* myHp;
	bool IsTarget = false;
	bool isDead = false;
public:
	virtual ~VictimEntityBase();
	virtual bool IsDead() { return isDead; };
private:
	//CC_SYNTHESIZE_PASS_BY_REF(float, myHp, MyHp);
	Sprite* beLocked;
	Vec2 position;
	Size size;
};