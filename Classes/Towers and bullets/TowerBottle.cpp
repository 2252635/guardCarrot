#include"TowerBottle.h"
#include"BottleBullet.h"
#include"PublicSourceDefine.h"
void TowerBottle::setParameter()
{
	grade = 1;//初始时设置防御塔等级为1
	price = BOTTLE_PRICE;//设置价格
	attackRange = BOTTLE_DEFAULT_ATTACK_RANGE;
	attack = BOTTLE_DEFAULT_ATTACK;

	setDAttack(BOTTLE_DEFAULT_ATTACK);//设置默认的攻击力
	setDAttackRange(BOTTLE_DEFAULT_ATTACK_RANGE);//设置默认攻击范围
	setCanRotate(true);//将是否可旋转的状态设置为是

	setDUpCost(BOTTLE_DEFAULT_UP_COST);//设置默认升级时的花费步长
	setDAttack(BOTTLE_DEFAULT_DATTACK);//设置默认升级时增加的攻击力步长
	setDAttackRange(BOTTLE_DEFAULT_DATTACK_RANGE);//设置默认的升级时增加的攻击范围步长

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
	auto myPos = towerPanel->getPosition();//获取自己防御塔的位置

	auto direction = targetPos - myPos;
	float angleRadians = atan2(direction.y, direction.x);//计算弧度
	while (angleRadians < -M_PI)
		angleRadians += 2 * M_PI;
	while (angleRadians > M_PI)
		angleRadians -= 2 * M_PI;
	float angleDegree= CC_RADIANS_TO_DEGREES(angleRadians);//弧度转角度
	auto rotateAction = RotateBy::create(0.5f, angleDegree);

	towerPanel->runAction(rotateAction);//进行旋转
}
void TowerBottle::fireAction(Vec2 endPos)
{
	auto myBullet = new BottleBullet;
	myBullet->create(grade,BOTTLE_BULLET,target,towerPanel->getPosition());//创建一个子弹并获取子弹指针
	towerPanel->addChild(myBullet->getBullet(),1);
	//this->getParent()->addChild(myBullet->getBullet(), 1);
	 // 计算子弹的相对位置
	/*Vec2 relativePos = endPos - towerPanel->getPosition();
	myBullet->getBullet()->setRelativePosition(relativePos);*/
	rotate();//旋转
	/*if (!ref)
		throw "BottleTowerAttackFalse";*/
	//myBullet->autorelease();//添加到自动释放池中
	myBullet->BottleBullet::attack(attack,false);//让子弹进行攻击
	/*towerPanel->removeAllChildren();*/
}