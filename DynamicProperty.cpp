#include"DynamicProperty.h"
Label*DynamicProperty::init()
{
	money = DEFAULT_MONEY;//��ʼ���������
	moneyLabel = Label::createWithTTF(StringUtils::format("���: %d", money), "fonts/arial.ttf", 24);
	moneyLabel->setPosition(Vec2(100, 100));//���ý��λ��
	return moneyLabel;

}
void DynamicProperty::showMoney()
{
	moneyLabel->setString(StringUtils::format("���: %d", money));
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