#pragma once
#ifndef _CARROT_TOWER_SHIT_
#define _CARROT_TOWER_SHIT_
#include"TowerBase.h"

class TowerShit :public TowerBase
{
public:
	void setParameter();//���ò���
	bool doUpAction();//��������
	void fireAction(Vec2 endPos)override;//���������Ķ���
};
#endif