#pragma once
#ifndef _PUBLIC_DEFINE_
#define _PUBLIC_DEFINE_
//ͷ�ļ�
#include "cocos2d.h"

using namespace cocos2d;

//�������궨��
#define TOWER_MAX_GRADE 3//������������������

//ƿ����
#define BOTTLE_DEFAULT_UP_COST//��������Ĭ����������
#define BOTTLE_DEFAULT_ATTACK 5//Ĭ�Ϲ�����
#define BOTTLE_DEFAULT_ATTACK_RANGE//Ĭ�Ϲ�����Χ
#define BOTTLE_PRICE//�������۸�

#define BOTTLE_DEFAULT_DATTACK//Ĭ�Ϲ�����
#define BOTTLE_DEFAULT_DATTACK_RANGE//Ĭ�Ϲ�����Χ

#define BOTTLE_EVERY_ATTACK_RANGE 20//ƿ����ÿ��һ��������Χ������
#define BOTTLE_EVERY_ATTACK 10//ƿ�����Ĺ���������ֵ
#define BOTTLE_EVERY_UP_COST//ƿ������������������ֵ

//������
#define STAR_DEFAULT_UP_COST//��������Ĭ����������
#define STAR_DEFAULT_ATTACK 10//Ĭ�Ϲ�����
#define STAR_DEFAULT_ATTACK_RANGE//Ĭ�Ϲ�����Χ
#define STAR_PRICE

#define STAR_DEFAULT_DATTACK1 //Ĭ�Ϲ�����
#define STAR_DEFAULT_DATTACK_RANGE//Ĭ�Ϲ�����Χ

#define STAR_EVERY_ATTACK_RANGE 20//ƿ����ÿ��һ��������Χ������
#define STAR_EVERY_ATTACK 10//ƿ�����Ĺ���������ֵ
#define STAR_EVERY_UP_COST//ƿ������������������ֵ

//ʺ��
#define SHIT_DEFAULT_UP_COST//��������Ĭ����������
#define SHIT_DEFAULT_ATTACK 5//Ĭ�Ϲ�����
#define SHIT_DEFAULT_ATTACK_RANGE//Ĭ�Ϲ�����Χ
#define SHIT_PRICE

#define SHIT_DEFAULT_DATTACK//Ĭ�Ϲ�����
#define SHIT_DEFAULT_DATTACK_RANGE//Ĭ�Ϲ�����Χ

#define SHIT_EVERY_ATTACK_RANGE 20//ƿ����ÿ��һ��������Χ������
#define SHIT_EVERY_ATTACK 10//ƿ�����Ĺ���������ֵ
#define SHIT_EVERY_UP_COST//ƿ������������������ֵ



enum TowerType
{
	BOTTLE,
	STAR,
	SHIT
};//�������͵���
enum BulletType
{
	BOTTLE_BULLET,
	STAR_BULLET,
	SHIT_BULLET
};//�������͵��ӵ�
#endif