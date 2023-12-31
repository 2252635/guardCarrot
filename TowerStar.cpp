#include"TowerStar.h"
#include"PublicSourceDefine.h"
void TowerStar::setParameter()
{
	grade = 1;//��ʼʱ���÷������ȼ�Ϊ1
	price = STAR_PRICE;//���ü۸�
	attackRange = STAR_DEFAULT_ATTACK_RANGE;
	attack = STAR_DEFAULT_ATTACK;

	setDAttack(STAR_DEFAULT_DATTACK);//����Ĭ�ϵĹ�����
	setDAttackRange(STAR_DEFAULT_DATTACK_RANGE);//����Ĭ�Ϲ�����Χ
	setCanRotate(false);//���Ƿ����ת��״̬����Ϊ��

	setDUpCost(STAR_DEFAULT_UP_COST);//����Ĭ������ʱ�Ļ��Ѳ���
	setDAttack(STAR_DEFAULT_DATTACK);//����Ĭ������ʱ���ӵĹ���������
	setDAttackRange(STAR_DEFAULT_DATTACK_RANGE);//����Ĭ�ϵ�����ʱ���ӵĹ�����Χ����

	
	auto sceneSchedule=  Director::getInstance()->getScheduler();
	sceneSchedule->schedule(CC_SCHEDULE_SELECTOR(TowerBase::chooseTarget), this, 0.1, false);
	sceneSchedule->schedule(CC_SCHEDULE_SELECTOR(TowerBase::fire), this, 0.5, false);
	/*gradeMark = Sprite::create("������ͼƬ" + std::to_string(grade));*/
}
bool TowerStar::doUpAction()
{
	auto parent=towerPanel->getParent();
	auto position = towerPanel->getPosition();
	towerPanel->removeFromParent();
	
	CC_SAFE_RELEASE_NULL(towerPanel);
	towerPanel = Sprite::create(TOWERSTAR + std::to_string(grade) + PHOTOPOSTFIX);
	towerPanel->setScale(1.5);
	towerPanel->setPosition(position);
	parent->addChild(towerPanel,TOWER_PANEL_LAYER);
	return true;
}
void TowerStar::fireAction(Vec2 endPos)
{
	auto myBullet = new StarBullet;
	myBullet->create(grade, STAR_BULLET, target, towerPanel->getPosition());//����һ���ӵ�����ȡ�ӵ�ָ��
	/*if (!ref)
		throw "StarTowerAttackFalse";*/
	towerPanel->getParent()->addChild(myBullet->getBullet(), BULLET_LAYER);
	//myBullet->autorelease();//��ӵ��Զ��ͷų���
	myBullet->StarBullet::attack(attack, false);//���ӵ����й���
}