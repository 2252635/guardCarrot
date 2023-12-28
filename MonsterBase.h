#pragma once
#include "PublicDefine.h"
#include "VictimEntityBase.h"
#include <vector>

class MonsterBase:public VictimEntityBase
{
public:
	void setMonster();
	Sprite* setVictim(Vec2 _position);
	void unsetVictim();
	Vec2 startPosition;
protected:
	virtual bool init(std::vector<Vec2> _path, Vec2 position);
	static MonsterBase* create(std::vector<Vec2> _path, Vec2 position);
	virtual void hurtAction();
	void move(float dt);
	void whenDead();
private:
	CC_SYNTHESIZE_PASS_BY_REF(MonsterType, nowMonsterType, NowMonsterType);
	CC_SYNTHESIZE_PASS_BY_REF(int, normSpeed, NormSpeed);
	CC_SYNTHESIZE_PASS_BY_REF(int, slowSpeed, SlowSpeed);
	CC_SYNTHESIZE_PASS_BY_REF(int, nowSpeed, NowSpeed);
	std::vector<Vec2> path;
	Sprite* monster;

};