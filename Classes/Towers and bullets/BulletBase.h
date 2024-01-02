#pragma once
#ifndef _CARROT_BULLET_BASE_
#define _CARROT_BULLET_BASE_
#include"VictimEntityBase.h"

class VictimEntityBase;
class BulletBase:public Node
{

protected:
	Sprite* bulletPanel;//子弹图片
	VictimEntityBase* target;//子弹的攻击目标

	BulletType myType;//指明子弹的类型
	bool isSlow;
public:
	BulletBase* create(int grade,BulletType type,VictimEntityBase* newTarget,Vec2 startPos);//创建子弹并设置攻击目标的函数
	virtual void setParameter()=0;
	void move();//进行移动的函数
    virtual void attack(int hurt, bool beSlow)=0;//执行攻击操作的函数
	Sprite* getBullet() { return bulletPanel; };
	virtual~BulletBase();//析构函数

};
#endif