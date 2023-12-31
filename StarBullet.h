#pragma once
#ifndef _CARROT_STAR_BULLET_
#define _CARROT_STAR_BULLET_

#include"BulletBase.h"
class StarBullet :public BulletBase
{
public:
	void setParameter();
	void attack(int attack, bool beSlow);
};

#endif