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
	sceneSchedule->schedule(CC_SCHEDULE_SELECTOR(TowerBase::fire), this, 0.5, false);
}
bool TowerShit::doUpAction()
{
	auto parent = towerPanel->getParent();
	auto position = towerPanel->getPosition();
	towerPanel->removeFromParent();

	CC_SAFE_RELEASE_NULL(towerPanel);
	towerPanel = Sprite::create(TOWERSHIT + std::to_string(grade) + PHOTOPOSTFIX);
	towerPanel->setScale(1.5);
	towerPanel->setPosition(position);
	parent->addChild(towerPanel, TOWER_PANEL_LAYER);
	return true;
}
void TowerShit::fireAction(Vec2 endPos)
{
	auto myBullet = new ShitBullet;
	myBullet->create(grade, SHIT_BULLET, target, towerPanel->getPosition());//����һ���ӵ�����ȡ�ӵ�ָ��
	/*if (!ref)
		throw "StarTowerAttackFalse";*/
	towerPanel->getParent()->addChild(myBullet->getBullet(), BULLET_LAYER);
	//myBullet->autorelease();//��ӵ��Զ��ͷų���
	myBullet->ShitBullet::attack(attack, true);//���ӵ����й���
	/*delete myBullet;*/
}