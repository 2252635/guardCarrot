#pragma once
#ifndef _CARROT_TOWERBASE_
#define _CARROT_TOWERBASE_
#include "VictimEntityBase.h"

class TowerBase :public Node
{
protected:
	Sprite* towerPanel;//指向塔的图片的指针
	Sprite* towerBase;
	/*Sprite* gradeMark;*/
	VictimEntityBase* target;//指向攻击目标的函数
	TowerType type;//防御塔类型
	int attack;//攻击力
	int grade;//等级
	int attackRange;//攻击范围
	int upCost;//升级时花费的价格
	int price;//防御塔价格
	Scheduler* scheduler1;
	Scheduler* scheduler2;
public:
	TowerBase() :grade(1),target(nullptr) {};
	TowerBase* init(TowerType type,Vec2 targetPos, Sprite* &newTowerBase);//给塔的类型并根据类型进行初始化
	bool isInAttackRange(VictimEntityBase* newTarget);//判断NewTarget是否在防御塔攻击范围内的函数
	void setTarget(VictimEntityBase* newTarget);//将newTarget设置为攻击目标的函数
	void chooseTarget(float dt);//从一排怪物中选择攻击目标的函数
	void missTarget();
	bool upGrade(int money);//给防御塔升级的函数
	const Vec2& getPos() { return towerPanel->getPosition(); };
	TowerType getType() { return type; };
	virtual bool doUpAction()=0;
	bool checkMoney(int money);//检查金币是否足够
	virtual void setParameter()=0;//在塔初始化时设置攻击力、攻击范围、升级花费等参数
	void fire(float dt);//攻击函数
	virtual void rotate(){};//进行旋转的函数
	virtual void fireAction(Vec2 endPos)=0;//攻击动作的函数
	Sprite* getTowerPanel() { return towerPanel;};
	int getGrade() { return grade; };
	int getUpCost() { return upCost; };
	int getPrice() { return price; };
	//void showGradeMark();//显示等级面板
	//void hideGradeMark();//隐藏等级面板
	CC_SYNTHESIZE_PASS_BY_REF(bool, canRotate, CanRotate);//标识塔能否旋转的变量
	CC_SYNTHESIZE_PASS_BY_REF(bool, haveTarget, HaveTarget);//标识防御塔是否有攻击目标的变量
	CC_SYNTHESIZE_PASS_BY_REF(int, dAttack, DAttack);//攻击力增加的步长
	CC_SYNTHESIZE_PASS_BY_REF(int, dAttackRange, DAttackRange);//攻击范围的增量
	CC_SYNTHESIZE_PASS_BY_REF(int, dUpCost, DUpCost);
	virtual~TowerBase();//析构函数
};
#endif