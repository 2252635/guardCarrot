#pragma once
#ifndef _Enity_
#define _Enity_

#include "PublicDefine.h"
//东西类
class Entity:public Node//cocos中Node的子类
{
public:
	~Entity();//析构函数
	static int Num;//结点总数
	int GetNum();//获取结点编号
	virtual bool Initiate(int num, const std::string& CsvFileName);
	virtual const Size& GetSize()const;
	virtual void Dead()final;
	virtual void BindSprite(Sprite* Target);
	virtual Sprite* GetSprite();
	virtual Rect GetBoundingBox()const;
protected:
	virtual void DeadMove(const std::string& DeadImageFile="");
	virtual void InitiateProperty(const int Src, const std::string& CsvFileName);

	CC_SYNTHESIZE_PASS_BY_REF(int, Id, Id);//提供设置和访问某些变量的接口函数
	CC_SYNTHESIZE_PASS_BY_REF(std::string, Name, Name); //Enity的名字
	CC_SYNTHESIZE_PASS_BY_REF(std::string, FileName, FileName);//Enity对应图标的文件名
	CC_SYNTHESIZE_PASS_BY_REF(int, Value, Value); //Enity的价值
	CC_SYNTHESIZE_PASS_BY_REF(bool, IsDead, IsDead);//Enity是否死亡的标志
	CC_SYNTHESIZE_PASS_BY_REF(int, AnimationFrameCount, AnimationFrameCount);
	CC_SYNTHESIZE_PASS_BY_REF(int, Grade, Grade);//Enity等级
private:
	Sprite* MySprite;//指向精灵的指针
	static int MyNo;//记录当前结点的编号
};
#endif _Enity_