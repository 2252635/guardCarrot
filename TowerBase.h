#pragma once
#ifndef _CARROT_TOWERBASE_
#define _CARROT_TOWERBASE_
#include "PublicDefine.h"
class VictimEntityBase;
class TowerBase :public Node
{
protected:
	Sprite* towerPanel;//ָ������ͼƬ��ָ��
	Sprite* gradeMark;
	VictimEntityBase* target;//ָ�򹥻�Ŀ��ĺ���
<<<<<<< HEAD
	int grade;
	int attack;//������
=======
	TowerType type;//����������
	int attack;//������
	int grade;//�ȼ�
>>>>>>> 3cc07b4 (lyy2)
	int attackRange;//������Χ
	int upCost;//����ʱ���ѵļ۸�
	int price;//�������۸�

public:
	TowerBase() :grade(1) {};
	TowerBase* init(TowerType type,Vec2 targetPos);//���������Ͳ��������ͽ��г�ʼ��
	bool isInAttackRange(VictimEntityBase* newTarget);//�ж�NewTarget�Ƿ��ڷ�����������Χ�ڵĺ���
	void setTarget(VictimEntityBase* newTarget);//��newTarget����Ϊ����Ŀ��ĺ���
	void chooseTarget();//��һ�Ź�����ѡ�񹥻�Ŀ��ĺ���
	void missTarget();
<<<<<<< HEAD
	bool upGrade(std::string&FileName);//�������������ĺ���
	virtual bool doUpAction();
	bool checkMoney();//������Ƿ��㹻
=======
	bool upGrade(int money);//�������������ĺ���
	const Vec2& getPos() { return towerPanel->getPosition(); };
	TowerType getType() { return type; };
	virtual bool doUpAction();
	bool checkMoney(int money);//������Ƿ��㹻
>>>>>>> 3cc07b4 (lyy2)
	virtual void setParameter();//������ʼ��ʱ���ù�������������Χ���������ѵȲ���
	virtual void fire();//��������
	virtual void rotate();//������ת�ĺ���
	virtual void fireAction();//���������ĺ���
	void showGradeMark();//��ʾ�ȼ����
	void hideGradeMark();//���صȼ����
	CC_SYNTHESIZE_PASS_BY_REF(bool, canRotate, CanRotate);//��ʶ���ܷ���ת�ı���
	CC_SYNTHESIZE_PASS_BY_REF(bool, haveTarget, HaveTarget);//��ʶ�������Ƿ��й���Ŀ��ı���
	CC_SYNTHESIZE_PASS_BY_REF(int, dAttack, DAttack);//���������ӵĲ���
	CC_SYNTHESIZE_PASS_BY_REF(int, dAttackRange, DAttackRange);//������Χ������
	CC_SYNTHESIZE_PASS_BY_REF(int, dUpCost, DUpCost);
	~TowerBase();//��������
};
#endif