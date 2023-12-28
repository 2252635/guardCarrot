#include"TowerBottle.h"
#include"BottleBullet.h"
void TowerBottle::setParameter()
{
	grade = 1;//��ʼʱ���÷������ȼ�Ϊ1
	price = BOTTLE_PRICE;//���ü۸�
	setDAttack(BOTTLE_DEFAULT_ATTACK);//����Ĭ�ϵĹ�����
	setDAttackRange(BOTTLE_DEFAULT_ATTACK_RANGE);//����Ĭ�Ϲ�����Χ
	setCanRotate(true);//���Ƿ����ת��״̬����Ϊ��

	setDUpCost(BOTTLE_DEFAULT_UP_COST);//����Ĭ������ʱ�Ļ��Ѳ���
	setDAttack(BOTTLE_DEFAULT_DATTACK);//����Ĭ������ʱ���ӵĹ���������
	setDAttackRange(BOTTLE_DEFAULT_DATTACK_RANGE);//����Ĭ�ϵ�����ʱ���ӵĹ�����Χ����

	this->schedule(CC_SCHEDULE_SELECTOR((TowerBottle::chooseTarget), 0.1);
	this->schedule(CC_SCHEDULE_SELECTOR(TowerBottle::fire), 1);
	gradeMark = Sprite::create("" + std::to_string(grade));
}
bool TowerBottle::doUpAction()
{
	if (upGrade("ƿ��������"))
		return true;
	return false;
}
void TowerBottle::rotate()
{
	auto targetPos = target->getPosition();
	auto myPos = towerPanel->getPosition();//��ȡ�Լ���������λ��

	auto direction = targetPos - myPos;
	float angleRadians = atan2(direction.y, direction.x)%M_PI/2;//���㻡��
	float angleDegree= CC_RADIANS_TO_DEGREES(angleRadians);//����ת�Ƕ�
	towerPanel->setRotation(-angleDegree);//������ת
}
void TowerBottle::fireAction()
{
	rotate();//��ת
	auto myBullet = new BottleBullet;
	auto ref=myBullet->create(grade,BOTTLE_BULLET,target,towerPanel->getPosition());//����һ���ӵ�����ȡ�ӵ�ָ��
	if (!ref)
		throw "BottleTowerAttackFalse";
	myBullet->autorelease();//��ӵ��Զ��ͷų���
	myBullet->attack(attack,false);//���ӵ����й���
}