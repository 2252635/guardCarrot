#include"TowerShit.h"
#include"ShitBullet.h"
#include"PublicSourceDefine.h"
void TowerShit::setParameter()
{
	grade = 1;//初始时设置防御塔等级为1
	price = SHIT_PRICE;//设置价格
	attackRange = SHIT_DEFAULT_ATTACK_RANGE;
	attack = SHIT_DEFAULT_ATTACK;

	setDAttack(SHIT_DEFAULT_ATTACK);//设置默认的攻击力
	setDAttackRange(SHIT_DEFAULT_ATTACK_RANGE);//设置默认攻击范围
	setCanRotate(true);//将是否可旋转的状态设置为是

	setDUpCost(SHIT_DEFAULT_UP_COST);//设置默认升级时的花费步长
	setDAttack(SHIT_DEFAULT_DATTACK);//设置默认升级时增加的攻击力步长
	setDAttackRange(SHIT_DEFAULT_DATTACK_RANGE);//设置默认的升级时增加的攻击范围步长

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
	//rotate();//旋转
	auto myBullet = new ShitBullet;
	auto ref=myBullet->create(grade, SHIT_BULLET, target, towerPanel->getPosition());//创建一个子弹并获取子弹指针

	auto targetPos = target->getVictim()->getPosition();
	auto myPos = towerPanel->getPosition();//获取自己防御塔的位置

	auto direction = targetPos - myPos;
	float angleRadians = atan2(direction.y, direction.x);//计算弧度
	while (angleRadians < -M_PI)
		angleRadians += 2 * M_PI;
	while (angleRadians > M_PI)
		angleRadians -= 2 * M_PI;
	float angleDegree = CC_RADIANS_TO_DEGREES(angleRadians);//弧度转角度
	ref->getBullet()->setRotation(angleDegree);

	towerPanel->addChild(myBullet->getBullet(), 1);
	/*if (!ref)
		throw "ShitTowerAttackFalse";*/
	//myBullet->autorelease();//添加到自动释放池中
	myBullet->ShitBullet::attack(attack, true);//让子弹进行攻击
	/*delete myBullet;*/
}