#pragma once
#ifndef _CARROT_PUBLIC_
#define _CARROT_PUBLIC_
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
using namespace cocos2d;

//�������궨��
#define TOWER_MAX_GRADE 3//������������������

//ƿ����
#define BOTTLE_DEFAULT_UP_COST 40//��������Ĭ����������
#define BOTTLE_DEFAULT_ATTACK 30//Ĭ�Ϲ�����
#define BOTTLE_DEFAULT_ATTACK_RANGE 120//Ĭ�Ϲ�����Χ
#define BOTTLE_PRICE 50//�������۸�

#define BOTTLE_DEFAULT_DATTACK 10//Ĭ�Ϲ�����
#define BOTTLE_DEFAULT_DATTACK_RANGE 20//Ĭ�Ϲ�����Χ

#define BOTTLE_EVERY_ATTACK_RANGE 20//ƿ����ÿ��һ��������Χ������
#define BOTTLE_EVERY_ATTACK 10//ƿ�����Ĺ���������ֵ
#define BOTTLE_EVERY_UP_COST 10//ƿ������������������ֵ

//������
#define STAR_DEFAULT_UP_COST 60//��������Ĭ����������
#define STAR_DEFAULT_ATTACK 10//Ĭ�Ϲ�����
#define STAR_DEFAULT_ATTACK_RANGE 120//Ĭ�Ϲ�����Χ
#define STAR_PRICE 120

#define STAR_DEFAULT_DATTACK 20//Ĭ�Ϲ�����
#define STAR_DEFAULT_DATTACK_RANGE 20//Ĭ�Ϲ�����Χ

#define STAR_EVERY_ATTACK_RANGE 20//ƿ����ÿ��һ��������Χ������
#define STAR_EVERY_ATTACK 20//ƿ�����Ĺ���������ֵ
#define STAR_EVERY_UP_COST 15//ƿ������������������ֵ

//ʺ��
#define SHIT_DEFAULT_UP_COST 40//��������Ĭ����������
#define SHIT_DEFAULT_ATTACK 30//Ĭ�Ϲ�����
#define SHIT_DEFAULT_ATTACK_RANGE 120//Ĭ�Ϲ�����Χ
#define SHIT_PRICE 80

#define SHIT_DEFAULT_DATTACK 10//Ĭ�Ϲ�����
#define SHIT_DEFAULT_DATTACK_RANGE 20//Ĭ�Ϲ�����Χ

#define SHIT_EVERY_ATTACK_RANGE 20//ƿ����ÿ��һ��������Χ������
#define SHIT_EVERY_ATTACK 10//ƿ�����Ĺ���������ֵ
#define SHIT_EVERY_UP_COST 10//ƿ������������������ֵ

//��Ǯ
#define DEFAULT_MONEY 200//����ʱ��Ĭ�Ͻ������

//��ͼ
#define MAP_ROW 18
#define MAP_COL 12

#define BLOCK_SIZE 80

enum BulletType
{
	BOTTLE_BULLET,
	STAR_BULLET,
	SHIT_BULLET
};//�������͵��ӵ�
enum TowerType
{
	BOTTLE,
	STAR,
	SHIT
};//�������͵���
//std::map<TowerType, std::string> TowerTypeName = {
//	{BOTTLE, "BottleTower"},
//	{STAR, "StarTower"},
//	{SHIT, "ShitTower"}
//};
enum BlockType
{
	ROAD,
	TOWER,
	NO_TOWER,
	BARRIER
};

//�йس���
enum Scenes
{
	MAP_BLUE_VIEW,
	MAP_PURPLE_VIEW,
	END_WIN,
	END_LOSE,
	MAP_BLUE,
	MAP_PURPLE,
	START,
	HELP
};

//��������
#define MONSTERMAX 10//���θ���
#define BATCH 2//��������
#define BATCH_INTERNAL 5.0f//���μ��

enum MonsterType
{
	NORMAL = 1,
	FAST,
	SLOW,
};

enum BarrierType
{
	BALL_ONE,
	BALL_TWO,
	CLOUD_BLUE,
	CLOUD_PURPLE,
};


#endif