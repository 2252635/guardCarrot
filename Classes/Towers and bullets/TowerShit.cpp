#include"TowerShit.h"
#include"ShitBullet.h"
#include"PublicSourceDefine.h"
void TowerShit::setParameter()
{
	grade = 1;//��ʼʱ���÷������ȼ�Ϊ1
	price = SHIT_PRICE;//���ü۸�
	attackRange = SHIT_DEFAULT_ATTACK_RANGE;
	attack = SHIT_DEFAULT_ATTACK;

	setDAttack(SHIT_DEFAULT_ATTACK);//����Ĭ�ϵĹ�����
	setDAttackRange(SHIT_DEFAULT_ATTACK_RANGE);//����Ĭ�Ϲ�����Χ
	setCanRotate(true);//���Ƿ����ת��״̬����Ϊ��

	setDUpCost(SHIT_DEFAULT_UP_COST);//����Ĭ������ʱ�Ļ��Ѳ���
	setDAttack(SHIT_DEFAULT_DATTACK);//����Ĭ������ʱ���ӵĹ���������
	setDAttackRange(SHIT_DEFAULT_DATTACK_RANGE);//����Ĭ�ϵ�����ʱ���ӵĹ�����Χ����

	auto sceneSchedule = Director::getInstance()->getScheduler();
	sceneSchedule->schedule(CC_SCHEDULE_SELECTOR(TowerBase::chooseTarget), this, 0.1, false);
	sceneSchedule->schedule(CC_SCHEDULE_SELECTOR(TowerBase::fire), this, 1, false);
}
bool TowerShit::doUpAction()
{
	CC_SAFE_RELEASE_NULL(towerPanel);
	towerPanel = Sprite::create(TOWERSHIT + std::to_string(grade) + PHOTOPOSTFIX);
	addChild(towerPanel);
	return true;
}
void TowerShit::fireAction(Vec2 endPos)
{
	//rotate();//��ת
	auto myBullet = new ShitBullet;
	auto ref=myBullet->create(grade, SHIT_BULLET, target, towerPanel->getPosition());//����һ���ӵ�����ȡ�ӵ�ָ��

	auto targetPos = target->getVictim()->getPosition();
	auto myPos = towerPanel->getPosition();//��ȡ�Լ���������λ��

	auto direction = targetPos - myPos;
	float angleRadians = atan2(direction.y, direction.x);//���㻡��
	while (angleRadians < -M_PI)
		angleRadians += 2 * M_PI;
	while (angleRadians > M_PI)
		angleRadians -= 2 * M_PI;
	float angleDegree = CC_RADIANS_TO_DEGREES(angleRadians);//����ת�Ƕ�
	ref->getBullet()->setRotation(angleDegree);

	towerPanel->addChild(myBullet->getBullet(), 1);
	/*if (!ref)
		throw "ShitTowerAttackFalse";*/
	//myBullet->autorelease();//��ӵ��Զ��ͷų���
	myBullet->ShitBullet::attack(attack, true);//���ӵ����й���
	/*delete myBullet;*/
}