#ifndef _TOWER_BASE_
#define _TOWER_BASE_
#include "Enity.h"
#pragma once
#define TOWER_ICE
#define TOWER_BOTTLE
#define TOWER_SLOW
#define TOWER_ELECTRIC
class VictimEntityBase;

class Tower:public Entity 
{
protected:
	Sprite* MyTower;//ָ��������ָ��
	Sprite* Grade;//ָ��ȼ�����ָ��
	VictimEntityBase* Target;//����Ŀ��

	virtual bool Initiate();
	virtual void InitTower();
	virtual void DeadMove(const std::string& DeadImageFile = "")override;
	virtual void Attack(float Delta);//���й���
	virtual void AttackMove();//�����ӵ�ʱ�Ķ���
	virtual void Ratate(float Delta);//��תһ���ĽǶ�
	virtual void CheckTarget(float Delta);//��鹥��Ŀ��
	virtual void ChooseTarget();//ѡ�񹥻�Ŀ��
	virtual void MissAtkTarget();

	CC_SYNTHESIZE_PASS_BY_REF(int, BulletId, BulletId);//�����ӵ����ڽ���ŵı���
	CC_SYNTHESIZE_PASS_BY_REF(int, AttackSpeed, AttackSpeed);//����÷����������ٶȵı���
	CC_SYNTHESIZE_PASS_BY_REF(int, AttackRange, AttackRange);//����÷�����������Χ�ı���
	CC_SYNTHESIZE_PASS_BY_REF(std::string, UpCost, UpCost);//������������������ı���
	CC_SYNTHESIZE_PASS_BY_REF(int, AttackUp, AttackUp);//����������ʱ���Ե���ǿ
	CC_SYNTHESIZE_PASS_BY_REF(bool, IsRotate, IsRotate);//��ʾ�������Ƿ�����ת�ı���
	CC_SYNTHESIZE_PASS_BY_REF(int, CreateCost, CreateCost);//���������������ʱ�����ı���
	CC_SYNTHESIZE_PASS_BY_REF(bool, HaveTarget, HaveTarget);//��ʶ�������Ƿ��й���Ŀ��ı���
public:
	static Tower* PlaceTower(const int Id);//���÷�����
	virtual void GradeUp();//����������
	virtual int ShowGrade();//��ʾ�������ȼ��Ľӿں���
	virtual int HideGrade();//���ط������ȼ�
	virtual bool IsInAttackRange(const Vec2& Pos);//�ж�Ŀ�굱ǰ�Ƿ��ڹ�����Χ��
	virtual void SetTarget(VictimEntityBase* NewTarget);//���ù���Ŀ��
	virtual bool ChangeTarget();//�л�����Ŀ��
	virtual ~Tower();//��������
};

#endif