#pragma once
#ifndef _CARROT_BULLET_BASE_
#define _CARROT_BULLET_BASE_
#include"PublicDefine.h"
#include"VictimEntityBase.h"

class VictimEntityBase;
class BulletBase:public Node
{

private:
	Sprite* bulletPanel;//�ӵ�ͼƬ
	VictimEntityBase* target;//�ӵ��Ĺ���Ŀ��
protected:
	BulletType myType;//ָ���ӵ�������
	bool isSlow;
public:
	BulletBase* create(int grade,BulletType type,VictimEntityBase* newTarget,Vec2 startPos);//�����ӵ������ù���Ŀ��ĺ���
	virtual void setParameter();
	void move();//�����ƶ��ĺ���
    void attack(int hurt, bool beSlow);//ִ�й��������ĺ���
	~BulletBase();//��������

};
#endif