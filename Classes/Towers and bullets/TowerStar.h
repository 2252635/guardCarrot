#pragma once
#ifndef _CARROT_TOWER_STAR_
#define _CARROT_TOWER_STAR_
#include"TowerBase.h"
#include"StarBullet.h"

class TowerStar :public TowerBase
{
public:
	void setParameter();//���ò���
	bool doUpAction();//��������
	void fireAction(Vec2 endPos)override;//���������Ķ���
};
#endif