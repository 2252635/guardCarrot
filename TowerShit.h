#pragma once
#ifndef _CARROT_TOWER_SHIT_
#define _CARROT_TOWER_SHIT_
#include"PublicDefine.h"
#include"TowerBase.h"
#include"ShitBullet.h"

class TowerShit :public TowerBase
{
public:
	void setParameter();//���ò���
	bool doUpAction();//��������
	void fire();//���й����ĺ���
	void fireAction();//���������Ķ���
};
#endif