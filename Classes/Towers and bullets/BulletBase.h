#pragma once
#ifndef _CARROT_BULLET_BASE_
#define _CARROT_BULLET_BASE_
#include"VictimEntityBase.h"

class VictimEntityBase;
class BulletBase:public Node
{

protected:
	Sprite* bulletPanel;//�ӵ�ͼƬ
	VictimEntityBase* target;//�ӵ��Ĺ���Ŀ��

	BulletType myType;//ָ���ӵ�������
	bool isSlow;
public:
	BulletBase* create(int grade,BulletType type,VictimEntityBase* newTarget,Vec2 startPos);//�����ӵ������ù���Ŀ��ĺ���
	virtual void setParameter()=0;
	void move();//�����ƶ��ĺ���
    virtual void attack(int hurt, bool beSlow)=0;//ִ�й��������ĺ���
	Sprite* getBullet() { return bulletPanel; };
	virtual~BulletBase();//��������

};
#endif