#include"TowerShit.h"
void TowerShit::setParameter()
{
	grade = 1;//��ʼʱ���÷������ȼ�Ϊ1
	price = SHIT_PRICE;//���ü۸�
	setDAttack(SHIT_DEFAULT_ATTACK);//����Ĭ�ϵĹ�����
	setDAttackRange(SHIT_DEFAULT_ATTACK_RANGE);//����Ĭ�Ϲ�����Χ
	setCanRotate(true);//���Ƿ����ת��״̬����Ϊ��

	setDUpCost(SHIT_DEFAULT_UP_COST);//����Ĭ������ʱ�Ļ��Ѳ���
	setDAttack(SHIT_DEFAULT_DATTACK);//����Ĭ������ʱ���ӵĹ���������
	setDAttackRange(SHIT_DEFAULT_DATTACK_RANGE);//����Ĭ�ϵ�����ʱ���ӵĹ�����Χ����

	this->schedule(CC_SCHEDULE_SELECTOR(TowerBottle::chooseTarget), 0.1);
	this->schedule(CC_SCHEDULE_SELECTOR(TowerBottle::fire), 1);
	gradeMark = Sprite::create("" + std::to_string(grade));
}
bool TowerShit::doUpAction()
{
	if (upGrade("ƿ��������"))
		return true;
	return false;
}
void TowerShit::fireAction()
{
	rotate();//��ת
	auto myBullet = new ShitBullet;
	auto ref = myBullet->create(grade, SHIT_BULLET, target, towerPanel->getPosition());//����һ���ӵ�����ȡ�ӵ�ָ��
	if (!ref)
		throw "ShitTowerAttackFalse";
	myBullet->autorelease();//��ӵ��Զ��ͷų���
	myBullet->attack(attack, false);//���ӵ����й���
}