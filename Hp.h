#pragma once
#ifndef __CARROT__HP__
#define __CARROT__HP__
#include "Entity.h"
#include "ui/CocosGUI.h"

class Hp :public ui::LoadingBar
{
private:
	CC_SYNTHESIZE(int, maxHp, MaxHp);//���Ѫ��
	CC_SYNTHESIZE(int, nowHp, NowHp);//��ǰѪ��
	/*Hp* pHp;*/

public:

	/*~Hp() {CC_SAFE_RELEASE() };*/
	void changeHpBy(int atkValue);

	void updateHp();//����Ѫ��

	bool init(int hp);

	/*static Hp* create(int hp);*/

};


#endif