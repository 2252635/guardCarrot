#include"TowerBottle.h"
#include"BottleBullet.h"
void TowerBottle::setParameter()
{
	grade = 1;//初始时设置防御塔等级为1
	price = BOTTLE_PRICE;//设置价格
	setDAttack(BOTTLE_DEFAULT_ATTACK);//设置默认的攻击力
	setDAttackRange(BOTTLE_DEFAULT_ATTACK_RANGE);//设置默认攻击范围
	setCanRotate(true);//将是否可旋转的状态设置为是

	setDUpCost(BOTTLE_DEFAULT_UP_COST);//设置默认升级时的花费步长
	setDAttack(BOTTLE_DEFAULT_DATTACK);//设置默认升级时增加的攻击力步长
	setDAttackRange(BOTTLE_DEFAULT_DATTACK_RANGE);//设置默认的升级时增加的攻击范围步长

	this->schedule(CC_SCHEDULE_SELECTOR((TowerBottle::chooseTarget), 0.1);
	this->schedule(CC_SCHEDULE_SELECTOR(TowerBottle::fire), 1);
	gradeMark = Sprite::create("" + std::to_string(grade));
}
bool TowerBottle::doUpAction()
{
	if (upGrade("瓶子塔名字"))
		return true;
	return false;
}
void TowerBottle::rotate()
{
	auto targetPos = target->getPosition();
	auto myPos = towerPanel->getPosition();//获取自己防御塔的位置

	auto direction = targetPos - myPos;
	float angleRadians = atan2(direction.y, direction.x)%M_PI/2;//计算弧度
	float angleDegree= CC_RADIANS_TO_DEGREES(angleRadians);//弧度转角度
	towerPanel->setRotation(-angleDegree);//进行旋转
}
void TowerBottle::fireAction()
{
	rotate();//旋转
	auto myBullet = new BottleBullet;
	auto ref=myBullet->create(grade,BOTTLE_BULLET,target,towerPanel->getPosition());//创建一个子弹并获取子弹指针
	if (!ref)
		throw "BottleTowerAttackFalse";
	myBullet->autorelease();//添加到自动释放池中
	myBullet->attack(attack,false);//让子弹进行攻击
}