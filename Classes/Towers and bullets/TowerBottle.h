#pragma once
#ifndef _CARROT_TOWER_BOTTLE_
#define _CARROT_TOWER_BOTTLE_
#include "TowerBase.h"
class TowerBottle:public TowerBase
{
public:
	void setParameter();//���ò���
	bool checkMoney();//����Ǯ
	bool doUpAction();//��������
	void rotate();//������ת�ĺ���
	void fireAction(Vec2 endPos)override;//���������Ķ���
};
#endif