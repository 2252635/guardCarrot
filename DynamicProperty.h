#pragma once
#ifndef _CARROT_DYNAMIC_PROPERTY_
#define _CARROT_DYNAMIC_PROPERTY_
#include "Entity.h"
class DynamicProperty :public Entity
{
private:
	static int money;//��Ǯ����
	static LabelTTF *moneyLabel;
public:
	/*DynamicProperty();*/
	bool init()override;
	static void showMoney();//��ʾ��������ĺ���
	static int getMoney() { return money; };//��ȡ��ǰ��Ǯ����
	static void monsterDead(int dm);//��ɱ����ʱ��Ǯ�ı仯��
	static void towerDead(int dm);//���������ʱ��Ǯ�ı仯��
	static void towerBuild(int dm);//���������ʱ��Ǯ�ı仯��
	static LabelTTF* getMoneyLabel() { return moneyLabel; };

};
#endif