#include"DynamicProperty.h"

int DynamicProperty::money = DEFAULT_MONEY;
LabelTTF *DynamicProperty::moneyLabel=nullptr;

bool DynamicProperty::init()
{
	/*moneyLabel = Label::createWithTTF(StringUtils::format("金币: %d", money), "fonts/arial.ttf", 24);*/
	moneyLabel = LabelTTF::create(StringUtils::format("金币: %d", money), "Market Felt", 24);
	/*moneyLabel->setTextColor(Color4B::RED);*/
	moneyLabel->setPosition(Vec2(MAP_ROW / 2 * BLOCK_SIZE, (MAP_COL / 2-1) * BLOCK_SIZE));//设置金币位置
	return true;
}
//void DynamicProperty::showMoney()
//{
//	moneyLabel->setString(StringUtils::format("金币: %d", money));
//}
void DynamicProperty::monsterDead(int dm)
{
	money += dm;
	/*showMoney();*/
}
void DynamicProperty::towerDead(int dm)
{
	money += dm;
	/*showMoney();*/
}
void DynamicProperty::towerBuild(int dm)
{
	money -= dm;
	/*showMoney();*/
}