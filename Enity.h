#pragma once
#ifndef _Enity_
#define _Enity_

#include "PublicDefine.h"
//������
class Entity:public Node//cocos��Node������
{
public:
	~Entity();//��������
	static int Num;//�������
	int GetNum();//��ȡ�����
	virtual bool Initiate(int num, const std::string& CsvFileName);
	virtual const Size& GetSize()const;
	virtual void Dead()final;
	virtual void BindSprite(Sprite* Target);
	virtual Sprite* GetSprite();
	virtual Rect GetBoundingBox()const;
protected:
	virtual void DeadMove(const std::string& DeadImageFile="");
	virtual void InitiateProperty(const int Src, const std::string& CsvFileName);

	CC_SYNTHESIZE_PASS_BY_REF(int, Id, Id);//�ṩ���úͷ���ĳЩ�����Ľӿں���
	CC_SYNTHESIZE_PASS_BY_REF(std::string, Name, Name); //Enity������
	CC_SYNTHESIZE_PASS_BY_REF(std::string, FileName, FileName);//Enity��Ӧͼ����ļ���
	CC_SYNTHESIZE_PASS_BY_REF(int, Value, Value); //Enity�ļ�ֵ
	CC_SYNTHESIZE_PASS_BY_REF(bool, IsDead, IsDead);//Enity�Ƿ������ı�־
	CC_SYNTHESIZE_PASS_BY_REF(int, AnimationFrameCount, AnimationFrameCount);
	CC_SYNTHESIZE_PASS_BY_REF(int, Grade, Grade);//Enity�ȼ�
private:
	Sprite* MySprite;//ָ�����ָ��
	static int MyNo;//��¼��ǰ���ı��
};
#endif _Enity_