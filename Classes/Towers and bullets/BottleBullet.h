#pragma once
#ifndef _CARROT_BOTTLE_BULLET_
#define _CARROT_BOTTLE_BULLET_
#include"BulletBase.h"
class BottleBullet :public BulletBase
{
public:
	void setParameter();//���ò���
	void attack(int attack, bool beSlow);
};
#endif