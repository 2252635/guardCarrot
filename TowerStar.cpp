#include"TowerStar.h"
void TowerStar::setParameter()
{
	grade = 1;//初始时设置防御塔等级为1
	price = STAR_PRICE;//设置价格
	setDAttack(STAR_DEFAULT_ATTACK);//设置默认的攻击力
	setDAttackRange(STAR_DEFAULT_ATTACK_RANGE);//设置默认攻击范围
	setCanRotate(false);//将是否可旋转的状态设置为否

	setDUpCost(STAR_DEFAULT_UP_COST);//设置默认升级时的花费步长
	setDAttack(STAR_DEFAULT_DATTACK);//设置默认升级时增加的攻击力步长
	setDAttackRange(STAR_DEFAULT_DATTACK_RANGE);//设置默认的升级时增加的攻击范围步长

	this->schedule(CC_SCHEDULE_SELECTOR(TowerStar::chooseTarget), 0.1);
	this->schedule(CC_SCHEDULE_SELECTOR(TowerStar::fire), 1);
	gradeMark = Sprite::create("星星塔图片" + std::to_string(grade));
}

void TowerStar::fireAction()
{
	auto myBullet = new StarBullet;
	auto ref = myBullet->create(grade, STAR_BULLET, target, towerPanel->getPosition());//创建一个子弹并获取子弹指针
	if (!ref)
		throw "StarTowerAttackFalse";
	myBullet->autorelease();//添加到自动释放池中
	myBullet->attack(attack, false);//让子弹进行攻击
}