#include"TowerBottle.h"
#include"BottleBullet.h"
#include"PublicSourceDefine.h"
void TowerBottle::setParameter()
{
	grade = 1;//��ʼʱ���÷������ȼ�Ϊ1
	price = BOTTLE_PRICE;//���ü۸�
	attackRange = BOTTLE_DEFAULT_ATTACK_RANGE;
	attack = BOTTLE_DEFAULT_ATTACK;

	setDAttack(BOTTLE_DEFAULT_ATTACK);//����Ĭ�ϵĹ�����
	setDAttackRange(BOTTLE_DEFAULT_ATTACK_RANGE);//����Ĭ�Ϲ�����Χ
	setCanRotate(true);//���Ƿ����ת��״̬����Ϊ��

	setDUpCost(BOTTLE_DEFAULT_UP_COST);//����Ĭ������ʱ�Ļ��Ѳ���
	setDAttack(BOTTLE_DEFAULT_DATTACK);//����Ĭ������ʱ���ӵĹ���������
	setDAttackRange(BOTTLE_DEFAULT_DATTACK_RANGE);//����Ĭ�ϵ�����ʱ���ӵĹ�����Χ����

	auto sceneSchedule = Director::getInstance()->getScheduler();
	sceneSchedule->schedule(CC_SCHEDULE_SELECTOR(TowerBase::chooseTarget), this, 0.1, false);
	sceneSchedule->schedule(CC_SCHEDULE_SELECTOR(TowerBase::fire), this, 1, false);
	/*gradeMark = Sprite::create("" + std::to_string(grade));*/
}
bool TowerBottle::doUpAction()
{
	CC_SAFE_RELEASE_NULL(towerPanel);
	towerPanel = Sprite::create(TOWERBOTTLE + std::to_string(grade) + PHOTOPOSTFIX);
	addChild(towerPanel);
	return true;
}
void TowerBottle::rotate()
{
	auto targetPos = target->getVictim()->getPosition();
	auto myPos = towerPanel->getPosition();//��ȡ�Լ���������λ��

	auto direction = targetPos - myPos;
	float angleRadians = atan2(direction.y, direction.x);//���㻡��
	while (angleRadians < -M_PI)
		angleRadians += 2 * M_PI;
	while (angleRadians > M_PI)
		angleRadians -= 2 * M_PI;
	float angleDegree= CC_RADIANS_TO_DEGREES(angleRadians);//����ת�Ƕ�
	auto rotateAction = RotateBy::create(0.5f, angleDegree);

	towerPanel->runAction(rotateAction);//������ת
}
void TowerBottle::fireAction(Vec2 endPos)
{
	auto myBullet = new BottleBullet;
	myBullet->create(grade,BOTTLE_BULLET,target,towerPanel->getPosition());//����һ���ӵ�����ȡ�ӵ�ָ��
	towerPanel->addChild(myBullet->getBullet(),1);
	//this->getParent()->addChild(myBullet->getBullet(), 1);
	 // �����ӵ������λ��
	/*Vec2 relativePos = endPos - towerPanel->getPosition();
	myBullet->getBullet()->setRelativePosition(relativePos);*/
	rotate();//��ת
	/*if (!ref)
		throw "BottleTowerAttackFalse";*/
	//myBullet->autorelease();//��ӵ��Զ��ͷų���
	myBullet->BottleBullet::attack(attack,false);//���ӵ����й���
	/*towerPanel->removeAllChildren();*/
}