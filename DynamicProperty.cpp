#include"DynamicProperty.h"
Label*DynamicProperty::init()
{
	money = DEFAULT_MONEY;//初始化金币数量
	moneyLabel = Label::createWithTTF(StringUtils::format("金币: %d", money), "fonts/arial.ttf", 24);
	moneyLabel->setPosition(Vec2(100, 100));//设置金币位置
	return moneyLabel;

}
void DynamicProperty::showMoney()
{
	moneyLabel->setString(StringUtils::format("金币: %d", money));
}
void DynamicProperty::monsterDead(int dm)
{
	money += dm;
	showMoney();
}
void DynamicProperty::towerDead(int dm)
{
	money += dm;
	showMoney();
}
void DynamicProperty::towerBuild(int dm)
{
	money -= dm;
	showMoney();
}