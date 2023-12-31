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
	sceneSchedule->schedule(CC_SCHEDULE_SELECTOR(TowerBase::fire), this, 0.5, false);
	/*gradeMark = Sprite::create("" + std::to_string(grade));*/
}
bool TowerBottle::doUpAction()
{
	auto parent = towerPanel->getParent();
	auto position = towerPanel->getPosition();
	towerPanel->removeFromParent();

	CC_SAFE_RELEASE_NULL(towerPanel);
	towerPanel = Sprite::create(TOWERBOTTLE + std::to_string(grade) + PHOTOPOSTFIX);
	towerPanel->setScale(1.5);
	towerPanel->setPosition(position);
	parent->addChild(towerPanel, TOWER_PANEL_LAYER);
	return true;
}
void TowerBottle::rotate()
{
	Vec2 direction = target->getVictim()->getPosition() - towerPanel->getPosition();
	float angle = CC_RADIANS_TO_DEGREES(atan2(direction.y, direction.x)+M_PI);
	towerPanel->setRotation3D(Vec3(0, 0, angle));
}
void TowerBottle::fireAction(Vec2 endPos)
{
	auto myBullet = new BottleBullet;
	myBullet->create(grade, BOTTLE_BULLET, target, towerPanel->getPosition());//����һ���ӵ�����ȡ�ӵ�ָ��
	/*if (!ref)
		throw "StarTowerAttackFalse";*/
	towerPanel->getParent()->addChild(myBullet->getBullet(), BULLET_LAYER);
	rotate();
	//myBullet->autorelease();//��ӵ��Զ��ͷų���
	myBullet->BottleBullet::attack(attack, false);//���ӵ����й���
}