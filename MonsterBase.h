#pragma once
#ifndef _CARROT_MONSTER_BASE_
#define _CARROT_MONSTER_BASE_
#include "VictimEntityBase.h"
#include <vector>

class MonsterBase:public VictimEntityBase
{
public:
	bool monsterMove(std::vector<Vec2> path, MonsterType type);
	Sprite* setVictim(Vec2 _position);
	void unsetVictim();
	Vec2 startPosition;
	void create( Vec2 position);
	Sprite* getMonster() { return monster; };
protected:
	virtual bool init(Vec2 position);
	void hurtAction()override;
	//void move(float dt, MonsterType type);
	void whenDead();
private:
	CC_SYNTHESIZE_PASS_BY_REF(MonsterType, nowMonsterType, NowMonsterType);
	CC_SYNTHESIZE_PASS_BY_REF(float, normSpeed, NormSpeed);
	CC_SYNTHESIZE_PASS_BY_REF(float, slowSpeed, SlowSpeed);
	CC_SYNTHESIZE_PASS_BY_REF(float, nowSpeed, NowSpeed);
	Sprite* monster;

};

#endif