#pragma once
#ifndef _CARROT_TOWER_STAR_
#define _CARROT_TOWER_STAR_
#include "PublicDefine.h"
#include"TowerBase.h"
#include"StarBullet.h"

class TowerStar :public TowerBase
{
public:
	void setParameter();//���ò���
	bool doUpAction();//��������
	void fire();//���й����ĺ���
	void fireAction();//���������Ķ���
};
#endif