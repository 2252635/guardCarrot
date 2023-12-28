#include"TowerStar.h"
void TowerStar::setParameter()
{
	grade = 1;//��ʼʱ���÷������ȼ�Ϊ1
	price = STAR_PRICE;//���ü۸�
	setDAttack(STAR_DEFAULT_ATTACK);//����Ĭ�ϵĹ�����
	setDAttackRange(STAR_DEFAULT_ATTACK_RANGE);//����Ĭ�Ϲ�����Χ
	setCanRotate(false);//���Ƿ����ת��״̬����Ϊ��

	setDUpCost(STAR_DEFAULT_UP_COST);//����Ĭ������ʱ�Ļ��Ѳ���
	setDAttack(STAR_DEFAULT_DATTACK);//����Ĭ������ʱ���ӵĹ���������
	setDAttackRange(STAR_DEFAULT_DATTACK_RANGE);//����Ĭ�ϵ�����ʱ���ӵĹ�����Χ����

	this->schedule(CC_SCHEDULE_SELECTOR(TowerStar::chooseTarget), 0.1);
	this->schedule(CC_SCHEDULE_SELECTOR(TowerStar::fire), 1);
	gradeMark = Sprite::create("������ͼƬ" + std::to_string(grade));
}

void TowerStar::fireAction()
{
	auto myBullet = new StarBullet;
	auto ref = myBullet->create(grade, STAR_BULLET, target, towerPanel->getPosition());//����һ���ӵ�����ȡ�ӵ�ָ��
	if (!ref)
		throw "StarTowerAttackFalse";
	myBullet->autorelease();//��ӵ��Զ��ͷų���
	myBullet->attack(attack, false);//���ӵ����й���
}