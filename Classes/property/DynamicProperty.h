#pragma once
#ifndef _CARROT_DYNAMIC_PROPERTY_
#define _CARROT_DYNAMIC_PROPERTY_
#include "Entity.h"
class DynamicProperty :public Entity
{
private:
	int money;//��Ǯ����
	Label *moneyLabel;
public:
	bool init()override;
	//void showMoney();//��ʾ��������ĺ���
	int getMoney() { return money; };//��ȡ��ǰ��Ǯ����
	void monsterDead(int dm);//��ɱ����ʱ��Ǯ�ı仯��
	void towerDead(int dm);//���������ʱ��Ǯ�ı仯��
	void towerBuild(int dm);//���������ʱ��Ǯ�ı仯��

};
#endif