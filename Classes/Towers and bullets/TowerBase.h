#pragma once
#ifndef _CARROT_TOWERBASE_
#define _CARROT_TOWERBASE_
#include "VictimEntityBase.h"

class TowerBase :public Node
{
protected:
	Sprite* towerPanel;//ָ������ͼƬ��ָ��
	Sprite* towerBase;
	/*Sprite* gradeMark;*/
	VictimEntityBase* target;//ָ�򹥻�Ŀ��ĺ���
	TowerType type;//����������
	int attack;//������
	int grade;//�ȼ�
	int attackRange;//������Χ
	int upCost;//����ʱ���ѵļ۸�
	int price;//�������۸�
	Scheduler* scheduler1;
	Scheduler* scheduler2;
public:
	TowerBase() :grade(1),target(nullptr) {};
	TowerBase* init(TowerType type,Vec2 targetPos, Sprite* &newTowerBase);//���������Ͳ��������ͽ��г�ʼ��
	bool isInAttackRange(VictimEntityBase* newTarget);//�ж�NewTarget�Ƿ��ڷ�����������Χ�ڵĺ���
	void setTarget(VictimEntityBase* newTarget);//��newTarget����Ϊ����Ŀ��ĺ���
	void chooseTarget(float dt);//��һ�Ź�����ѡ�񹥻�Ŀ��ĺ���
	void missTarget();
	bool upGrade(int money);//�������������ĺ���
	const Vec2& getPos() { return towerPanel->getPosition(); };
	TowerType getType() { return type; };
	virtual bool doUpAction()=0;
	bool checkMoney(int money);//������Ƿ��㹻
	virtual void setParameter()=0;//������ʼ��ʱ���ù�������������Χ���������ѵȲ���
	void fire(float dt);//��������
	virtual void rotate(){};//������ת�ĺ���
	virtual void fireAction(Vec2 endPos)=0;//���������ĺ���
	Sprite* getTowerPanel() { return towerPanel;};
	int getGrade() { return grade; };
	int getUpCost() { return upCost; };
	int getPrice() { return price; };
	//void showGradeMark();//��ʾ�ȼ����
	//void hideGradeMark();//���صȼ����
	CC_SYNTHESIZE_PASS_BY_REF(bool, canRotate, CanRotate);//��ʶ���ܷ���ת�ı���
	CC_SYNTHESIZE_PASS_BY_REF(bool, haveTarget, HaveTarget);//��ʶ�������Ƿ��й���Ŀ��ı���
	CC_SYNTHESIZE_PASS_BY_REF(int, dAttack, DAttack);//���������ӵĲ���
	CC_SYNTHESIZE_PASS_BY_REF(int, dAttackRange, DAttackRange);//������Χ������
	CC_SYNTHESIZE_PASS_BY_REF(int, dUpCost, DUpCost);
	virtual~TowerBase();//��������
};
#endif